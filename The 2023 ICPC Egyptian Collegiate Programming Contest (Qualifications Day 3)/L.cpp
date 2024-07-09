#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i , st , ed) for(int i = st; i < ed; i++)
#define f first
#define s second
ll add(ll a , ll b , int mod){
	return ((a % mod) + (b % mod)) % mod;
}
const int mod = 1e9 + 7;
ll fast_power(ll a , ll b){
	if(b == 0)return 1;
	ll res = fast_power(a , b/ 2);
	res = (res % mod) * (res % mod);
	if(b & 1)return res * a % mod;
	return res;
}
ll solve(vector<int>&v){
	map<int,int>mp;
	for(auto &val : v){
		for(int j = 2;j*j<=val;j++){
			while(val % j == 0){
				mp[j]++;
				val /= j;
			}
		}
		if(val > 1)mp[val]++;
	}
	ll res = 0;
	for(auto &val:mp){
		ll temp = 1;
		for (int i = 1;i<=val.second;i++){
			temp = temp * val.first % mod;
			res = add(res, temp , mod);
		}
	}

	return res;
}
const int N = 1e5 + 100;
int v[N];
int main(){
    ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
    #endif 
    int n;
    cin>>n;
    for(int i = 0;i<n;i++){
    	cin>>v[i];
    }
    vector<vector<int>>all;
    sort(v , v + n);
    vector<int>temp;
    for(int i = 0;i<n;i++){
    	if(i + 1 < n && v[i] * 2 >= v[i +1]){
    		temp.emplace_back(v[i]);
    	}else{
    		temp.emplace_back(v[i]);
    		all.emplace_back(temp);
    		temp.clear();
    	}
    }
    if(temp.size())all.emplace_back(temp);
    ll res = 0;

    for(auto &val:all){
    	res = add(res , solve(val) , mod);
    }
    cout<<res<<endl;
}
