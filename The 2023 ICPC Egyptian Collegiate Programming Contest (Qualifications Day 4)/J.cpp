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
    int coupon , n , q; cin >> coupon >> n >> q;
   	set<pair<ll,int> , greater<pair<ll,int>>> pay;
   	auto tot = [&](int price){ return 1LL * (coupon / price) * price; };
   	for(int i = 0; i < n; ++i){
		int price; cin >> price;

		if( tot(price) == 0) pay.emplace( tot(price) , -price );
		else pay.emplace( tot(price) , price );
   	}
   	while(q--){
   		int t; cin >> t;
   		if(t == 1){
   			if(pay.empty()) cout << -1 << '\n';
   			else cout << abs(pay.begin()->s) << '\n'; 
   		}else if(t == 2){
   			int price; cin >> price;
   			if( tot(price) == 0) pay.emplace( tot(price) , -price );
			else pay.emplace( tot(price) , price );
   		}else{
   			int x; cin >> x;
   			auto p = make_pair(tot(x) , x);
   			if(p.f == 0) p.s *= -1;
   			if( pay.count(p) ){
   				pay.erase(pay.find(p));
   				cout << "Deleted Successfully\n";
   			}else{
   				cout << "Can't Delete\n";
   			}
   		}
   	}
   	for(auto &[x , y] : pay){
   		cout << abs(y) << ' ';
   	}
}