/*
* @Description: 145. 超市
* @Author: Xiaobin Ren
* @Date:   2020-07-31 13:58:47
* @Last Modified time: 2020-07-31 13:58:55
*/
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;
typedef pair<int, int> pii;

int main(){
    int n;
   
    while(cin >> n){
        vector<pii> p(n);
        for(int i = 0; i < n; i++) cin >> p[i].second >> p[i].first;
        
        
    sort(p.begin(), p.end());
    
   
    
    priority_queue<int, vector<int>, greater<int> > heap;
    
    for(auto x : p){
        heap.push(x.second);
        if(heap.size() > x.first) heap.pop();
    }
    
    int res = 0;
    while(heap.size()) res += heap.top(), heap.pop();
    
    cout << res << endl;
        
    }
    
    return 0;
}