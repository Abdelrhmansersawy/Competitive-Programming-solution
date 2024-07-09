#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i , st , ed) for(int i = st; i < ed; i++)
#define f first
#define s second
const int N = 2e5 + 9;
class BITrange {
private:
    long long m[N], c[N];
    void add(int pos, long long mVal, long long cVal) {
        for (++pos; pos <= N; pos += (pos & (-pos))) {
            m[pos - 1] += mVal;
            c[pos - 1] += cVal;
        }
    }
    long long get(int pos) {
        long long ret = 0;
        int x = pos;
        for (++pos; pos; pos -= (pos & (-pos))) {
            ret += m[pos - 1] * x + c[pos - 1];
        }
        return ret;
    }
    
public:
    void init(int n) {
        memset(m, 0, n * sizeof(m[0]));
        memset(c, 0, n * sizeof(m[0]));
    }
    void upd(int st, int en, long long val) {
        if(st > en) return;
        add(st, val, -val * (st - 1));
        add(en + 1, -val, val * en);
    }
    ll qry(int l , int r){ return get(r) - get(l - 1); }
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
        ll n , k; cin >> n >> k;
        ll pre[n + 1]{};
        for(int i = 1; i <= n; ++i){
            cin >> pre[i];
            pre[i] += pre[i - 1];
        }
        vector<pair<int,int>> query[n + 1];
        int Q; cin >> Q;
        ll ans[Q];
        for(int i = 0; i < Q; ++i){ 
            int l , r; cin >> l >> r;
            query[r].emplace_back(l , i);
        }
        map<ll , pair<int,int>> mp;
        BITrange B; B.init(n + 1);
        mp[0] = {1 , 1};
        for(int i = 1; i <= n; ++i){
            int t = pre[i] - k;
            if(mp.count(t)){
                B.upd(mp[t].f , mp[t].s , 1);
            }
            for(auto &[j , idx] : query[i]){
                ans[idx] = B.qry(j , i);
            }

            if(pre[i] != pre[i - 1]) mp[pre[i]] = {i + 1 , i + 1};
            else mp[pre[i]].s = i + 1;
        }
        for(auto &i : ans) cout << i << '\n';
    }
}