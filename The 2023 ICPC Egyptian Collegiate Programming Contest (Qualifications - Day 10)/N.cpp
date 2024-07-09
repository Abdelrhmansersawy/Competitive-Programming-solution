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
        string s; cin >> s;
        string word = "ecpc";
        int ans = n;
        for(int i = 0; i <= n - word.size(); ++i){
            int j = i , k = 0 , cnt = 0;
            while(k < word.size()){
                cnt += (s[j] != word[k]) ;
                ++j; ++k;
            }
            ans = min(ans , cnt);
        }
        cout << ans << '\n';
    }
}