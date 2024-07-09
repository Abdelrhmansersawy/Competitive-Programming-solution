#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i , st , ed) for(int i = st; i < ed; i++)
#define f first
#define s second
const int N = 51;
ll dp[N][1 << 15] , S[N];
bool isComposite[N];
int msk[N];
void init(){
	int cnt = 0;
	for(int i = 2; i < N; ++i) if(not isComposite[i]){
		for(int j = i; j < N; j += i){
			isComposite[j] = 1;
			msk[j] |= (1 << cnt);
		}
		++cnt;
	}
	for(int i = 1; i < N; ++i) dp[i][ msk[i] ] = 1;
	
	int Max = (1 << cnt) - 1;
	for(int s = 1; s < N; ++s){
		for(int i = 1; i < N - s; ++i){
			int m = Max ^ msk[i];
			for (int smsk = m; ; smsk = (smsk-1) & m){
				dp[s + i][msk[i] | smsk] += dp[s][smsk];
				if(smsk == 0) break;
			}
		}
	}
	for(int i = 1; i < N; ++i){
		for(int j = 0; j < (1 << cnt); ++j){
			S[i] += dp[i][j];
		}
		S[i] += S[i - 1];
	}
}
int main(){
    ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
    #endif
    init(); 
    int q; cin >> q;
    while(q--){
    	int l , r; cin >> l >> r;
    	cout << S[r] - S[l - 1] << '\n';
    }
}