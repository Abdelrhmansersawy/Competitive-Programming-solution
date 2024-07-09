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
    vector<int> isPrime(n + 1 , 1) , noPrime(n + 1);
    isPrime[0] = isPrime[1] = 0;
    int cnt = 0;
    for(int i = 2; i <= n; ++i){
    	if(isPrime[i]){
    		noPrime[i] = 1;
    		for(int j = 2 * i; j <= n; j += i){
    			isPrime[j] = 0;
    			int k = j;
    			while(k % i == 0) noPrime[j]++ , k /= i;
    		}
    	}
    }
    for(int i = 2; i <= n; ++i){
    	if( isPrime[noPrime[i] ]  ) ++cnt;
    }
    cout << cnt;
}