#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i , st , ed) for(int i = st; i < ed; i++)
#define f first
#define s second
const int mod = 1e9 + 7;
 
struct Mat {
    ll mat[3][3];
    ll row, col;
 
    Mat(ll _r, ll _c) : row(_r), col(_c) {
    	memset(mat , 0 , sizeof mat);
        
    }
 
    Mat operator *(const Mat& b) const {
        Mat Product(row, b.col);
        for(int i = 0; i < row; ++i) {
            for(int k = 0; k < col; ++k) {
                if(mat[i][k] != 0) {
                    for(int j = 0; j < b.col; ++j) {
                        Product.mat[i][j] += mat[i][k] * b.mat[k][j] % mod;
                    }
                }

            }
            for(int j = 0; j < b.col; ++j) {
                Product.mat[i][j] %= mod;
            }
        }
        return Product;
    }
};
 
Mat power(Mat a, ll b) {
    Mat res(a.row, a.col);
    for(int i = 0; i < res.row; ++i) res.mat[i][i] = 1;
    while(b > 0) {
        if(b & 1) {
            res = res * a;
        }
        a = a * a;
        b >>= 1;
    }
    return res;
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	#ifndef ONLINE_JUDGE
	    freopen("in.txt", "r", stdin);
	    freopen("out.txt", "w", stdout);
	    freopen("error.txt", "w", stderr);
	#endif 
	    int q; cin >> q;
	    Mat m(3,3);
	    Mat base(3,1);
	    m.mat[0][0] = 2;
	    m.mat[0][2] = 1;
	    m.mat[1][1] = 1;
	    m.mat[2][1] = 1;
	    m.mat[2][2] = 1;
	    base.mat[1][0] = base.mat[2][0] = 1;
	    for(int i = 0; i < q; ++i){
	    	int k; cin >> k;
	    	Mat ans = power(m,k);
	    	cout <<  (ans.mat[0][1] + ans.mat[0][2])%mod << '\n';

	    }
	
}