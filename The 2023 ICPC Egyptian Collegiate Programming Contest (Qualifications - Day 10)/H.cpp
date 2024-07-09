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
const int mod = 1e9 + 7;
ll bpw(ll a , ll b){
    ll res = 1;
    while(b){
        if(b % 2) res = (res * a) % mod;
        b /= 2;
        a = (a * a) % mod;
    }
    return res;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
    #endif
    cerr << '\n';
    int q; cin >> q;
    while(q--){
        ll n; cin >> n;
        ll ans = 8;
        for(int d = 2; d < 10; ++d){
            ll dp[10]{};
            for(int g = 9; g >= 2; --g) if(__gcd(g , d) > 1){
                int c = 9 / g + 1;   
                ll m = n - 1;
                dp[g] = c * ( (bpw(c , m) - 1 + mod) % mod ) % mod * bpw(c - 1 , mod - 2) % mod;
                for(int i = 2 * g; i < 10; i += g){
                    dp[g] = (dp[g] - dp[i] + mod) % mod; 
                }
                ans = (ans + dp[g]) % mod;
            }
        }
        cout << ans << '\n';
    }
}