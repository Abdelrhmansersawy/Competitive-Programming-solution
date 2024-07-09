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
    int n , LOG;
    void init(vector<T> &a){
        this-> n = (int) a.size();
        this->LOG = 0;
        int size = 1;
        while(size <= n) size *= 2 , LOG++;
        mx.assign(n , vector<T>(LOG));
        for (int i = 0; i < n; i++)mx[i][0] = a[i];
        for (int j = 1; (1 << j) <= n; j++){
            for (int i = 0; (i + (1 << j) - 1) < n; i++){
                mx[i][j] = merge(mx[i][j - 1] , mx[i + (1 << (j - 1))][j - 1]);
            }
        }
    }
    T merge(T a , T b){
        return max(a , b); // change the operation
    }
    T qry(int l, int r){
        int len = r - l + 1;
        int j = 31 - __builtin_clz(len);
        T res = merge(mx[l][j] , mx[r - (1 << j) + 1][j]);
        return res; // determine what you want to return 
    }
};
int main(){
    ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
    #endif
    int q; cin >> q;
    while(q--){
        int n; cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; ++i) cin >> a[i];
        Sparetable<int> spt; spt.init(a);
        if(n < 3){ cout << "0\n"; continue; }
        ll ans = 0;
        for(int i = 0; i < n - 2; ++i){
            int f1 = spt.qry(0 , i);
            int lo = i + 1 , hi = n - 2 , mid;
            if (f1 + spt.qry(i + 1 , i + 1) > spt.qry(i + 2 , n - 1) ) continue;
            while(lo < hi){
                mid = lo + (hi - lo + 1) / 2;
                int f2 = spt.qry(i + 1 , mid);
                int f3 = spt.qry(mid + 1 , n - 1);
                if(f1 + f2 <= f3) lo = mid;
                else hi = mid - 1;
            }
            ans += (lo - i);
        }
        cout << ans << '\n';
    }
}