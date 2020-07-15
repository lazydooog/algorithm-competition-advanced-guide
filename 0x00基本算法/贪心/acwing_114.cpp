/*
* @Description: 114. 国王游戏
* @Author: Xiaobin Ren
* @Date:   2020-07-15 10:53:46
* @Last Modified time: 2020-07-15 10:58:35
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

int n; PII ps[N];  //储存大臣左右手金额

vector<int> mul(vector<int> & a, int b){  //得到的结果是逆序
    vector<int> c;
    int t = 0;
    for(int i = 0; i < a.size() || t; i++){
        if (i < a.size()) t += a[i] * b;
        c.push_back(t % 10);
        t /= 10;
    }
    
    return c;
}

vector<int> div (vector<int> &a, int b){  //返回逆序答案
    vector<int> c;
    int r = 0;  //余数
    for(int i = a.size() - 1; i >=0; i--){
        r = r * 10 + a[i];
        c.push_back(r/b);
        r %= b;
    }
    
    reverse(c.begin(), c.end());
    while(c.size() > 1 && c.back() == 0) c.pop_back();
    return c;
}

vector<int> max_vec(vector<int> a, vector<int> b){  //返回逆序较大的一个vector，不能使用默认的vector比较，那个是字典序
    if(a.size() > b.size()) return a;
    if(a.size() < b.size()) return b;
    if(vector<int>(a.rbegin(), a.rend()) > vector<int>(b.rbegin(), b.rend())) return a;  //逆序比较.传进来的是逆序的
    
    return b;
}

int main(){
    cin >> n;
    for(int i = 0; i <= n; i++){
        int a, b;
        cin >> a >> b;  //加上国王一共是 n + 1 个人
        ps[i] = {a * b, a};
    }
    sort(ps+1, ps + n+ 1);  //国王不参与排序
    
    vector<int> product(1,1);  //用vector来存储大数
    vector<int> res(1,0);
    
    for(int i = 0; i <= n; i++){
        if(i) res = max_vec(res, div(product, ps[i].first / ps[i].second));
        product = mul(product, ps[i].second); //注意 第一次循环 只有一个元素 1 返回之后的vector就是逆序的了
        //之后参与乘除的vector全都是逆序传入高精度乘除函数
    }
    
    for(int i = res.size()-1; i >=0; i--) cout << res[i];
    cout << endl;
    
    
    return 0;
}



