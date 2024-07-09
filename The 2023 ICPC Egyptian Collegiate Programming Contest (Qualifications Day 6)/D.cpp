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
    int n; cin >> n;
    int a[n];
    for(int i = 0; i < n; ++i) cin >> a[i];
    vector<int> dp(1 << 10);
    for(int i = 0; i < (1 << 10); ++i) dp[i] = __builtin_popcount(a[0] ^ i);
    for(int i = 1; i < (1 << 10); ++i) dp[i] = min(dp[i] , dp[i - 1]);

    for(int i = 1; i < n; ++i){
    	vector<int> new_dp(1 << 10 , INT32_MAX);
    	for(int j = 0; j < (1 << 10); ++j){
    		new_dp[j] = min(new_dp[j] , dp[j] + __builtin_popcount(a[i] ^ j));
    	}
    	swap(dp , new_dp);
    	for(int i = 1; i < (1 << 10); ++i) dp[i] = min(dp[i] , dp[i - 1]);
    }
	cout << dp[(1 << 10) - 1];
}