/*
* @Description: 118. 分形
* @Author: Xiaobin Ren
* @Date:   2020-07-17 15:02:53
* @Last Modified time: 2020-07-17 15:04:49
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

const int N = 1010;
char g[N][N];

void dfs(int n){
    if(n == 1) {
        g[0][0] = 'X';
        return;
    }
    dfs(n - 1);
    
    int len = 1;
    for(int i = 0; i < n - 2; i++) len *= 3;
    
    int sx[4] = {0,1,2,2}, sy[4] = {2,1,0,2};  //另外4个正方形左上角起点坐标
    
    for(int k = 0; k < 4; k++) // 循环4次处理其他4个正方形
        for(int i= 0; i < len; i++)
            for(int j = 0; j < len; j++)
                g[sx[k] * len + i][sy[k] * len + j] = g[i][j];
    
}

int main(){
    dfs(7);  //需要几级就输出右上角即可
    int n ;
    while(cin >> n && n != -1){
        int len  = 1;
        for(int i = 0; i < n - 1; i++) len *= 3;   //从0开始，第n级有 3^n 层 'x'
        for(int i = 0; i < len; i++){
            for(int j = 0; j < len; j++)  //这个图是个正方形，样例那个图有问题
            if(g[i][j]) cout << 'X';
            else cout << ' ';
            
            cout << endl;
        }
        cout << '-' << endl;
    }
    
    return 0;
}