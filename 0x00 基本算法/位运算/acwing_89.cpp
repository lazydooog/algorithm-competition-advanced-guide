/*
* @Description: 89. a^b
* @Author: Xiaobin Ren
* @Date:   2020-05-01 10:46:00
* @Last Modified time: 2020-05-01 12:27:10
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
ll mulmod(ll a, ll b) {ll res=0;a%=mod;assert(b>=0);for(;b;b>>=1){if(b&1)res+=a%mod;a+=a%mod;}return res;}
ll powmod(ll a, ll b) {ll res=1;a%=mod;assert(b>=0);for(;b;b>>=1){if(b&1)res*=a%mod;a*=a%mod;}return res;}
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a;}
//head


#include <iostream>

using namespace std;

typedef long long ll;

ll p;

ll powmod(ll a, ll b){
    ll res = 1;
    a %= p;
    if(b == 0){
        return 1 % p;
    }
    while(b){
        if(b & 1){
            res  = res *a % p;
        }
        b >>= 1;
        a = a * a % p;
    }
    
    return res;
}

int main(){
    ll a,  b;
    cin >> a >> b >> p;
    cout << powmod(a, b);
    
    return 0;
}