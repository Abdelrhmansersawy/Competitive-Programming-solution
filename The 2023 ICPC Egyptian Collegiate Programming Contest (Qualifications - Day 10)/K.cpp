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
const int N = 2e5 + 9, mod = 1e9 + 7;
vector<int> dis[N];
ll sum[N];
void add(ll &a , ll b){
    a += b;
    if(a >= mod) a -= mod; 
}
void sub(ll &a , ll b){
    a -= b;
    if(a < 0) a += mod;
}
void init(){
    for(int i = 1; i < N; ++i){
        for(int j = 2 * i; j < N; j += i){
            dis[j].emplace_back(i);
        }
    }
}
template<class T = int>
struct BIT{
    vector<T> tree;
    int n;
    void init(int n){
        this->n = n;
        tree.assign(n , 0);
    }
    void add(int pos , T val){
        for(pos++; pos <= n ; pos += (pos & (-pos))){
            tree[pos - 1] = (tree[pos - 1] + val + mod) % mod;
        }
    }
    T sum(int pos){
        T ret = 0;
        for(pos++; pos ; pos -= (pos & (-pos))){
            ret = (ret + tree[pos - 1] + mod) % mod;

        }
        return ret;
    }
    T qry(int l , int r){ return (sum(r) - sum(l - 1) + mod) % mod; }
    T qry(int i){ return qry(i , i); }
};
int main(){
    ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
    #endif
    init();
    BIT<ll> B; B.init(N);
    int q; cin >> q;
    while(q--){
        int n; cin >> n;
        int a[n + 1];
        for(int i = 1; i <= n; ++i) cin >> a[i];
        ll res = 0;
        ll dp[n + 1]{};
        for(int i = 1; i <= n; ++i){
            dp[i] = 1;
            add( dp[i] , B.qry(0 , a[i] - 1) );
            for(auto &j : dis[i]){
                if(a[j] < a[i]) sub(dp[i] , dp[j]);
            }
            B.add(a[i] , dp[i]);
            add(res , dp[i]);
        }

        for(int i = 1; i <= n; ++i) B.add(a[i] , -B.qry(a[i]) );
        cout << res << '\n';
    }
}