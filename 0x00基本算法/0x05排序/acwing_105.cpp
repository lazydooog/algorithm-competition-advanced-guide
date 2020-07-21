/*
* @Description: 105. 七夕祭
* @Author: Xiaobin Ren
* @Date:   2020-07-12 21:56:33
* @Last Modified time: 2020-07-12 22:07:47
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

const int N = 100010;
ll n, m, t, x, y, a[N], b[N], f[N];

ll calc (ll a[], ll n){
	for (int i = 1; i <= n; ++i)
	{	
		a[i] -= (a[0] / n);
		f[i] = f[i - 1] + a[i];
	}
	sort(f + 1, f + 1 + n);

	ll mid = (n + 1) >> 1, ans = 0;

	for(int i = 1; i <= n; i++) ans += abs(f[mid] - f[i]);

	return ans;
}


int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m >> t;
	for(int i = 1; i <= t; i++) {
		cin  >> x >> y;
		a[x] ++;
		b[y] ++;
	}

	for(int i = 1; i <= n; i++) a[0] += a[i];
	for(int i = 1; i <= m; i++) b[0] += b[i];

	ll as = a[0] % n, bs = b[0] % m;

	if(!as && !bs) cout << "both " << calc(a, n) + calc(b, m);
	else if (!as) cout << "row " << calc(a, n);
	else if (!bs) cout << "column " << calc(b,m);
	else cout << "impossible" ;

	return 0;
}