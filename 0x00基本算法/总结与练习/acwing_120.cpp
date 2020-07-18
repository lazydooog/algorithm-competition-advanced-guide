/*
* @Description:120. 防线
* @Author: Xiaobin Ren
* @Date:   2020-07-18 12:04:26
* @Last Modified time: 2020-07-18 12:05:22
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

const int N = 200010;

struct seq{
    int s, e, d;
}seqs[N];

int n;

ll get_sum(int x){
    ll res = 0;
    for(int i = 0; i < n ;i ++)
        if(seqs[i].s <= x) res += (min(seqs[i].e, x) - seqs[i].s) / seqs[i].d + 1;
    return res;
}


int main(){
    
    int t;
    scanf("%d", &t);
    while(t--){
        int l = 0, r = 0;
        scanf("%d", &n);
        for(int i = 0; i < n; i++){
            int s, e,d;
            scanf("%d%d%d", &s, &e, &d);
            seqs[i] = {s,e,d};
            r = max(r, e); //求出最大右边界 用于二分
        }
        while(l < r){
            int mid = l + r >> 1;
            if (get_sum(mid) & 1) r = mid;   //小于等于mid的数的个数是奇数
            else l = mid + 1;
        }
        
        auto sum = get_sum(r) - get_sum(r - 1);  //此时的r已经是答案的位置坐标
        if(sum & 1) cout << r << ' ' << sum << endl;
        else cout << "There's no weakness." << endl;
    }
    
    return 0;
}
