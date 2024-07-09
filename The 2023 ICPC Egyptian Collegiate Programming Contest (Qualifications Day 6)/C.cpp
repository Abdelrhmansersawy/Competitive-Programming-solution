#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i , st , ed) for(int i = st; i < ed; i++)
#define f first
#define s second
const int N = 1e5 + 9;
vector<pair<int,ll>> adj[N] , revadj[N];
int n , m , q;
vector<ll> topo(int st, vector<pair<int,ll>> adj[]){
	vector<int> deg(n);
	
	vector<int> vis(n);
	queue<int> q;
	q.push(st); vis[st] = 1;
	while(q.size()){
		auto u = q.front(); q.pop();
		for(auto &[v , w] : adj[u]){
			deg[v]++;
			if(vis[v] == 0){
				vis[v] = 1;
				q.push(v);
			}
		}
	}

	vector<ll> dp(n , -1);
	q.push(st); dp[st] = 0;
	while(q.size()){
		auto u = q.front(); q.pop();
		for(auto &[v, w]: adj[u]){
			dp[v] = max(dp[v] , dp[u] + w);
			if(--deg[v] == 0){
				q.push(v);
			}
		}
	}
	return dp;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
    #endif 
    cin >> n >> m >> q;
    for(int i = 0; i < m; ++i){
    	int u , v , w; cin >> u >> v >> w;
    	--u; --v;
    	adj[u].emplace_back(v , w);
    	revadj[v].emplace_back(u , w);
    }
    auto dis1 = topo(0 , adj);
    auto dis2 = topo(n - 1 , revadj);
    while(q--){
    	int x; cin >> x;
    	--x;
    	if(dis1[x] == -1 || dis2[x] == -1){
    		cout << "-1\n";
    	}else cout << (dis1[x] + dis2[x]) << '\n';
    }
}