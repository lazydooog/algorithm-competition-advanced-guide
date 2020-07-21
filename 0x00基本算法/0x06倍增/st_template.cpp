/*
* @Description: ST算法模板
* @Author: Xiaobin Ren
* @Date:   2020-07-14 11:20:07
* @Last Modified time: 2020-07-14 12:22:44
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

const int M = 25;  // 2 ^25
const int N = 100005;
int n, m;
int a[N];
int f[N][M];

void st_prework(){   //预处理st表
	for(int i = 1; i <= n; i++) f[i][0] = a[i];
	int t = log(n) / log(2) + 1;
	for(int j = 1; j < t; j++)
		for(int i = 1; i <= n - (1 << j) + 1; i++)
			f[i][j] = max(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
}

int st_query(int l, int r){   //查询
	int k = log(r - l + 1) / log(2);
	return max(f[l][k], f[r - (1 << k) + 1][k]);
}

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	scanf("%d", &n);
	rep(i, 0, n + 1) scanf("%d", &a[i]);
	st_prework();
	cout << st_query(0,5) << endl;

	return 0;
}