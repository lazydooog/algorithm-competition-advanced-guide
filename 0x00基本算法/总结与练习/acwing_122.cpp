/*
* @Description: 122. 糖果传递
* @Author: Xiaobin Ren
* @Date:   2020-07-18 23:40:06
* @Last Modified time: 2020-07-18 23:40:25
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


ll sum;
const int N = 1e6 + 10;
int n;
int a[N], f[N];
int main(){
    cin >> n;
    for(int i = 1; i <= n; i ++){
        cin >> a[i];
        sum += a[i];
    }
    ll ave = sum / n;
    
    for(int i = 2; i <= n; i++) f[i] = f[i - 1] + a[i] - ave;
    sort(f + 1, f + 1 + n);
    
    int  mid = (1 + n) >> 1;
    ll res= 0;
    
    for(int i = 1; i <= n; i++) res += abs(f[i] - f[mid]);
    
    cout << res << endl;
    
    return 0;
}