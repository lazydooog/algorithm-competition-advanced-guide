/*
* @Description: 146. 序列
* @Author: Xiaobin Ren
* @Date:   2020-07-31 14:54:28
* @Last Modified time: 2020-07-31 14:54:34
*/
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;
typedef pair<int, int> pii;
const int N = 2010;
int m, n;
int a[N], b[N], c[N];  //c是归并后的数组

void merge(){
    priority_queue<pii, vector<pii>, greater<pii> > heap;
    for(int i = 0; i < n; i++) heap.push({a[0] + b[i], 0});
    
    for(int i = 0; i < n; i++){
        auto t = heap.top();
        heap.pop();
        int s = t.first, p = t.second;
        c[i] = s;  //存储堆顶 也就是答案
        heap.push({s - a[p] + a[p + 1], p + 1});
    }
    
    for(int i = 0; i < n; i++) a[i] = c[i];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t; cin >> t;
    while(t --){
        cin >> m >> n;
        for(int i = 0; i < n; i++) cin >> a[i];
        sort(a, a + n);
        for(int i = 0; i < m - 1; i++){ //合并剩下的 m - 1 行 
            for(int j = 0; j < n; j++) cin >> b[j];
            merge();
        }
        
        for(int i = 0; i < n; i++) cout << a[i] << ' ';
        cout << endl;
    }
    
    return 0;
}

