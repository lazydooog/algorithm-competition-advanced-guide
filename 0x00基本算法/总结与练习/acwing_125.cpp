/*
* @Description: 125. 耍杂技的牛
* @Author: Xiaobin Ren
* @Date:   2020-07-20 14:37:14
* @Last Modified time: 2020-07-20 14:38:18
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

const int N = 50050;
typedef pair<int, int> PII;
int n;
PII cows[N];
//思路 贪心 证明：领项交换
//按照w + s 顺序排序
//然后遍历一次取最大值即可
int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        int w,  s;
        cin >> w >> s;
        cows[i]  = {w + s, s};
    }
    sort(cows, cows + n);
    
    int sum = 0, res = INT_MIN;
    for(int i = 0; i < n; i++){
        res = max(res, sum - cows[i].second);
        sum += cows[i].first - cows[i].second;
    }
    
    cout << res << endl;
    return 0;
}