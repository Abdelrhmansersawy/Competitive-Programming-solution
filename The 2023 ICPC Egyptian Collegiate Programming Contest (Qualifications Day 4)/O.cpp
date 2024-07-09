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
    int n; cin >> n;
    int a[n + 2]{};
    for(int i = 1; i <= n; ++i) cin >> a[i];
    int pref[n + 2]{} , suff[n + 2]{};
	for(int i = 1; i <= n; ++i){
		pref[i] = __gcd(pref[i - 1] , a[i]);
	}
	for(int i = n; i >= 1; --i){
		suff[i] = __gcd(suff[i + 1] , a[i]);
	}
	int q; cin >> q;
	while(q--){
		int i; cin >> i;
		cout << __gcd(pref[i - 1] , suff[i + 1]) << '\n';
	}
}