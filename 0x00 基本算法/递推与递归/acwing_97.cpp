/*
* @Description: 97. 约数之和
* @Author: Xiaobin Ren
* @Date:   2020-05-01 22:15:50
* @Last Modified time: 2020-05-01 22:28:04
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
const ll mod = 9901;
int rnd(int x) { return mrand() % x;}
ll mulmod(ll a, ll b) {ll res=0;a%=mod;assert(b>=0);for(;b;b>>=1){if(b&1)res=(res+a)%mod;a=2*a%mod;}return res;}
ll powmod(ll a, ll b) {ll res=1;a%=mod;assert(b>=0);for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a;}
//competitive-programing-snippet-head


int a, b;

ll sum(int p,int c){
    if (c==0)
        return 1;
    if(c&1)
        return ((1+powmod(p,(c+1)>>1))*sum(p,(c-1)>>1))%mod;//奇数的情况下
    else
        return ((1+powmod(p,c>>1))*sum(p,(c>>1)-1)+powmod(p,c))%mod;//偶数的情况下
}

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(0);

	cin >> a >> b;
	int ans = 1;
	rep(i, 2, a+1){ //质因子分解，试除法
		int s=0;
        while(a%i==0){ s++; a/=i;}
        if(s) ans = ans * sum(i, s * b) % mod;
	}
	if(a == 0) cout << 0 << endl;
	else cout << ans;

	return 0;
}