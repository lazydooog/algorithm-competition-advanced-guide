/*
* @Description: 144. 最长异或值路径
* @Author: Xiaobin Ren
* @Date:   2020-07-31 11:11:57
* @Last Modified time: 2020-07-31 11:12:04
*/
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 100010, M  = 3000010;

int n;
int h[N], e[N * 2], c[N * 2], ne[N*2],cnt;  // 链式前向星  cnt 内存指针
int son[M][2], idx; //注意对于son数组 第一维要开总共的节点个数 
int a[N];

//此题略有贪心思路： 从最高位开始寻异或 原因是低位对于数大小的贡献 远小于高位 数大小由高位决定

void add(int u, int v, int w){
    e[cnt] = v, c[cnt] = w, ne[cnt] = h[u], h[u] = cnt ++;
}

void dfs(int u, int father, int sum){
    a[u] = sum;
    for(int i = h[u]; ~i; i = ne[i]){
        int j = e[i];
        if(j != father) dfs(j, u, sum ^ c[i]);
    }
}

void insert(int x){
    int p = 0;
    for(int i = 30; ~i ; i --){  //从高位到低位存 所以逆着来
        int &s = son[p][x >> i & 1];  // >> i 是第 i + 1 位  所以循环最大30
        if(!s) s = ++idx;
        p = s;
    }
}

int query(int x){
    int res = 0, p = 0;
    for(int i = 30; ~i; i--){
        int s = x >> i & 1;
        if(son[p][!s]){
            res += 1 << i;  //该位对于答案的贡献 
            p = son[p][!s];
        }else p = son[p][s]; //不存在不同的值 就只能选择相同的二进制位
    }
    
    return res;
}

int main(){
    cin >> n;
    memset(h, -1, sizeof h );
    for(int i = 0; i < n; i++){
        int u, v, w;
        cin >> u >> v >> w;
        add(u, v, w);
        add(v, u, w);  //无向图加2遍
    }
    
    dfs(0, -1, 0);
    
    for(int i = 0; i < n; i++) insert(a[i]);
    
    int res = 0;
    for(int i = 0; i < n ;i++) res = max(res, query(a[i]));
    cout << res << endl;
    
    return 0;
}