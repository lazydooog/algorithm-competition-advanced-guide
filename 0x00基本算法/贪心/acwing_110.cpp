/*
* @Description: 110. 防晒
* @Author: Xiaobin Ren
* @Date:   2020-07-14 10:38:02
* @Last Modified time: 2020-07-14 17:26:24
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


const int N = 2510;
PII cows[N];
int n,m;

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> cows[i].first >> cows[i].second;
    sort(cows, cows + n);
    
    map<int, int> spfs;
    for(int i = 0; i < m; i++){
        int spf, cover;
        cin >> spf >> cover;
        spfs[spf] += cover;   //这里要用 + ，可能有先相同的 spf 值
        
    }
    
    int res = 0;
    for(int i = n - 1; i >=0; i--){
        auto cow = cows[i];
        auto it = spfs.upper_bound(cow.second);
        it -- ;
        if(it->first >= cow.first && it->first <= cow.second){
            res ++;
            if(-- it->second == 0) spfs.erase(it);
        }
        
    }
    cout << res << endl;
    return 0;
}

























