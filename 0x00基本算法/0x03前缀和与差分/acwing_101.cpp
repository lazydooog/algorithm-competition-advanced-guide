/*
* @Description: 101. 最高的牛
* @Author: Xiaobin Ren
* @Date:   2020-07-11 20:13:25
* @Last Modified time: 2020-07-11 20:13:47
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
int c[N], d[N];
map<pair<int, int>, bool> existed;

int main(){
    int n, p, h,m;
    cin >> n >> p >> h >> m;
    while(m --){
        int a, b;
        scanf("%d%d", &a, &b);
        if(a > b) swap(a, b);
        if(existed[make_pair(a, b)]) continue;
        d[a + 1]--, d[b]++;
        existed[make_pair(a, b)] = true;
    }
    
    for(int i = 1; i <= n; i++){
        c[i] = c[i - 1] + d[i];   //求 d[]的前缀和
        cout << h + c[i] << endl;
    }
    
    return 0;
}