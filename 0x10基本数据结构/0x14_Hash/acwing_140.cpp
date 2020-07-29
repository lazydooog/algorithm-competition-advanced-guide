/*
* @Description: 140. 后缀数组
* @Author: Xiaobin Ren
* @Date:   2020-07-29 23:30:30
* @Last Modified time: 2020-07-29 23:30:42
*/
#include <iostream>
#include <algorithm>
#include <cstring>
#include <climits>
using namespace std;
typedef unsigned long long ull;
const int N = 300010, base = 131;
char str[N];
int n;
ull h[N], p[N];
int sa[N];
//先字符串哈希 二分求最长前缀 然后比较最长前缀的下一个字母即可比较串的字典序大小
//排序nlogn  二分比较log  复杂度nlogn * logn  

ull get(int l, int r){
    return h[r] - h[l - 1] * p[r - l + 1];
}

int get_max_common(int a, int b){  //求最长公共前缀长度  a b 是下标
    int l = 0, r = min(n - a + 1, n - b + 1);
    while(l < r){
        int mid = l + r + 1 >> 1;
        if(get(a, a + mid - 1) != get(b, b + mid - 1)) r = mid - 1;  //哈希值不等于说明太长了 缩短比较
        else l = mid;
    }
    return l;  //return r 也可
}

bool cmp(int a, int b){  // a b 是下标  字典序比较函数
    int l = get_max_common(a, b);  //最长前缀长度
    int av = a + l > n ? INT_MIN : str[a + l]; //如果最长公共前缀后一位为空 那么就设为无穷小比较即可
    int bv = b + l > n ? INT_MIN : str[b + l];
    
    return av < bv;
}

int main(){
    scanf("%s", str + 1);
    n = strlen(str + 1);
    p[0] = 1;
    for(int i = 1; i <= n; i++){
        h[i] = h[i - 1] * base + str[i] - 'a' + 1;
        p[i] = p[i - 1] * base;
        sa[i] = i;
    }
    
    sort(sa + 1, sa + n + 1, cmp);  //注意求哈希的下标从一开始 最后答案减掉一即可
    
    for(int i = 1; i <= n; i++) printf("%d ", sa[i] - 1);  //后缀数组从0开始
    puts("");
    
    for(int i = 1; i <= n; i++)  //height 数组
        if(i == 1) printf("0 ");   //第一个返回0
        else printf("%d ", get_max_common(sa[i-1], sa[i]));
        
    return 0;
    
}