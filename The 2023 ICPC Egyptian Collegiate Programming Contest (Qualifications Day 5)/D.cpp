#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i , st , ed) for(int i = st; i < ed; i++)
#define f first
#define s second
const int N = 5e5 + 9;
int n , x , k;
vector<pair<int,int>> primeFac[N];
int invA[N] , A[N];
void init(){
	for(int i = 2; i < N; ++i) if(primeFac[i].empty()){
		for(int j = i; j < N; j += i){
			primeFac[j].emplace_back(i , 0);
			int k = j;
			while(k % i == 0){
				k /= i;
				primeFac[j].back().s++;
			}
		}
	}
	for(int i = 1; i < N; ++i){
		invA[i] = A[i] = 1;
		for(auto &[p , q] : primeFac[i]){
			int need_q = (x - q % x) % x;
			A[i] *= pow(p , q % x);
			while(need_q && 1LL * invA[i] * p <= N){
				invA[i] *= p;
				--need_q;
			}
			if(need_q) invA[i] = N;
		}
	}
}
int main(){
    ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
    #endif 
    cin >> n >> x >> k;
    init();
    int a[n];
    for(int i = 0; i < n; ++i) cin >> a[i];
   	int l = 0;
   	vector<int> ans;
   	while(l < n){
   		int r = l;
   		map<ll,ll> frq;
   		ll cnt = 0;
   		while(r < n && cnt + frq[invA[a[r]]] <= k){
   			cnt += frq[invA[a[r]]];
   			frq[A[a[r]]]++;
   			++r;
   		}
   		ans.emplace_back(r - l);
  		l = r;
   	}
   	cout << (int) ans.size() << '\n';
   	for(auto &x : ans) cout << x << ' ';
}