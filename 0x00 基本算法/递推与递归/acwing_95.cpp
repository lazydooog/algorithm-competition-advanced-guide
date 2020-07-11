/*
* @Description: 95. 费解的开关
* @Author: Xiaobin Ren
* @Date:   2020-07-11 10:55:13
* @Last Modified time: 2020-07-11 13:36:57
*/
#include <iostream>
#include <cstring>

using namespace std;

const int INF = 0x3f3f3f3f;
char g[10][10];
int dx[5] = {0, -1, 0, 1, 0}, dy[5] = {0, 0, 1, 0, -1};

void turn(int x, int y){   //对x，y位置进行操作
    for(int i = 0; i < 5; i++){
        int a = x + dx[i], b = y + dy[i];
        if(a >= 0 && a < 5 && b >= 0 && b <5) g[a][b] ^= 1;
    }
}

int solve(){
    int ans = INF;
    for(int k = 0; k < 1 << 5; k++){
        int res = 0;  //标记答案 最后更新
        char backup[10][10];
        memcpy(backup, g, sizeof g);  
        for(int j = 0; j < 5; j++)
            if(!(k >> j & 1)){   //处理第一行 也可写为 if(k >> j & 1) 
            //其实这行代码的意思就是枚举第一行所有的按法
            //无论是1 是 0也好，因为按后会影响左右的灯。所以只需要指数型枚举32个状态就行。
                res ++ ;
                turn(0, j); 
            }
        for(int i = 0; i < 4; i++)
            for(int j = 0; j < 5; j++)
                if (g[i][j] == '0'){
                    res ++;
                    turn(i + 1, j);
                }
        bool flag = true;
        for(int j = 0; j < 5; j++)
            if (g[4][j] == '0'){
                flag = false;
                break;
            }
        if(flag) ans = min(ans, res);
        
        memcpy(g, backup, sizeof g); // 还原初始数祖，判断下一个样例
    }
    
    if (ans > 6) ans = -1;
    return ans;
}


int main(){
    int t;
    cin >> t;
    while(t--){
        for(int i = 0; i < 5; i++) cin >> g[i];
        cout << solve() << endl;
    }
    
    return 0;
}