/*
* @Description: 133. 蚯蚓
* @Author: Xiaobin Ren
* @Date:   2020-07-26 12:33:09
* @Last Modified time: 2020-07-26 12:33:17
*/
#include <iostream>
#include <algorithm>
#include <queue>
#include <climits>

typedef long long ll;
using namespace std;

const int N = 1e5 + 10, M = 7 * 1000000 + 10;
int n,m,q,u,v,t;
int q1[N], q2[M],q3[M];
int hh1, hh2, hh3, tt1, tt2 = -1, tt3 = -1;
int delta;  //偏移量

int get_max(){
    int x = INT_MIN;
    if(hh1 <= tt1) x = max(x, q1[hh1]);
    if(hh2 <= tt2) x = max(x, q2[hh2]);
    if(hh3 <= tt3) x = max(x, q3[hh3]);
    if(hh1 <= tt1 && x == q1[hh1]) hh1 ++;
    else if(hh2 <= tt2 && x == q2[hh2]) hh2 ++;
    else hh3 ++;
    
    return x;
}

int main(){
    cin >> n >> m>> q >> u >> v >> t;
    for(int i = 0; i < n; i++) cin >> q1[i];
    sort(q1, q1 + n); reverse(q1, q1 + n);
    tt1 = n - 1;
    
    for(int i = 1; i <= m; i++){
        int x= get_max();
        x += delta;
        int left = x * 1ll * u/v ;
        int right = x - left;
        if(i % t == 0) cout << x << ' ';
         
        delta += q;
        q2[++tt2] = left - delta;
        q3[++tt3] = right - delta;
    }
    cout << endl;
    
    for(int i = 1; i <= m + n; i++){
        int x = get_max();
        if(i % t == 0) cout << x + delta << ' ';
    }
    cout << endl;
    
    return 0;
}


