/*
* @Description: 
* @Author: Xiaobin Ren
* @Date:   2020-07-14 22:08:51
* @Last Modified time: 2020-07-14 22:11:51
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

typedef pair<double, double> pdd;
const double eps = 1e-6, INF = 1e10;
int n,d;
pdd segs[N];

int main(){
    
    bool flag = true;
    
    cin >> n >> d;
    for(int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        if(y > d){
            flag = false;
            break;
        }
        double len = sqrt(d * d - y * y);
        segs[i] = {x + len, x - len}; //按照终点排序 ，将右端点置为第一关键字
    }
    
    if(!flag) puts("-1");
    else{
        sort(segs, segs + n);
        int res = 0; double last = -INF;  //注意last是double的
        for(int i = 0; i < n; i++){
            auto seg = segs[i];
            if(seg.second > last + eps){  //精度问题，对于double要加上eps ，然而样例不加也能过
                res ++;
                last = seg.first;
            }
        }
        cout << res << endl;
    }
    
    return 0;
}

