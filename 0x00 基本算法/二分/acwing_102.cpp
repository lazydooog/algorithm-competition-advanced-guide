/*
* @Description: 102. 最佳牛围栏
* @Author: Xiaobin Ren
* @Date:   2020-07-12 08:40:23
* @Last Modified time: 2020-07-12 10:36:31
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
    问题核心在于求最大子段和的“平均值”最大 而不是子段和最大。
    只需要最大子段和大于0，也就是存在，然后二分mid求最大的平均值即可
    数列减去mid后，寻找一个子段和>0的子段即可，要求这个问题，只需要最大的子段和>0即可，也就是存在。
*/
const int N = 100010;

int n, m;
int cows[N];
double sum[N];

bool check(double avg){
    for(int i = 1; i <= n; i++) sum[i] = sum[i - 1] + cows[i] - avg;
    
    double minv = 0;
    for(int i = 0, j = m; j <= n; j++, i++){
        minv = min(minv, sum[i]);
        if(sum[j] >= minv) return true;
        
    }
    return false;
}

int main(){
    
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> cows[i];
    double l = 0, r = 2000;
    while(r - l > 1e-5){
        double mid = (l + r) / 2;
        if(check(mid)) l = mid;
        else r = mid;
    }
    printf("%d\n", int(r * 1000));
    
    return 0;
}