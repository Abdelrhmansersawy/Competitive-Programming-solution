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
int main(){
    ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
    #endif
 	int q; cin >> q;
 	while(q--){
 		int n , w; cin >> n >> w;
 		ll pref[n + 1]{};
 		for(int i = 1; i <= n; ++i){
 			cin >> pref[i];
 			pref[i] += pref[i - 1];
 		}
 		ll ans = 0;
 		for(int i = 1; i <= n; ++i){
 			int j = upper_bound(pref  , pref + n + 1, pref[i - 1] + w) - pref - 1;
 			ans = max(ans , pref[j] - pref[i - 1]);
 		}
 		cout << ans << '\n';
 	}   
}