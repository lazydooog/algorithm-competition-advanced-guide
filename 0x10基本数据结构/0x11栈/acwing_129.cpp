/*
* @Description: 129. 火车进栈
* @Author: Xiaobin Ren
* @Date:   2020-07-21 22:12:18
* @Last Modified time: 2020-07-21 22:12:30
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

int n, cnt = 20;
vector<int> state1;
stack<int> state2;
int state3 = 1;

void dfs(){
    if(!cnt) return;
    if(state1.size() == n){
        cnt--; //只输出前20个 要加一个计数器
        for(auto x : state1) cout << x;
        cout << endl;
        return;
    }
    if(state2.size()){
        state1.push_back(state2.top());
        state2.pop();
        dfs();
        state2.push(state1.back());
        state1.pop_back();
        
    }
    
    if(state3 <= n){
        state2.push(state3);
        state3 ++;
        dfs();
        state3 --;
        state2.pop();
    }
}

int main(){
    
    cin >> n;
    dfs();
    
    return 0;
    
}

