/*
* @Description: 147. 数据备份
* @Author: Xiaobin Ren
* @Date:   2020-07-31 21:36:01
* @Last Modified time: 2020-07-31 21:36:08
*/
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <set>
using namespace std;

//最优子结构性质 连续选中的边和未选的边 同时选 或者同时不选 共进退
typedef long long ll;
typedef pair<ll, int> pii;
const int N = 100010;
int n, k;
int l[N], r[N];  //双链表 左指针 右指针
ll d[N];   //存储 

void delete_node(int p){
    r[l[p]] = r[p];
    l[r[p]] = l[p];
}

int main(){
    cin >> n >> k;
    for(int i = 0; i < n; i++) cin >> d[i];
    for(int i = n - 1; ~i; i--) d[i] -= d[i - 1];
   // priority_queue<pii, vector<pii>, greater<pii> > heap
    d[0] = d[n] = 1e15;
    set<pii> s;
    for(int i = 0; i <= n; i++){
        l[i] = i - 1, r[i] = i + 1;
        if(i >= 1 && i < n)  s.insert({d[i], i});
    }
    
    ll res = 0;
    while(k --){
       auto it = s.begin();
       ll v = it -> first;
       int p = it -> second, left = l[p], right = r[p];
       s.erase(it);
       s.erase({d[left], left}) ,s.erase({d[right], right});
       delete_node(left), delete_node(right);
       
       res += v;
       
       d[p] = d[left] + d[right] - d[p];
       s.insert({d[p], p});
    }
    
    cout << res << endl;
    
    return 0;
}