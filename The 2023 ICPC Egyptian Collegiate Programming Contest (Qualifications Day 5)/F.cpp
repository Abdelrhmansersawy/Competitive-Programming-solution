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
    int n;
    cin>>n;
    vector<ll>v(n);
    for(auto &val:v)cin>>val;
    vector<ll>pref(3 * n + 10);
	for(int i = 0;i<n;i++){
		pref[i]++ , pref[i + v[i]]--;
	}
	for(int i = 1;i< pref.size();i++)pref[i] += pref[i - 1];
	cout<<*max_element( pref.begin() , pref.end() );
}