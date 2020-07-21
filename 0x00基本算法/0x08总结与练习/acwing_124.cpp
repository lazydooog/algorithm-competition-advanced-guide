/*
* @Description: 
* @Author: Xiaobin Ren
* @Date:   2020-07-19 23:46:55
* @Last Modified time: 2020-07-19 23:47:07
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


int main(){
    int t; cin>> t;
    while(t --){
        int a, b;
        string aline, bline;
        cin >> a >> b >> aline;
        
        vector<int> number;
        for(auto c : aline){
            if(c >='0' && c <= '9') number.push_back(c - '0');
            if(c >= 'A' && c <= 'Z') number.push_back(c - 'A' + 10);
            if(c >= 'a' && c <= 'z') number.push_back(c - 'a' + 36);
        }
        reverse(number.begin(), number.end());
        
        vector<int> res;
        while(number.size()){
            int r = 0;  //余数
            for(int i = number.size() -  1; i >= 0; i--){  //反着存的 所以要最后一位开始除
                number[i] += r * a;
                r = number[i] % b;
                number[i] /= b;
            }
            res.push_back(r);  //余数存储的顺序是 顺序的
            while (number.size() && number.back() == 0) number.pop_back();  //商的前导0;
        }
        reverse(res.begin(), res.end());  //余数要逆序排列 才是进制转换后的 连着除取余的方法转换进制
        for(auto x : res){
            if (x <= 9) bline += char(x + '0');
            if(x >= 10 && x <= 35) bline += char(x -10 + 'A');
            if(x >= 36) bline += char(x - 36 + 'a');
        }
        
        cout << a << ' ' << aline << endl;
        cout << b << ' ' << bline << endl;
        cout << endl;
    }
    return 0;
}