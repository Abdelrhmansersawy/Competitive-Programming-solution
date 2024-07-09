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
    ll n , E; cin >> n >> E;
    ll a[n];
    ll tot = 0, cnt[2]{};
    ll inter[2] = { INT32_MAX , -INT32_MAX };
    vector<int> v[2];
    bool f = false;
    for(int i = 0; i < n; ++i){
    	cin >> a[i];
    	inter[0] = min(inter[0] , a[i]);
    	inter[1] = max(inter[1] , a[i]);
    	if(a[i] == E) { f = true; continue;}
    	ll waiting = 10LL * abs(a[i] - E);
    	tot += waiting;
    	cnt[a[i] > E]++;
    	v[a[i] > E].emplace_back(a[i]);
    }
    ll ans[2]{}; // {Down , UP}	
    for(int o = 0; o < 2; ++o){
    	ans[o] = tot;
    	ans[o] += 10LL * cnt[o ^ 1] * abs(inter[o] - E);
    }
    sort(all(v[0]) , greater<int>());
    sort(all(v[1]));

    pair<int,int> vis;
    if(ans[0] < ans[1]){
    	vis = {0 , 1};
    }else{
    	vis = {1 , 0};
    }

    if(f) cout << E << ' ';
	for(auto &x : v[vis.f]) cout << x << ' ';
	for(auto &x : v[vis.s]) cout << x << ' ';

}