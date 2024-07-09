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
    int n , w; cin >> n >> w;
    int c[n];
    for(int i = 0; i < n; ++i) cin >> c[i];
    int dp[w + 1][3];
	memset(dp , 0 , sizeof dp);
	dp[0][0] = 1;
	for(auto &x : c){
		for(int i = w; i >= x; --i){
			for(int j = 2; j >= (x % 2 == 0); --j){
				dp[i][j] |= dp[i - x][j - (x % 2 == 0)];
			}
		}
	}
	cout << (dp[w][1] ? "YES" : "NO");
}