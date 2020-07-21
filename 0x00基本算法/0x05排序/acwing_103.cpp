/*
* @Description: 103. 电影
* @Author: Xiaobin Ren
* @Date:   2020-07-12 12:30:21
* @Last Modified time: 2020-07-12 19:06:17
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
map<int, int> s;
int a[N];

struct scientist{
    int a, b;
}p[N];

int main(){
    int n, m;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);  //科学家的语言
        s[a[i]] ++;  //map记录
    }
    
    scanf("%d", &m);
    for(int i = 1; i <= m; i++) scanf("%d", &p[i].a); //语音
    for(int i = 1; i <= m; i++) scanf("%d", &p[i].b); //字幕
    
    
    int max1 = 0, cur = 1; //cur记录最大元素的下标
    for(int i = 1; i <= m; i++){
        if(max1 < s[p[i].a]){
            max1 = s[p[i].a];
            cur = i;
        }
    }
    //语音相同的情况下比较字幕的大小
    int max2 = 0;
    for(int i = 1; i <= m; i++){
        if(s[p[i].a] == max1){
            if(max2 < s[p[i].b]){
                max2 = s[p[i].b];
                cur = i;
            }
        }
    }
    
    printf("%d", cur);
    
    return 0;
    
}