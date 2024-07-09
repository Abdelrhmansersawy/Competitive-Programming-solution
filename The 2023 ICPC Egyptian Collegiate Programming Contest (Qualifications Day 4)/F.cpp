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
template<class T = int>
struct Sparetable{
    vector<vector<T>> mx;
    vector<vector<T>> mn;
    int n , LOG;
    void init(vector<T> &a){
        this-> n = (int) a.size();
        this->LOG = 0;
        int size = 1;
        while(size <= n) size *= 2 , LOG++;
        mx.assign(n , vector<T>(LOG));
        mn.assign(n , vector<T>(LOG));
        for (int i = 0; i < n; i++) mn[i][0] = mx[i][0] = a[i];
        for (int j = 1; (1 << j) <= n; j++){
            for (int i = 0; (i + (1 << j) - 1) < n; i++){
                mn[i][j] = min(mn[i][j - 1] , mn[i + (1 << (j - 1))][j - 1]);
                mx[i][j] = max(mx[i][j - 1] , mx[i + (1 << (j - 1))][j - 1]);
            }
        }
    }
    T getMin(int l , int r){
    	int len = r - l + 1;
        int j = 31 - __builtin_clz(len);
        T res = min(mn[l][j] , mn[r - (1 << j) + 1][j]);
        return res;
    }
    T getMax(int l , int r){
    	int len = r - l + 1;
        int j = 31 - __builtin_clz(len);
        T res = max(mx[l][j] , mx[r - (1 << j) + 1][j]);
        return res;
    }
};
int main(){
    ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
    #endif
    int n , q; cin >> n >> q;
    vector<ll> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i];
    Sparetable<ll> spt; spt.init(a);
	while(q--){
    	int l , r , w; cin >> l >> r >> w;
    	--l; --r;
    	ll ans = spt.getMin(l , r) ^ spt.getMax(l , r) ^ w;
    	if(ans) cout << "YES\n";
    	else cout << "NO\n";
    }
}