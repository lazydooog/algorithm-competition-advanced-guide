/*
* @Description: 141. 周期
* @Author: Xiaobin Ren
* @Date:   2020-07-30 11:15:25
* @Last Modified time: 2020-07-30 11:15:35
*/
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int N = 1000010;
int n;
char str[N];
int Next[N];

void get_next(){ //kmp模板
    for(int i = 2, j = 0; i <= n; i++){
        while(j && str[i] != str[j + 1]) j = Next[j];
        if(str[i] == str[j + 1]) j++;
        Next[i] = j;
    }
}
//最短循环节长度 就是 i - next[i]  个数就为 i / (i - next[i])
int main(){
    int t = 1;
    while(scanf("%d", &n), n){
        scanf("%s", str + 1);
        get_next();
        printf("Test case #%d\n", t++);
        for(int i = 2; i <= n; i++){
            int t = i - Next[i];
            if(t != i && i % t == 0) printf("%d %d\n", i, i / t);
        }
        puts("");
    }
    return 0;
}