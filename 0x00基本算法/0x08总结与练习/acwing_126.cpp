/*
* @Description: 126. 最大的和
* @Author: Xiaobin Ren
* @Date:   2020-07-20 20:17:26
* @Last Modified time: 2020-07-20 20:17:50
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

const int N = 110;
int g[N][N];
int n;

int main(){
    cin >> n;
    for(int i = 1 ; i  <=n; i++)
        for(int j = 1; j <= n; j++){
            cin >> g[i][j];
            g[i][j] += g[i - 1][j];  //上下界求 前缀和
        }
    
    int res = INT_MIN;
    for(int i = 1; i <= n; i++)
        for(int j = i; j <= n; j++){   //n * n 矩阵 j变量枚举i下边的下界区域  k横向扫描
            int last = 0;
            for(int k = 1; k <= n; k++){
                last = max(last, 0) + g[j][k] - g[i - 1][k];
                res = max(res, last);
            }
        }
        
    cout << res << endl;
    
    return 0;
}



