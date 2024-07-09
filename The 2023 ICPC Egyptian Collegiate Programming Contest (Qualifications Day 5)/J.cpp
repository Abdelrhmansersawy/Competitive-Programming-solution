#include <bits/stdc++.h>
using namespace std;
#define line '\n'
typedef long long ll;
#define rep(i , st , ed) for(int i = st; i < ed; i++)
#define f first
#define s second

#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace __gnu_pbds;
template<class T> using ordered_set = tree<T, null_type , less_equal<T> , rb_tree_tag , tree_order_statistics_node_update> ;
int solve(string &s1 , string &s2){
	if(s1.size() != s2.size() || count(s1.begin() , s1.end() , '1') != count(s2.begin() , s2.end() , '1')){
		return INT32_MAX;
	}
	// cerr << s1 << ' ' << s2 << '\n';
	ordered_set<int> pos[2];
	for(int i = 0; i < s1.size(); ++i){
		pos[s1[i] == '1'].insert(i);
	}
	ll ans = 0;
	for(auto &ch : s2){
		int f = (ch == '1');
		assert(pos[f].size());
		int i = *pos[f].find_by_order(0);
		int ope = pos[f ^ 1].order_of_key(i);
		ans += ope;
		pos[f].erase( pos[f].lower_bound(i - 1) );
	}
	return ans;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
    #endif 
    int t;
    cin>>t;
    while(t--){
    	int n;cin>>n;
    	string s;
    	cin>>s;
    	string temp1 , temp2;
    	bool f = false;
    	for(int i = 0;i<n;i++){
    		if(f)temp1 += '0' , temp2 += '1';
    		else temp1 +='1' , temp2 += '0';
    		f ^= true;
    	}
    	int c0 = count(s.begin() , s.end() , '0');
    	int c1 = n - c0;
    	if(c0 == (n + 1) /2 && c1 == n/ 2 || c0 == n / 2 && c1 == (n + 1) / 2){
    		int res = 1e9;
    		cout<<min(solve(s, temp1) , solve(s , temp2))<<line;
    	}else{
    		cout<<-1<<'\n';
    	}
    }
}