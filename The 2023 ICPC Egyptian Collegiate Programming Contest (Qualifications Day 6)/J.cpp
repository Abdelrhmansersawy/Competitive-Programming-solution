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
    int t;cin>>t;
    while(t--){
    	ll n , y;
    	cin>>n>>y;
 		ll oring = 0;
 		for(int i = 0;i<n;i++){
 			ll x;cin>>x;
 			oring |= x;
 		}
 		ll res = 0;
 		bool fail = false;
 		for(int i = 0;i<40;i++){
 			if((oring & (1LL<<i)) && (y &(1LL<<i)))continue;
 			if((oring & (1LL<<i)) && !(y &(1LL<<i)))fail = true;
 			if(!(oring & (1LL<<i)) && !(y &(1LL<<i)))continue;
 			if(!(oring & (1LL<<i)) && (y & (1LL<<i)))res |= (1LL<<i);
 		}
 		cout<<(fail ? -1 : res)<<'\n';
    }
}