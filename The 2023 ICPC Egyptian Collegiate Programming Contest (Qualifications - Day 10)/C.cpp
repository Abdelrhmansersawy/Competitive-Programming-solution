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
    int q; cin >> q;
    while(q--){
        int n , m , k; cin >> n >> m >> k;
        int a[n][m];
        multiset<ll> all;
        for(int i = 0; i < n; ++i) for(int j = 0; j < m; ++j){
            cin >> a[i][j];
            all.emplace(a[i][j]);
        }
        if(k == 1){ cout << "0\n"; continue; }
        ll ans = 0;
        for(int j = 0; j < m; ++j){
            for(int i = 0;i < n; ++i) all.erase(all.find(a[i][j]));
            for(int i = 0; i < n; ++i){
                ll cur = max(
                            abs(a[i][j] - *all.begin()),
                            abs(a[i][j] - *all.rbegin()) 
                         );
                ans = max(ans , cur);
    
            }
            for(int i = 0;i < n; ++i) all.emplace(a[i][j]);
            
        }
        cout << ans << '\n';
    }
}