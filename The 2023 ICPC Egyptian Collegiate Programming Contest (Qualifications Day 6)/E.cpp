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
    int n , k; cin >> n >> k;
    int pref[n + 2]{};
    for(int i = 0; i < n; ++i){
    	int l , r; cin >> l >> r;
    	pref[l]++; pref[r + 1]--;
    }
    for(int i = 1; i <= n; ++i) pref[i] += pref[i - 1];
   	int cnt = 0 , mx = 0;
   	for(int i = 1; i <= n; ++i){
   		if(pref[i]) cnt = 0;
   		else ++cnt;
   		mx = max(mx , cnt);
   	}
   	cout << mx;
}