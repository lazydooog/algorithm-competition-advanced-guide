/*
* @Description: 90. 64位整数乘法
* @Author: Xiaobin Ren
* @Date:   2020-05-01 13:30:51
* @Last Modified time: 2020-05-01 13:31:10
*/

#include <iostream>

using namespace std;

typedef long long ll;


ll mulmod(ll a, ll b, ll p){
    ll res = 0;
    while(b){
        if(b & 1) res = (res + a) % p;
        b >>= 1;
        a = a*2 % p;
    }
    return res;
}

int main(){
    ll a, b, p;
    cin >> a >> b >> p;
    cout << mulmod(a, b, p) << endl;
    
    return 0;
}