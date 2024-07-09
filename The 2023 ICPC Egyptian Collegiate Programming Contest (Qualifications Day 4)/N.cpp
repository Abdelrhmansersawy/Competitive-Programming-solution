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
    int n , T , k; cin >> n >> T >> k;
    int t[n] , v[n] , w[n];
    for(int i = 0; i < n; ++i) cin >> t[i];
    for(int i = 0; i < n; ++i) cin >> v[i];
    for(int i = 0; i < n; ++i) cin >> w[i];
    int idx[n];
	iota(idx , idx + n , 0);
	sort(idx , idx + n , [&](int x , int y){
		if(w[x] == w[y]) return v[x] > w[y];
		return w[x] < w[y];
	});
	sort(t , t + n,  greater<int>());
	int i = 0;
	multiset<int, greater<int>> s;
	ll ans = 0;
	for(auto &x : t){
		while(i < n && x + w[idx[i]] / k <= T - x){
			s.emplace(v[idx[i]]);
			++i;
		}
		if(s.size()){
			ans += *s.begin();
			s.erase(s.begin());
		}
	}
	cout << ans;
}