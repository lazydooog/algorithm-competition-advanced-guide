/*
* @Description: 95. 费解的开关
* @Author: Xiaobin Ren
* @Date:   2020-07-11 10:55:13
* @Last Modified time: 2020-07-11 11:42:53
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


const int INF = 0x3f3f3f3f;
char g[10][10];
int dx[5] = {0, -1, 0, 1, 0}, dy[5] = {0, 0, 1, 0, -1};

void turn(int x, int y){   //对x，y位置进行操作
    for(int i = 0; i < 5; i++){
        int a = x + dx[i], b = y + dy[i];
        if(a >= 0 && a < 5 && b >= 0 && b <5) g[a][b] ^= 1;
    }
}

int solve(){
    int ans = INF;
    for(int k = 0; k < 1 << 5; k++){
        int res = 0;  //标记答案 最后更新
        char backup[10][10];
        memcpy(backup, g, sizeof g);  
        for(int j = 0; j < 5; j++)
            if(k >> j & 1){
                res ++ ;
                turn(0, j); 
            }
        for(int i = 0; i < 4; i++)
            for(int j = 0; j < 5; j++)
                if (g[i][j] == '0'){
                    res ++;
                    turn(i + 1, j);
                }
        bool flag = true;
        for(int j = 0; j < 5; j++)
            if (g[4][j] == '0'){
                flag = false;
                break;
            }
        if(flag) ans = min(ans, res);
        
        memcpy(g, backup, sizeof g); // 还原初始数祖，判断下一个样例
    }
    
    if (ans > 6) ans = -1;
    return ans;
}


int main(){
    int t;
    cin >> t;
    while(t--){
        for(int i = 0; i < 5; i++) cin >> g[i];
        cout << solve() << endl;
    }
    
    return 0;
}