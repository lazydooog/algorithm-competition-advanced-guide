/*
* @Description: 132. 小组队列
* @Author: Xiaobin Ren
* @Date:   2020-07-25 23:31:15
* @Last Modified time: 2020-07-25 23:31:25
*/
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

const int N = 1010, M = 1000010;
int teamid[M];


int main()
{
    int n;int count = 0;
    while(cin >> n, n){
         cout << "Scenario #" << ++count << endl;
        
        for(int i = 0; i < n; i++){
            int cnt; cin >> cnt;
            while(cnt --){
                int x;
                cin >> x;
                teamid[x] = i;
            }
        }
        queue<int> team;//储存队列目前所有人已经存在的编号 不重复
        queue<int> person[N]; //储存所有的人
        string command;
        while(cin >> command, command != "STOP"){
            if(command == "ENQUEUE"){
                int x;
                cin >> x;
                int tid = teamid[x];
                if(person[tid].empty()) team.push(tid);
                person[tid].push(x);
            }else{
                int tid = team.front();
               
                auto &q = person[tid];
                cout << q.front() << endl;
                q.pop();
                if(q.empty()) team.pop();
                
            }
        }
         cout << endl;
    }
    
    
    return 0;
}