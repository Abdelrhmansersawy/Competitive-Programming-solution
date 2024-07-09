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
int nCr(int n, int k) {
    // nCr mod 2
    while (n > 0 || k > 0) {
        if ((k & 1) > (n & 1)) {
            return 0;
        }
        n >>= 1;
        k >>= 1;
    }
    return 1;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
    #endif
    int n , k; cin >> n >> k;
    ll ans = 0;
    int sum[k + 1]{};
    sum[0] = nCr(k , 0);
    for(int i = 1; i <= k; ++i){
        sum[i] = (sum[i - 1] + nCr(k , i)) % 2; 
    }
    for(int i = 0; i < n; ++i){
        int x; cin >> x;
        int lo = max(k - n + i + 1 , 0);
        int hi = min(i , k);
        assert(lo <= hi);
        int cnt = sum[hi];
        if(lo) cnt = ( cnt - sum[lo - 1] + 2) % 2;
        if(cnt){
            ans ^= x;
        }
    }
    cout << ans;
}