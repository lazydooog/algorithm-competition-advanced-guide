/*
* @Description: 168. 生日蛋糕
* @Author: Xiaobin Ren
* @Date:   2020-08-03 21:02:03
* @Last Modified time: 2020-08-03 21:02:28
*/

#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 25, INF = (int)1e9;
int ans = INF;

int n, m;
int R[N], H[N]; 
int minv[N], mins[N]; //存储前i层面积最小是多少

void dfs(int u, int v, int s){ //正在搜第u层 以及当前的体积和表面积
    //剪枝
    if(v + minv[u] > n) return;
    if(s + mins[u] >= ans) return ;
    if(s + 2 * (n - v) / R[u + 1] >= ans) return ;
   
    if(!u) {
        if(n == v) ans = s; //第一层 自下而上 出口是第一层
        return ;
    }

    for(int r = min((int)sqrt(n - v), R[u + 1] - 1); r >= u; r-- )
        for(int h = min((n - v) / r / r, H[u + 1] - 1); h >= u; h--){
            int t  = 0;
            if(u == m) t = r * r;  // 上部俯视的面积
            R[u] = r, H[u] = h;
            dfs(u - 1, v + r * r * h, s + 2 * r * h + t);
        }
}

int main(){
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        minv[i] = minv[i - 1] + i * i * i; //可行性剪枝 r * r * h;  h r 同步1，2，3递增
        mins[i] = mins[i - 1] + 2 * i * i;  //s  = 2* pi * r * h
    }
    R[m + 1] = H[m + 1] = INF; //边界
    dfs(m, 0, 0);  //第二维是体积 三维是面积 从第m层从下而上dfs
     if (ans == INF) ans = 0;
    cout << ans << endl;
    return 0;
}
