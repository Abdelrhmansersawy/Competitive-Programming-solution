#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i , st , ed) for(int i = st; i < ed; i++)
#define f first
#define s second
vector<int> prime, lpf;
void Sieve(int n) {
    prime.clear();
    lpf.assign(n + 1, 0);

    lpf[1] = 1;
    for (int i = 2; i <= n; i++) {
        if (lpf[i] == 0) {
            lpf[i] = i;
            prime.push_back(i);
        }
        for (int j = 0; j < (int) prime.size() && i * prime[j] <= n; j++) {
            lpf[i * prime[j]] = prime[j];
            if (prime[j] == lpf[i]) break;
        }
    }
}
const int mod = 1e9 + 7;
int main(){
    ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
    #endif 
    Sieve( 1e7 + 1);
    int n , m; cin >> n >> m;
    int lt = 0 , cnt = 0;
	ll ans = 1;
    for(int i = 0; i < n; ++i){
    	int x; cin >> x;
    	auto it = lower_bound(prime.begin() , prime.end() , x);
    	if(it != prime.end() && *it == x){
    		++cnt;
			if(cnt > m){ 
				ans *= (i - lt);
				ans %= mod;
				cnt = 1;
			}
			lt = i;
    	}
    }  
	cout << (cnt == m ? ans : 0);
}
