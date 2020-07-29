/*
* @Description: 137. 雪花雪花雪花
* @Author: Xiaobin Ren
* @Date:   2020-07-28 23:50:11
* @Last Modified time: 2020-07-29 09:24:24
*/
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 100010;
int n;
int snows[N][6], idx[N];

//顺序 反转之后 求2个最小表示 然后取小  就是最小表示
//求最小表示 复制一遍 然后 双指针 复杂度 线性


bool cmp_array(int a[], int b[]){   //比较字典序
    for(int i = 0; i < 6; i++)
        if(a[i] > b[i]) return false;
        else if(a[i] < b[i]) return true;
    return false;  //相等
}


bool cmp(int a, int b){
    return cmp_array(snows[a], snows[b]);
}


void get_min(int a[]){//字符串最小表示
    static int b[12];
    for(int i = 0; i < 12; i++) b[i] = a[i % 6];  //a数组复制2次 到b数组
    int i = 0, j = 1, k;
    while(i < 6  && j < 6){
        for( k = 0; k < 6 && b[i + k] == b[j + k]; k++);
        if(k == 6) break;
        if(b[i + k] > b[j + k]){
            i += k + 1;
            if(i == j) i ++;
        }else{
            j += k + 1;
            if(i == j) j ++;
        }
        
    }
    
    k = min(i, j);
    for(int i = 0; i < 6; i++) a[i] = b[i + k];
}

int main(){
    scanf("%d", &n);
    int snow[6], isnow[6];  //  isnow 储存逆序
    for(int i = 0; i < n; i++){
        for(int j = 0, k = 5; j < 6; j++, k--){
            scanf("%d", &snow[j]);
            isnow[k] = snow[j];
        }
       get_min(snow);
       get_min(isnow);
       if(cmp_array(snow, isnow)) memcpy(snows[i], snow, sizeof snow);
       else memcpy(snows[i], isnow, sizeof isnow);
       
       idx[i] = i;  //二维数组索引 用来排序 前提定义了数组排序的函数
    }
    sort(idx, idx + n, cmp);
    
    bool flag = false;
    for(int i  = 1 ; i < n; i++)
        if(!cmp(idx[i - 1], idx[i]) && !cmp(idx[i], idx[i - 1])){  //数组字典序相等
            flag = true;   //找到相同序列 字典序一样
            break;
        }
        
    if(flag) cout << "Twin snowflakes found." << endl;
    else cout << "No two snowflakes are alike." << endl;
    
    return 0;
}




