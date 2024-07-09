#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i , st , ed) for(int i = st; i < ed; i++)
#define f first
#define s second
#define all(x) x.begin(),x.end()
const int N = 1e3;
const int M = 1e5 + 100;
const int mod = 1e9 + 7;
const int m = 1 << 12;
ll fact[M], inv[M] , invfact[M];

int mask[N + 1] , badPrime[N + 1];
vector<int> prime;
vector<int> primeFac[N + 1];
void init(){
    for(int i = 2; i <= N; ++i){
        // prime factorization of i
        int n = i;
        for(int k = 2; k * k <= n; ++k){
            int cnt = 0;
            while(n % k == 0) n /= k , cnt ^= 1;
            if(cnt) primeFac[i].emplace_back(k);
        }
        if(n > 1) primeFac[i].emplace_back(n);

        for(auto &p : primeFac[i]){
            if(p * p <= N) prime.emplace_back(p);
        }
    }

    // coordinate compression
    sort(all(prime));
    prime.erase( unique(all(prime)) , prime.end() );
    // Mask for each i
    for(int i = 2; i <= N; ++i){
        for(auto &p : primeFac[i]){
            if(p * p > N){
                assert(badPrime[i] == 0);
                badPrime[i] = p;
            }
            else{
                int j = lower_bound(all(prime) , p) - prime.begin();
                assert(j < prime.size() && prime[j] == p);
                mask[i] |= (1 << j);
            }
            
        }
    }  
}
void initNcR(){
    fact[0] = inv[1] = fact[1] = invfact[0] = invfact[1] = 1;
    for (long long i = 2; i < M; i++) {
        fact[i] = (fact[i - 1] * i) % mod;
        inv[i] = mod - (inv[mod % i] * (mod / i) % mod);
        invfact[i] = (inv[i] * invfact[i - 1]) % mod;
    }
}
ll nCr(int n, int r) {
    if(r > n || n < 0 || r < 0) return 0; // manual handling
    return (((fact[n] * invfact[r]) % mod) * invfact[n - r]) %
           mod;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
    #endif 
    init();
    initNcR();

    int n; cin >> n;
    map<int,int> frq;
    map<int, vector< array<ll,3> >> group;
    for(int i = 0; i < n; ++i){
        int x; cin >> x;
        frq[x]++;
    }
    
    vector<ll> dp(m , 0);
    dp[0] = 1;
    for(auto &[x , f] : frq){
        vector<ll> c(2);
        for(int i = 0; i <= f; ++i){
            c[i % 2] += nCr(f , i);
            c[i % 2] %= mod;
        }
        if(badPrime[x]){
            group[ badPrime[x] ].push_back( { mask[x] | (1 << 11) , c[0] , c[1] } );
        }else{
            vector<ll> new_dp(m , 0);
            for(int msk = 0; msk < m; msk++){
                new_dp[msk] += c[0] * dp[msk];
                new_dp[msk] %= mod;

                int nmsk = msk ^ mask[x];
                new_dp[nmsk] += c[1] * dp[msk];
                new_dp[nmsk] %= mod;
            }
            swap(dp , new_dp);
        }
    }
    for(auto &[x , v] : group){
        for(auto &[cmsk , c0 , c1] : v){
            vector<ll> new_dp(m , 0);
            for(int msk = 0; msk < m; msk++){
                new_dp[msk] += c0 * dp[msk];
                new_dp[msk] %= mod;

                int nmsk = msk ^ cmsk;
                new_dp[nmsk] += c1 * dp[msk];
                new_dp[nmsk] %= mod;
            }
            swap(dp , new_dp);
        }
        for(int i = (1 << 11); i < m; ++i) dp[i] = 0;
    }
    ll res = (dp[0] - 1 + mod) % mod;
    cout << res;
}