#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i , st , ed) for(int i = st; i < ed; i++)
#define f first
#define s second
int main(){
    ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
    #endif 
    int q; cin >> q;
    ll ans = LLONG_MAX;
    for(int i = 0; i < q; ++i){
        ll n , x , y , z; cin >> n >> x >> y >> z;
        ll cur = (n + 1) / 2  * x + (1 + (n - 1) / 3 ) * y + z * n;
        ans = min(ans , cur);
    }
    cout << ans;
}