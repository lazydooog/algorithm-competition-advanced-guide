/*
* @Description: 139. 回文子串的最大长度
* @Author: Xiaobin Ren
* @Date:   2020-07-29 13:06:19
* @Last Modified time: 2020-07-29 13:06:28
*/
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
typedef unsigned long long ull;

const int N = 2000010, base = 131;   //加入#所以长度×2
ull hl[N], hr[N], p[N];  // h[l] 正序 h[l]逆序
char str[N];

ull get(ull hash[], int l , int r){
    return hash[r] - hash[l - 1] * p[r - l + 1];
}

int main(){
    int t = 1;
    while(scanf("%s", str + 1), strcmp(str + 1, "END")){
         int n = strlen(str + 1);
        for(int i = 2 * n; i > 0; i -= 2){
            str[i] = str[i/2];  //拉伸
            str[i - 1] = 'z' + 1;  //没有出现过的字符即可
        }
       n *=2; //长度* 2
        p[0] = 1;
        for(int i = 1, j = n; i <= n; i++, j--){  //计算正逆序  哈希值
            hl[i] = hl[i - 1] * base + str[i] - 'a' + 1;
            hr[i] = hr[i - 1] * base + str[j] - 'a' + 1;
            p[i] = p[i - 1] * base;
        }
        
        int res = 0;
        for(int i = 1; i <= n; i++){
            int l = 0, r = min(i - 1, n - i); //二分的最大半径 半径不报括中心元素 
            while(l < r){
                int mid = l + r + 1 >> 1; //当前的半径是 mid 
                if(get(hl, i - mid, i - 1) != get(hr, n - (i + mid) + 1, n - ( i + 1) + 1)) r = mid - 1; //这一步计算下标 hr需要正逆序转换
                else l = mid;
            }
            //字母多一个 则 字母l + 1， 符号 l  总共 2l + 1
            if(str[i - l] <= 'z') res = max(res, l + 1);  // i 是中心元素 i -l 就是子串的边界元素
            else res = max(res, l);
        }
        
        printf("Case %d: %d\n", t++, res);
    }
    
    return 0;
}