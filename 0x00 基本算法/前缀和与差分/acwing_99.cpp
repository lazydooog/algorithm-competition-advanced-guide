/*
* @Description: 99. 激光炸弹
* @Author: Xiaobin Ren
* @Date:   2020-07-11 17:40:23
* @Last Modified time: 2020-07-11 18:26:46
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


const int N = 5010;
int g[N][N];

int main(){
    int N, R;
    cin >> N >> R;
    int n = R, m = R; //最小的边界，边R的正方形可能包括素有的点
    for(int i = 0, x, y, w; i < N; i++){
        cin >> x >> y >> w;
        x ++, y ++;  //前缀和从1开始计算，防止边界问题
        n = max(n, x), m = max(m, y); //更新最大边界
        g[x][y] += w;
    }
    
    for(int i = 1; i <= n; i++)
        for(int j = 0; j <= m; j++)
            g[i][j] += g[i - 1][j] + g[i][j - 1] - g[i-1][j-1];
            
    int res = 0;
    
    for(int i = R; i <= n; i ++)
        for(int j = R; j <= m; j++)
            res = max(res, g[i][j] - g[i - R][j] - g[i][j - R] + g[i - R][j - R]);  //边界的点不算，实际计算的是边长 R - 1 的正方形
    cout << res << endl;
    return 0;
}