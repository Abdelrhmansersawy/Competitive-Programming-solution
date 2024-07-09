#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i , st , ed) for(int i = st; i < ed; i++)
#define f first
#define s second
int main(){
    ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
        freopen("error.txt", "w", stderr);
    #endif 
    int n; cin >> n;
    vector<string> v(n);
    for(auto &i : v) cin >> i;
    int ans = 0;
    for(int i=1; i < n-1; ++i)
    {
        for(int j=1; j < v[i].size()-1; ++j)
        {
            if(v[i][j] == '*')
            {
                if(v[i][j+1] == v[i][j-1] && v[i+1][j] == v[i-1][j] && 
                    v[i][j] == v[i][j+1] && v[i][j] == v[i-1][j]) ans++;
            }
        }
    }
    cout << ans << "\n";

}