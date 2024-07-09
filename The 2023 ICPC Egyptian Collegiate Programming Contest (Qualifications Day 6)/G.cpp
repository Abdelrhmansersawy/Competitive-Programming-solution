#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i , st , ed) for(int i = st; i < ed; i++)
#define f first
#define s second
const int N = 1e5 + 9;
int n;
map<int,bool> frq[N];
int c[N];
ll ans;
vector<int> adj[N];
int dfs(int u , int par){
	int p = u;
	bool f = true;
	for(auto &v : adj[u]) if(v != par){
		int x = dfs(v , u);
		if(frq[x].size() > frq[p].size()) swap(x , p);
		for(auto &[c , f] : frq[x]){
			frq[p][c] = 1;
		}
		f = false;
	}
	if( !frq[p].count(c[u]) ){
		++ans;
		frq[p][c[u]] = 1;
	}
	return p;
}
void init(){
	for(int i = 0; i < n; ++i){
		adj[i].clear();
		frq[i].clear();
	}
	ans = 0;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
    #endif 
    int q; cin >> q;
    while(q--){
    	cin >> n;
    	init();
    	for(int i = 0; i < n; ++i) cin >> c[i];
    	for(int i = 1; i < n; ++i){
    		int u , v; cin >> u >> v;
    		--u; --v;
    		adj[u].emplace_back(v);
    		adj[v].emplace_back(u);
    	}
    	dfs(0 , 0);
    	cout << ans << '\n';
    }
}