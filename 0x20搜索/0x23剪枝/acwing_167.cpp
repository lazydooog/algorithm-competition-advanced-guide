/*
* @Description: 167. 木棒
* @Author: Xiaobin Ren
* @Date:   2020-08-03 16:22:37
* @Last Modified time: 2020-08-03 18:11:30
*/
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 64;
int sticks[N];  //存储所有的木棒
bool st[N];  //标记用过没有
int n,sum, length; // sum 所有木棒总和  length 当前木棒的长度

bool dfs(int u, int cur, int start){ // 第一个参数 已经拼好的原始木棍的个数 第二个是当前木棍已经拼好的长度 第三个是枚举木棍的下标（已经排序）
    if(u * length == sum) return true;
    if(cur == length) return dfs(u + 1, 0, 0);
    
    for(int i = start; i < n; i++){
        if(st[i]) continue;
        int l = sticks[i];
        if(cur + l > length) continue;
        
        st[i] = true;
        if(dfs(u, cur + l, i + 1)) return true;
        st[i] = false;  
        
        if(!cur) return false;  //第一个木棍不成立 剪枝
        if(cur + l == length) return false;  //最后一个不成立
        
        //剪枝 跳过所有相同木棍
        int j = i;
        while(j < n && sticks[j] == l) j ++; 
        i = j - 1;
    }
    
    return false;
}

int main(){
    while(cin >> n, n){
        sum = 0, length = 0;  //初始化 
        for(int i = 0; i < n; i++){
            int l; 
            cin >> l;
            sticks[i] = l;
            if(l > 50)continue;
            //sticks[i] = l;
            
            sum += l;
            length = max(length, l);
        }
        sort(sticks, sticks + n);
        reverse(sticks, sticks + n);
        
        memset(st, false, sizeof st);
        for(int i = 0; i < n; i++){
            if(sticks[i] > 50)
                st[i] = true;   //true 表示已经用过 所以就相当于剔除了大于50的木棍
        }
        
        while(1){
            if(sum % length == 0 && dfs(0, 0, 0)){
                cout << length << endl;
                break;
            }
            length ++;
        }
    }
    
    return 0;
}