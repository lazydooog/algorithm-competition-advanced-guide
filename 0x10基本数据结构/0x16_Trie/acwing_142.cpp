/*
* @Description: 142. 前缀统计
* @Author: Xiaobin Ren
* @Date:   2020-07-30 22:33:53
* @Last Modified time: 2020-07-30 22:34:01
*/
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int N = 1000010, M = 5000010;

int n, m;
int son[N][26], cnt[N];  //cnt储存 单词结尾的个数 trie 有 N 个节点
int idx;  //虚拟内存指针
char str[N];

void insert(){
    int p = 0;  //根节点 0 号
    for(int i =0; str[i]; i++){
        int &s  = son[p][str[i] - 'a'];
        if(!s) s = ++idx;
        p = s;
    }
    cnt[p] ++;
}

int query(){
    int p = 0, res  = 0;
    for(int i = 0; str[i]; i++){
        int &s = son[p][str[i] - 'a'];
        if(!s) break;
        p = s;
        res += cnt[p];
    }
    return res;
}

int main(){
     scanf("%d%d", &n, &m);
     while(n --){
         scanf("%s", str);
         insert();
     }
     while(m --){
         scanf("%s", str);
         printf("%d\n", query());
     }
    return 0;
}