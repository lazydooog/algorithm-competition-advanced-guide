/*
* @Description: 136. 邻值查找
* @Author: Xiaobin Ren
* @Date:   2020-07-27 10:57:20
* @Last Modified time: 2020-07-27 10:57:30
*/
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
const int N = 100010;
pii a[N], ans[N];
int p[N];  // 第n个点在链表中的位置
int l[N], r[N]; //前驱和后继
int n;

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a + 1, a + 1 + n);
    a[0].first = 1e9, a[n+1].first = -1e9;
    for(int i = 1; i <= n; i++){  //建立链表
        l[i] = i - 1, r[i] = i + 1;
        p[a[i].second] = i;  //原始节点在排序后链表中的位置
    }
    for(int i = n; i > 1; i--){
        int j = p[i], left = l[j], right = r[j];
        int lv = abs(a[j].first - a[left].first);
        int rv = abs(a[j].first - a[right].first);
        if(lv <= rv) ans[i] = {lv,a[left].second};
        else ans[i] = {rv, a[right].second};
       // else ans[i] = {lv,min(a[left].second, a[right].second)};
        
        r[left] = right, l[right] = left;  //删除节点
    }
    
    for(int i = 2; i <= n; i++) cout << ans[i].first << ' ' << ans[i].second << endl;
    
    return 0;
}

