/*
* @Description: 116. 飞行员兄弟
* @Author: Xiaobin Ren
* @Date:   2020-07-16 16:20:41
* @Last Modified time: 2020-07-16 16:48:41
*/
#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for(int i = a; i< n; i++)
#define per(i,a,n) for(int i=n-1; i>=a; i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define sz(x) ((int)(x).size())
typedef vector<int> VI;
typedef long long ll;
typedef pair<int, int> PII;
typedef double db;
mt19937 mrand(random_device{}());
const ll mod = 1000000007;
int rnd(int x) { return mrand() % x;}
ll mulmod(ll a, ll b) {ll res=0;a%=mod;assert(b>=0);for(;b;b>>=1){if(b&1)res=(res+a)%mod;a=2*a%mod;}return res;}
ll powmod(ll a, ll b) {ll res=1;a%=mod;assert(b>=0);for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a;}
//snippet-head

/*	
	思路：全部状压用16位二进制数表示整个矩阵的状态
	任何数^0 = 自己, 0^1=1, 1^1 = 0; 
	所以对于一个点的坐标二进制数与当前的state异或，对于state，只有这个坐标对应的二进制位会发生改变
	所以对于每个行列的变换，直接用当前的state^点的坐标转换之后的二进制数字即可
*/


int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	int state = 0;
	char c;
	rep(i, 0, 16){
		cin >> c;
		if(c == '+') state |= (1 << i);
	}

	for(int k = 1; k <= (1 << 16); k++){  //枚举所有状态空间
		int temp = state;  //储存初始状态
		vector<PII> path;
		rep(i, 0 ,16) {
			if (k >> i & 1){
				int x = i / 4, y = i % 4, pos;
				rep(j, 0, 4) state ^= (1 << (x *4 + j)); //变换行
				rep(j, 0, 4) {  //变换列，注意将中心点只需要变换一次，所以要特判
					pos = (1 << (y + j * 4));
					if(pos != (1 << i)) state ^= pos;
				}
				path.push_back({x + 1, y + 1});
			}
		}
		if(state == 0) {  //枚举到一种可行解
			cout << path.size() << endl;
			for(auto i : path) cout << i.fi << ' ' << i.se << endl;
		}
	state = temp;

	}

	return 0;
	
}



