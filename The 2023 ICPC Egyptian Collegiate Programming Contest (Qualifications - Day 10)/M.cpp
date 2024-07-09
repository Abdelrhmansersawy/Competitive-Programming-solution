#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i , st , ed) for(int i = st; i < ed; i++)
#define f first
#define s second
#define all(v) v.begin() , v.end()
#ifndef ONLINE_JUDGE 
#define debug(x) cerr << #x << ": " << x << '\n';
#else
#define debug(x)
#endif
const int N = 2e6 + 9;
vector<int> adj[N];
int n , c[N], isComposite[N];
ll ans[N];
vector<pair<int,int>> query[N];
template<class T = int>
struct BIT{
    vector<T> tree;
    int n;
    void init(int n){
        this->n = n;
        tree.assign(n , 0);
    }
    void add(int pos , T val){
        for(pos++; pos <= n ; pos += (pos & (-pos)))
            tree[pos - 1] += val;
    }
    T sum(int pos){
        T ret = 0;
        for(pos++; pos ; pos -= (pos & (-pos)))
            ret += tree[pos - 1];
        return ret;
    }
    T qry(int l , int r){ return (l > r) ? 0 : sum(r) - sum(l - 1); }
    T qry(int i){ return sum(i , i); }
};
BIT<ll> B;
void dfs(int u = 0, int p = 0, int dep = 0){
    for(auto &[d , i] : query[u]){
        ans[i] = -B.qry(dep + d , n);
    }
    B.add(dep , c[u]);
    for(auto &v : adj[u]) if(v != p) dfs(v , u , dep + 1);
    for(auto &[d , i] : query[u]){
        ans[i] += B.qry(dep + d , n);
    }
}
int main(){
    ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
        freopen("error.txt", "w", stderr);
    #endif 
    isComposite[0] = isComposite[1] = 1;
    for(int i = 2; i < N; ++i) if( !isComposite[i] ){
        for(int j = 2 * i; j < N; j += i){
            isComposite[j] = 1;
        }
    }
    B.init(N);
    
    int q; cin >> q;
    while(q--){
        cin >> n;
        for(int i = 0; i < n; ++i){
            cin >> c[i];
            if(isComposite[c[i]]) c[i] = 0;
        }
        for(int i = 0; i < n; ++i){
            adj[i].clear();
            query[i].clear();
        }
        for(int i = 1; i < n; ++i){
            int p; cin >> p;
            --p;
            adj[p].emplace_back(i);
            adj[i].emplace_back(p);
        }

        int q; cin >> q;
        for(int i = 0; i < q; ++i) ans[i] = 0;
        for(int i = 0; i < q; ++i){
            int u , d; cin >> u >> d;
            --u;
            query[u].emplace_back(d , i);
        }
        dfs();
        for(int i = 0; i < q; ++i) cout << ans[i] << ' ';
        cout << '\n';
    }
}