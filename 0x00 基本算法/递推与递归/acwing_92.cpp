/*
* @Description: AcWing 92. 递归实现指数型枚举
* @Author: Xiaobin Ren
* @Date:   2020-05-01 20:06:44
* @Last Modified time: 2020-05-01 20:12:52
*/


//状压非递归实现

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
ll powmod(ll a, ll b) {ll res=1;a%=mod;assert(b>=0);for(;b;b>>=1){if(b&1)res*=a%mod;a*=a%mod;}return res;}
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a;}
//head




int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(0);

	int n;
	cin >> n;

	//state 是每一个状态
	rep(state, 0, 1 << n){
		rep(j, 0, n)
			if(state >> j & 1) cout << j + 1 << " ";
		cout << endl;
	}

	return 0;
}