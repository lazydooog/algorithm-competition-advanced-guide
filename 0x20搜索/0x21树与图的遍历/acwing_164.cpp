/*
* @Description: 164. 可达性统计
* @Author: Xiaobin Ren
* @Date:   2020-08-01 17:21:19
* @Last Modified time: 2020-08-01 21:47:22
*/
#include <iostream>
#include <algorithm>
#include <cstring>
#include <bitset>
#include <queue>
using namespace std;

//拓扑排序

const int N = 30010;

int n,m;
int h[N], e[N], ne[N], idx;
int d[N], seq[N];
bitset<N> f[N];

void add(int a, int b){
    e[idx] = b; ne[idx] = h[a], h[a] = idx++;
}

void topsort(){
    queue<int> q;
    for(int i = 1; i<=n; i++)
        if(!d[i]) q.push(i);
    int k = 0;
    while(q.size()){
        int t = q.front();
        q.pop();
        
        seq[k ++] = t; //储存排序后的序列
        for(int i = h[t]; ~i; i = ne[i]){
            int j = e[i];
            if(-- d[j] == 0) q.push(j);
        }
    }
}

int main(){
    cin >> n >> m;
    memset(h ,-1, sizeof h);
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        d[b] ++;  // b点的入度加一
        add(a, b);
    }
    
    topsort();
    
    for(int i = n - 1; ~i; i--){ //从末尾开始 
        int j = seq[i];  //拓扑序列的点 开始往后走
        f[j][j]  = 1; //自己可到达自己
        for(int p = h[j]; ~p; p = ne[p])
            f[j] |= f[e[p]];  //e[p] 代表这条边指向的点  求并集
    }
    
    for(int i = 1; i <= n; i++) cout << f[i].count() << endl;
}


