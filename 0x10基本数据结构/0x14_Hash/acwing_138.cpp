/*
* @Description: 138. 兔子与兔子
* @Author: Xiaobin Ren
* @Date:   2020-07-29 11:07:20
* @Last Modified time: 2020-07-29 11:07:27
*/
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
typedef unsigned long long ull;

const int N = 1000010;   //储存每一位哈希的数组 开length长度即可
const int base = 131;
int m; ull p[N], h[N];  //h数组储存哈希值
char str[N];


ull get(int l, int r){
    return h[r] - h[l - 1]*p[r - l + 1];
}

int main(){
    scanf("%s", str + 1);   //从第一位开始存储
    int n = strlen(str + 1);
    
    p[0] = 1; //  base ^ 0 == 1;
    for(int i = 1; i <=n; i++){
        h[i] = h[i - 1] * base + str[i] - 'a' + 1;
        p[i] = p[i - 1] * base;  //预处理base进制数组
    }
    
    scanf("%d", &m);
    while(m --){
        int l1, r1, l2, r2;
        scanf("%d%d%d%d", &l1, &r1, &l2, &r2);
        if(get(l1, r1) == get(l2, r2)) puts("Yes");
        else puts("No");
    }
    
    return 0;
}