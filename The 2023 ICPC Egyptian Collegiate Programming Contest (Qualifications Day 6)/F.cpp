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
    while(q--){
    	int n; cin >> n;
    	string s; cin >> s;
    	vector<int> frq(26);
    	ll ans = 0;
    	for(int i = n - 1; i > 0; --i){
    		ans += 1 + frq[s[i] - 'a'];
    		frq[s[i] - 'a']++;
    	}
    	cout << ans << '\n';
    }
}