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
        int n; cin >> n;
        int a[n];
        ll before = 0 , after = 0;
        for(int i = 0; i < n; ++i){
            cin >> a[i];
            after += a[i];
        }
        int give = 0;
        for(int i = 0; i < n; ++i){
            after -= a[i];
            before += a[i];
            if(before > after) give = max(give , n - i - 1);
            if(after > before) give = max(give , i + 1);

        }
        cout << give << '\n';
    }
}