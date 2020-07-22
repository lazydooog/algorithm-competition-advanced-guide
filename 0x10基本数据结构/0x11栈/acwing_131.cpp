/*
* @Description: 131. 直方图中最大的矩形
* @Author: Xiaobin Ren
* @Date:   2020-07-22 21:33:30
* @Last Modified time: 2020-07-22 21:33:38
*/
#include <iostream>
#include <stack>
#include <algorithm>

typedef long long ll;

using namespace std;

const int N = 1e5 + 10;
int n;
int h[N], q[N], l[N], r[N];

void get(int bound[N]){ //得到边界
    int tt = 0;
     h[0] = -1;  //处理边界 栈底一定不会弹出
     for(int i = 1; i <= n; i++){
         while(h[q[tt]] >= h[i]) tt--;
         bound[i] = q[tt];
         q[++tt] = i;
     }
     
}

int main(){
    while(cin >> n, n){
        for(int i = 1; i <= n; i++) cin >> h[i];
        //得到左右边界 扫2遍 和原书做法不一样
        get(l);
        reverse(h + 1, h + 1 + n);
        get(r);
        
        ll res = 0;
        for(int i = 1, j = n; i <= n; i++, j--)
            res = max(res, h[i] * (n + 1 - l[j] - r[i] - 1ll));
            
    cout << res << endl;
    
    }
    
    return 0;
}