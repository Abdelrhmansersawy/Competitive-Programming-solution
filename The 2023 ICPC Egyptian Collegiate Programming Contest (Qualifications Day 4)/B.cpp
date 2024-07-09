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
ll dis(ll x , ll y , ll xx , ll yy){
	ll dx = abs(x - xx);
	ll dy = abs(y - yy);
	return min(dx , dy) + abs(dx - dy);
}
int main(){
    ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
    #endif
    int a , b; cin >> a >> b;
    int c , d; cin >> c >> d;
    int n; cin >> n;
    vector<pair<int,int>> path;
    rep(dx , -1 , 2) rep(dy , -1 , 2){
    	if(dx == 0 && dy == 0) continue;
    	if(path.size()) continue;
    	int cc = c + dx , dd = d + dy;
    	if( __gcd( abs(a - cc) , abs(b - dd) ) == 1){
    		path.emplace_back(cc , dd);
    	}
    }
    assert(path.size());
    --n;
    if(n % 2 == 0){
    	rep(dx , -1 , 2) rep(dy , -1 , 2){
	    	if(n % 2) continue;
	    	if(dx == 0 && dy == 0) continue;
	    	int xx = path.back().f + dx , yy = path.back().s + dy;
	    	if( dis(xx , yy , c , d) == 1 ){
	    		path.emplace_back(xx , yy);
    			--n;
	    	}
    	}
    	assert(n % 2);
    }
    path.emplace_back(c , d);
    --n;
    assert(n % 2 == 0);
    for(;n > 0; n -= 2){
    	path.emplace_back(c + 1 , d);
    	path.emplace_back(c , d);
    }
    for(auto &[x , y] : path) cout << x << ' ' << y << '\n';
}