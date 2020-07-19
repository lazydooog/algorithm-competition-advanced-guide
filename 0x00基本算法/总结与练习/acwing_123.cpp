/*
* @Description: 123. 士兵
* @Author: Xiaobin Ren
* @Date:   2020-07-19 12:10:59
* @Last Modified time: 2020-07-19 12:11:34
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

const int N = 10010;

int x[N], y[N];
int sum1, sum2;
int main(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) 
        cin >> x[i] >> y[i];
    sort(x + 1, x + 1 + n);
    for(int i = 1; i <=n; i++) x[i] -= (i - 1);
    sort(x + 1, x + 1 + n);
    sort(y + 1, y + 1 + n);
    for(int i = 1; i <= n; i++){
        sum1 += abs(y[i] - y[(1 + n) / 2]);
        sum2 += abs(x[i] - x[(1 + n) / 2]);
    }
    
    cout << sum1 + sum2<< endl;
    
    return 0;
}