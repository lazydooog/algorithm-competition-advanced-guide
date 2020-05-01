/*
* @Description: 94. 递归实现排列型枚举
* @Author: Xiaobin Ren
* @Date:   2020-05-01 20:27:06
* @Last Modified time: 2020-05-01 20:33:52
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



// stl 做法
int n;

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	cin >> n;
	int a[n];
	rep(i, 0, n) a[i] = i + 1;
	do{
		rep(i , 0, n) cout << a[i] << ' ';
		cout << endl;
	}while(next_permutation(a, a + n));
	return 0;
}