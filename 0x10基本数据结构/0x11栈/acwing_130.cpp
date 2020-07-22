/*
* @Description: 130. 火车进出栈问题
* @Author: Xiaobin Ren
* @Date:   2020-07-22 15:13:26
* @Last Modified time: 2020-07-22 15:14:27
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

const int N = 600010;
int n;
int powers[N];  //每个质因子的次数
int  primes[N], cnt;  //筛质数
bool st[N]; 

void get_primes(int n){
    for(int i = 2; i <= n; i++)
       if(!st[i]){
            primes[cnt++] = i; //没有被筛过 就是质数 
            for(int j = i * 2; j <= n; j+=i)
                st[j] = true;
       }
}

int get(int n ,int p){  //返回 n! 里有多少个质因子p
    int s = 0;
    while(n){
        s += n / p;
        n /= p;
    }
    return s;
}
//高精度+压位   不压会TLE
void mul(vector<int> & a, int b){
    int t = 0;
    for(int i = 0; i < a.size(); i++){
        a[i]  = a[i] * b + t;
        t = a[i] / 10000;
        a[i] %= 10000;
    }
    while(t){
        a.push_back(t % 10000);
        t /= 10000;
    }
}

void out(vector<int> & a){
    cout << a[a.size() - 1];
    for(int i = a.size() - 2; i >= 0; i--) printf("%04d", a[i]);
    cout << endl;
}

int main(){
    cin >> n;
    get_primes(n * 2);  // 返回1 ~ 2n 所有的质数
    for(int i = 0; i < cnt; i++){  //统计次数
       int p = primes[i]; 
       powers[p] = get(n * 2, p) - get(n, p) * 2;   // 分子(2n)! 分母(n!)*(n!)
    }
    
    //把n + 1 分解质因数 最后
    int k = n + 1;
    for(int i = 0; i < cnt && primes[i] <= k; i++){
        int p = primes[i], s = 0;
        while(k % p == 0){
            s ++;
            k /= p;
        }
        powers[p] -= s;
    }
    
    vector<int> res;
    res.push_back(1); //最后高精度相乘处理答案
    
    for(int i = 2; i <=n * 2 ; i++)
        for(int j = 0; j < powers[i]; j++)
            mul(res, i); //powers[i] == 0 时候就是相当于乘1
            
    out(res);
    
    return 0;
        
}
