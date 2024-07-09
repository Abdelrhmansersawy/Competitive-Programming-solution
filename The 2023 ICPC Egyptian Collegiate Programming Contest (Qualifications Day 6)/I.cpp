#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i , st , ed) for(int i = st; i < ed; i++)
#define f first
#define s second
#define all(x) x.begin() , x.end()
const int N = 1e5 + 9;
int BLOCK_SIZE = 460;
int n , q, a[N];
int frq[2 * N] , isComposite[N];
int cur;
vector<ll> primes;
void init(){
    vector<int> all;
    for(ll i = 2; i * i <= 1e9; ++i) if(isComposite[i] == 0){
        primes.emplace_back(i);
        for(int j = 2 * i; j < N; j += i){
            isComposite[j] = 1;
        }
    }
    for(int i = 0; i < n; ++i){
        for(auto &p : primes){
            while(a[i] % (p * p) == 0){
                a[i] /= (p * p);
            }
        }
        all.emplace_back(a[i]);
    }
    sort( all(all) );
    all.erase( unique(all(all)) , all.end() );
    // data compression
    for(int i = 0; i < n; ++i){
        a[i] = lower_bound(all(all) , a[i]) - all.begin();
    }
}

int ans[N];
void add(int idx){ 
    cur += frq[a[idx]];
    frq[a[idx]]++;
}
void remove(int idx){  
    --frq[ a[idx] ];
    cur -= frq[ a[idx] ];
}
struct Query{
    int l , r , id;
    bool operator <(const Query &other) const{
        int n1 = l / BLOCK_SIZE , n2 = other.l / BLOCK_SIZE;
        if(n1 != n2) return n1 < n2;
        return n1 % 2 ? r > other.r : r < other.r;
    }
};
void Mo(vector<Query> &query){
    sort(all(query));
    int mo_l = 0 , mo_r = -1;
    for(auto &q : query){
        while(mo_l > q.l) add(--mo_l);
        while(mo_r < q.r) add(++mo_r);
        while(mo_l < q.l) remove(mo_l++);
        while(mo_r > q.r) remove(mo_r--);
        // calculate answer of Query
        ans[q.id] = cur;
    }
}
int main(){
    ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
    #endif 
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
        freopen("error.txt", "w", stderr);
    #endif 
    cin >> n >> q;
    BLOCK_SIZE = sqrt(n) + 9;
    vector<Query> query(q);
    for(int i = 0; i < n; ++i) cin >> a[i];
    
    for(int i = 0; i < q; ++i){
        int l , r; cin >> l >> r;
        --l; --r;
        query[i] = {l , r , i};
    }

    init();
    Mo(query);
    for(int i = 0; i < q; ++i){
        cout << ans[i] << '\n';
    }
}