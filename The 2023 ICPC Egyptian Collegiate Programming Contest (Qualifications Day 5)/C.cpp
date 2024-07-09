#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i , st , ed) for(int i = st; i < ed; i++)
#define f first
#define s second
const int N = 1e4 + 5;
int v[N];
int ans[N];
int n;
int main(){
    ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
    #endif
 	cin>>n;
 	for(int i= 0;i<n;i++)ans[i] = 1e9;
 	for(int i = 0;i<n;i++)cin>>v[i];
 	for(int i = 0;i<(1<<10);i++){
 		int cost = __builtin_popcountll(i);
 		vector<int>pos;
 		for(int j=0;j<n;j++){
 			if(i & (1<<v[j]))continue;
 			pos.emplace_back(v[j]);
 		}
 		vector<int>lst(10 , -1);
 		int d = 0;
 		for(int j=0;j<pos.size();j++){
 			if(lst[pos[j]] == -1)lst[pos[j]] = j;
 			d = max(d , j - lst[pos[j]]);
 			lst[pos[j]] = j;
 		}
 		ans[d] = min(cost , ans[d]);
 	}
 	int mn = ans[0];
 	for(int i = 1;i<n ;i++){
 		mn = min(mn , ans[i]);
 		cout<<mn<<" ";
 	}

}