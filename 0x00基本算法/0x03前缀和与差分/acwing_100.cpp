/*
* @Description: 100. 增减序列
* @Author: Xiaobin Ren
* @Date:   2020-07-11 18:34:09
* @Last Modified time: 2020-07-11 19:38:16
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
int a[N];

int main(){
    int n; cin >> n;
    for(int i = 1; i <=n; i++) scanf("%d", &a[i]);
    for(int i = n; i > 1; i--) a[i] = a[i] -a[i - 1]; //此处直接用原数组来求差分，不开新数祖技巧：逆序求，正序没法求。
    //因为逆序求会用到前一个元素的值，但改变的是后一个元素的值。所以原数组基础上只能逆序递推差分数祖。 开新数祖无所谓
    ll pos = 0, neg = 0;
    for(int i = 2; i <=n; i++){
        if (a[i] > 0) pos += a[i];
        else neg -= a[i];
    }
    
    cout << max(pos, neg) << endl;
    cout << abs(pos - neg) + 1 << endl;
    
    return 0;
    
}