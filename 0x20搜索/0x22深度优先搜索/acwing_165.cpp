/*
* @Description: 165. 小猫爬山
* @Author: Xiaobin Ren
* @Date:   2020-08-01 23:50:07
* @Last Modified time: 2020-08-01 23:50:22
*/
#include <iostream>
#include <stack>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 20;
int n, m;
int cat[N], sum[N];
int ans = N;  //最坏的答案

//按照重量排序 优先考虑重的🐱
void dfs(int u, int k){  // u是当前的猫 k 车的数量
    if(k >= ans) return ; 
    if(u == n){
        ans = k;
        return;
    }
    for(int i = 0; i < k; i++)
        if(cat[u] + sum[i] <= m){
            sum[i] += cat[u];
            dfs(u + 1, k);
            sum[i] -= cat[u];
        }
        
    sum[k] = cat[u]; //加入新车
    dfs(u + 1, k + 1);
    sum[k] = 0;  //恢复现场
}

int main(){
    
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> cat[i];
    sort(cat, cat + n);
    reverse(cat, cat + n);
    dfs(0 ,0);
    
    cout << ans << endl;
    
    return 0;
}