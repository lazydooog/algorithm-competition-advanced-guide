/*
* @Description: 96. 奇怪的汉诺塔
* @Author: Xiaobin Ren
* @Date:   2020-05-01 21:51:18
* @Last Modified time: 2020-05-01 22:02:41
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
ll powmod(ll a, ll b) {ll res=1;a%=mod;assert(b>=0);for(;b;b>>=1){if(b&1)res*=a%mod;a*=a%mod;}return res;}
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a;}
//competitive-programing-snippet-head


//题解: https://www.acwing.com/solution/acwing/content/919/
//先把 i 个移到除了目标塔的其他一个塔， 然后剩下的就按照三个塔的方法处理即可
//由于 i 的选取不同，暴力枚举所有的 i  找到最小的即可
int a[15], f[15];


int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	a[1] = 1;
	rep(i, 2, 13) a[i] =  2 * a[i - 1] + 1;  //处理三个塔的情况
	memset(f,0x3f,sizeof(f));
	f[0] = 0;
	rep(i, 1, 13) rep(j, 0, i) f[i] = min(f[i], f[j] * 2 + a[i - j]);
	
	rep(i, 1, 13) cout << f[i] << endl;
}