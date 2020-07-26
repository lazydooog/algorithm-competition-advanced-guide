/*
* @Description: 135. 最大子序和
* @Author: Xiaobin Ren
* @Date:   2020-07-26 16:03:47
* @Last Modified time: 2020-07-26 16:03:55
*/
#include <iostream>

#include <climits>
using namespace std;
typedef long long ll;

//这题也叫滑动窗口 

const int N = 300010;
int q[N];  //单调队列下标
ll s[N]; //前缀和
int n, m;

int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++ ){
        cin >> s[i];
        s[i] += s[i - 1];
    }
    int hh = 0, tt = 0;  //队头 队尾
    
    ll res = INT_MIN;
    for(int i = 1; i <= n; i++){
        if(i - q[hh] > m) hh++;
        res = max(res, s[i] - s[q[hh]]);
        while(hh <= tt && s[q[tt]] >= s[i]) tt--;
        q[++tt] = i; //队尾下标
    }
    
    cout <<res << endl;
    
    return 0;
}

