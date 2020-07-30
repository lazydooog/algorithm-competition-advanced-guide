/*
* @Description: 143. 最大异或对
* @Author: Xiaobin Ren
* @Date:   2020-07-30 23:27:08
* @Last Modified time: 2020-07-30 23:27:20
*/
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 100010, M  = 3000010;

int n;
int son[M][2], idx; //注意对于son数组 第一维要开总共的节点个数 
int a[N];

//此题略有贪心思路： 从最高位开始寻异或 原因是低位对于数大小的贡献 远小于高位 数大小由高位决定

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
    for(int i = 0; i < n; i++){
        cin >> a[i];
        insert(a[i]);
    }
    int res = 0;
    for(int i = 0; i < n ;i++) res = max(res, query(a[i]));
    cout << res << endl;
    
    return 0;
}