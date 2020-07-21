/*
* @Description: 128. 编辑器
* @Author: Xiaobin Ren
* @Date:   2020-07-21 21:15:28
* @Last Modified time: 2020-07-21 21:15:54
*/
#include <iostream>
#include <algorithm>
#include <climits>  
using namespace std;
const int N = 1e6 + 10;

//思路：对顶栈 + 前缀和 + 单个栈维护最小

int stkl[N], stkr[N], tl, tr;
int s[N], f[N];  // s储存左边栈的前缀和，f存储前缀和的最大值

void push_left(int x){
    stkl[++tl] = x;
    s[tl] = s[tl - 1] + x;
    f[tl] = max(f[tl - 1], s[tl]);
}

int main(){
    f[0] = INT_MIN;
    int n ;
    cin >> n;
    while(n --){
        char str[2];
        int x;
        cin >> str;
        if(*str == 'I'){
            cin >> x;
            push_left(x);
        }
        else if(*str == 'D'){
            if(tl > 0) tl --;
        }
        else if(*str == 'L'){
            stkr[++tr] = stkl[tl--];
        }
        else if(*str == 'R'){
            if(tr > 0) push_left(stkr[tr--]);
        }
        else{
            cin >> x;
            cout << f[x] << endl;
        }
    }
    return 0;
}
