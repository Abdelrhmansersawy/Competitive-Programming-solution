#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i , st , ed) for(int i = st; i < ed; i++)
#define f first
#define s second
const int N = 1e5 + 5;
vector<int>adj[N];
ll value[N];
map<int,ll>mp[N];
int ids[N];
int main(){
    ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
    #endif 
    int n , q;
    cin>>n>>q;
    for(int i = 1;i<N;i++){
    	for(int j=i;j<N;j+=i){
    		adj[j].emplace_back(i);
    	}
    }

    while(q--){
    	int type;
    	cin>>type;
    	if(type == 1){
    		//insert
    		int s ,x;
    		cin>>s>>x;
    		ids[s] = x;
    		for(auto &val:adj[x]){
    			mp[s][val] = value[val];
    		}
    	}else if(type == 2){
    		ll x, y; cin>>x>>y;
    		value[x] += y;
    	}else{
    		int s ;cin>>s;
    		ll res = 0;
    		for(auto &val:adj[ids[s]]){
    			res += value[val] - mp[s][val];
    		}
    		cout<<res<<'\n';
    	}
    }
}