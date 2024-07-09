#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i , st , ed) for(int i = st; i < ed; i++)
#define f first
#define s second
const int N = 1e6 + 9;
const int mod = 1e9 + 7;
ll fac[N] , sumInv[N];
ll bpw(ll a,  ll b){
	ll res = 1;
	while(b){
		if(b % 2) res = res * a  % mod;
		b /= 2;
		a = (a * a) % mod;
	}
	return res;
}
ll inv(ll n){ return bpw(n , mod - 2); }
void init(){
	fac[0] = 1;
	for(int i = 1; i < N; ++i){
		fac[i] = fac[i - 1] * i % mod; 
	}
	for(int i = 1; i < N; ++i){
		sumInv[i] = ( sumInv[i - 1] + inv(i) ) % mod;
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
    	int n; cin >> n;
	    ll res = fac[n] * sumInv[n] % mod;;
	    cout << res << '\n';
    }
}