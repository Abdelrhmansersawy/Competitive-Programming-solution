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
    ll n , x;cin>>n>>x;
    vector<pair<ll,ll>>vp;
    for(ll i = 1;i * i<= x;i++){
    	if(x % i == 0){
    		vp.emplace_back(i , x /i);
    		
    	}
    }
    ll res = 0;
    for(auto &val:vp){
    	if(max(val.first , val.second) <= n){
    		if(val.first != val.second)res += 2;
    		else res++;
    	}
    }
    cout<<res<<endl;
}