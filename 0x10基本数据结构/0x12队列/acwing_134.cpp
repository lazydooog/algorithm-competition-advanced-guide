/*
* @Description: 134. 双端队列
* @Author: Xiaobin Ren
* @Date:   2020-07-26 15:22:36
* @Last Modified time: 2020-07-26 15:22:45
*/
#include <iostream>
#include <algorithm>
#include <queue>
#include <climits>

using namespace std;
typedef pair<int, int> pii;
const int N = 200010;
pii a[N];
int n;

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i].first;
        a[i].second = i;   //下标
    }
    
    sort(a, a + n);
    
    int res = 1;  //答案 段数
    int last = INT_MAX;
    
    int dir = -1;  //升降趋势  -1表示下降 初始从正无穷降下来
    for(int i = 0; i < n; ){
        int j = i;
        while(j < n && a[j].first == a[i].first) j++;  //相同的一段
        int minp = a[i].second, maxp = a[j - 1].second;  // 最值下标
        
        if(dir == -1){ //下降趋势
            if(last > maxp) last = minp;
            else dir = 1, last = maxp; 
        }else{  //上升趋势
            if (last < minp) last = maxp;
            else{
                res ++ ;
                dir = -1;
                last = minp;
            }
        }
        i = j;
    }
    
    cout  << res << endl;
    
    return 0;
}