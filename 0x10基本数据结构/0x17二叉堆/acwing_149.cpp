/*
* @Description: 149. 荷马史诗
* @Author: Xiaobin Ren
* @Date:   2020-07-31 18:38:56
* @Last Modified time: 2020-07-31 18:39:02
*/
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<ll, int> pii;
int main(){
    int n, k;
    cin >> n >> k;
    
    priority_queue<pii, vector<pii>, greater<pii> > heap;
    for(int i = 0; i < n; i++){
        ll x;
        cin >> x;
        heap.push({x, 0});
    }
    while((n - 1) % (k - 1)) heap.push({0, 0}), n++; //多叉树 不够的补0 
    ll res = 0;
    while(heap.size() > 1){
        ll s = 0;
        int depth = 0;
        for(int i = 0 ; i < k; i++){
            auto t = heap.top();
            s += t.first;
            depth = max(depth, t.second);
            heap.pop();
        }
        res += s;
        heap.push({s, depth + 1});
    }
    
    cout << res <<  endl;
    cout << heap.top().second << endl;
    return 0;
}