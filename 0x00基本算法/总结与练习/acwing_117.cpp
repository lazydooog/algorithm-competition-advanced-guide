/*
* @Description: 117. 占卜DIY
* @Author: Xiaobin Ren
* @Date:   2020-07-16 17:56:45
* @Last Modified time: 2020-07-16 17:57:11
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

const int N = 14;

vector<int> close[N];  // 1 ~ 13  所以数组开14  这个数组表示盖着的牌
int open[N];  //表示每一堆排里向上的牌的个数

int get(char c){
    if(c == 'A') return 1;
    if(c >= '2' && c <= '9') return c - '0';
    if(c == '0') return 10;
    if(c == 'J') return 11;
    if(c == 'Q') return 12;
    return 13;  // K
}


int main(){
    for(int i = 1; i <= 13; i++){
        for(int j = 0; j < 4; j++){
            char s[2];
            cin >> s;
            close[i].push_back(get(*s)); // *s 取第一位，而不是空格
        }
    }
    
    for(int i = 0; i < 4; i++){  //模拟所有翻牌
        int t = close[13][i];
        while(t != 13){
            open[t] ++;
            int r = close[t].back();
            close[t].pop_back();
            t = r;
        }
    }
    int res = 0;
    //统计
    for(int i = 1; i <= 12; i++) res += open[i] >= 4;
    
    cout << res << endl;
    
    return 0;
    
}