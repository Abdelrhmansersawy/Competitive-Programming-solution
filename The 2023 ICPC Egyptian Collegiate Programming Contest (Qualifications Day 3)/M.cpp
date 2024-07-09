#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i , st , ed) for(int i = st; i < ed; i++)
#define f first
#define s second
#define all(x) x.begin() , x.end()
int main(){
    ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
    #endif 
    int n; cin >> n;
    vector<array<int,3>> inter[n];
    for(int i = 0; i < n; ++i){
    	int m; cin >> m;
    	while(m--){
    		int a , b , c; cin >> a >> b >> c;
    		--a; --b;
    		if(a <= b) inter[i].push_back({c , a , b});
    		else{
    			inter[i].push_back({c , 0 , a});
    			inter[i].push_back({c , b , n - 1});
    		}
    	}
    }
    int S , E; cin >> S >> E;
    --S; --E;
    priority_queue< array<ll,3> , vector< array<ll,3> >, greater< array<ll,3> > > q;

    set<int> s;
    vector<ll> ans(n , -1);
    for(int i = 0; i < n; ++i) s.emplace(i);
	
    q.push({0 , S , S});

    while(q.size()){
    	auto [c , l , r] = q.top(); q.pop();
    	
    	auto it = s.lower_bound(l);
    	vector<int> v;
    	while(it != s.end() && *it  <= r){
    		int u = *it;
    		v.emplace_back(u);
    		ans[u] = c;
    		++it;
    	}
    	for(auto &u : v){
    		sort( all(inter[u]) );
    		for(auto &[w ,a , b] : inter[u]){
    			q.push({c +  w , a , b});
    		}
    		s.erase(u);
    	}
    }
    cout << ans[E];
}