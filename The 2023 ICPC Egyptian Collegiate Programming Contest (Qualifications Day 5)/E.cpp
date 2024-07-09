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
const int N = 2e5 + 9;
const int mod[] = { (int)1e9 + 7, 998244353 };
int o;  // Which mod wher I current use.
mt19937 random_seed(time(0));
int rnd(int l , int r){
    uniform_int_distribution<int> dist(l, r);
    return dist(random_seed);
}
ll bpw(ll a , ll b ){
    a %= mod[o];
    ll res = 1;
    while(b){
        if(b % 2) res = (res * a) % mod[o];
        a = (a * a) % mod[o];
        b >>= 1;
    }
    return res;
}

struct Mint{
    ll x;
    Mint(ll x = 0){  this->x = x % mod[o]; }
    Mint operator +(const Mint &other) const{ return (x + other.x) % mod[o]; }
    Mint operator -(const Mint &other) const{ return (x - other.x + mod[o]) % mod[o]; }
    Mint operator *(const Mint &other) const{ return (x * other.x) % mod[o]; }
    Mint operator /(const Mint &other) const{ return ( x * bpw(other.x , mod[o] - 2) ) % mod[o]; }
    bool operator ==(const Mint &other) const{ return x == other.x; }
    bool operator !=(const Mint &other) const{ return x != other.x; }
};

Mint p[2] , pw[2][N];
void init(){
    for(o = 0; o < 2; o++){
        p[o] = Mint( rnd(31 , 39) );
        pw[o][0] = Mint(1);
        for(int i = 1; i < N; ++i){
            pw[o][i] = pw[o][i - 1] * p[o];
        }
    }
}

struct Hash{
    Mint pref[2] , suff[2];
    int len;
    Hash(char ch = '?'){
        if(ch == '?'){
            pref[0] = pref[1] = suff[0] = suff[1] = Mint(0);
            len = 0;
            return;
        }
        len = 1;
        for(o = 0;o < 2; ++o){
            pref[o] = suff[o] = Mint(ch - 'a' + 1);
        }
    }
    Hash operator +(const Hash &other) const{
        Hash res;
        res.len = len + other.len;
        for(o = 0;o < 2; ++o){
            res.pref[o] = pref[o] + other.pref[o] * pw[o][len]; 
            res.suff[o] = other.suff[o] + suff[o] * pw[o][other.len]; 
        }
        return res;
    }
    void rev(){
        for(o = 0; o < 2; ++o) swap(pref[o] , suff[o]);
    }
    bool is_palindrome() const{
        for(o = 0; o < 2; ++o){
            if(pref[o] != suff[o]) return false;
        }
        return true;
    }
};

const int LOG = 20;
vector<int> adj[N];
char c[N];
Hash s[N];
int up[N][LOG] , dep[N];
void dfs(int u = 0, int p = -1){
    if(p == -1){
        s[u] = Hash{c[u]};
        up[u][0] = N - 1;
    }else{
        up[u][0] = p;
    }

    for(int x = 1; x < LOG; ++x) up[u][x] = up[ up[u][x-1] ][x - 1];
    
    for(auto &v : adj[u]) if(v != p){
        s[v] = s[u] + Hash{c[v]};

        dep[v] = dep[u] + 1;
        
        dfs(v , u);
    } 
}
int LCA(int u , int v){
    if(dep[u] < dep[v]) swap(u , v);
    int k = dep[u] - dep[v];
    for(int x = 0; x < LOG; ++x) if((k >> x) & 1) u = up[u][x];
    if(u == v) return u;
    for(int x = LOG - 1; x >= 0; --x) if( up[u][x] != up[v][x] ){
        u = up[u][x];
        v = up[v][x];
    }
    assert(up[u][0] == up[v][0]);
    return up[u][0];
}

Hash excludePrefix(Hash s1 , Hash s2){
    Hash res;
    res.len = s1.len - s2.len;
    for(o = 0; o < 2; ++o){
        res.pref[o] = s1.pref[o] - s2.pref[o];
        res.pref[o] = res.pref[o] / pw[o][s2.len];

        res.suff[o] = s1.suff[o] - s2.suff[o] * pw[o][s1.len - s2.len];
    }
    return res;
}

bool solve(int u , int v){
    if(dep[u] < dep[v]) swap(u , v);
    int lca = LCA(u , v);
    if(v == lca){
        Hash cur = excludePrefix(s[u] , s[ up[v][0] ]);
        return cur.is_palindrome();
    }
    Hash s1 = excludePrefix(s[u] , s[lca]);
    Hash s2 = excludePrefix(s[v] , s[lca]);
    s1.rev();
    Hash cur = s1 + Hash(c[lca]) + s2;

    return cur.is_palindrome();
}
int main(){
    ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
    #endif
    init();

    int n; cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> c[i];
    }
    for(int i = 1; i < n; ++i){
        int u , v; cin >> u >> v;
        --u; --v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }
    dfs();


    int q; cin >> q;
    while(q--){
        int u , v; cin >> u >> v;
        --u; --v;
        cout << solve(u , v) << '\n';
    }
}