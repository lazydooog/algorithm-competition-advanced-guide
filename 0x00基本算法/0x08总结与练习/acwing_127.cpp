/*
* @Description: 127.任务
* @Author: Xiaobin Ren
* @Date:   2020-07-20 23:15:44
* @Last Modified time: 2020-07-21 13:15:43
*/
#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for(int i = a; i< n; i++)
#define per(i,a,n) for(int i=n-1; i>=a; i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define sz(x) ((int)(x).size())
typedef vector<int> VI;
typedef long long ll;
typedef pair<int, int> PII;
typedef double db;
mt19937 mrand(random_device{}());
const ll mod = 1000000007;
int rnd(int x) { return mrand() % x;}
ll mulmod(ll a, ll b) {ll res=0;a%=mod;assert(b>=0);for(;b;b>>=1){if(b&1)res=(res+a)%mod;a=2*a%mod;}return res;}
ll powmod(ll a, ll b) {ll res=1;a%=mod;assert(b>=0);for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a;}
//snippet-head

const int N = 100010;
int n, m;
PII mchs[N], tasks[N];
/*
    贪心思路：将机器和任务都按照 分钟排序
    然后对于每个任务所需时间 ，枚举机器的时间，如果时间符合就全部放入候选
    接着在候选中选出能满足 级别 的最小的一个即可
    
    正确性：对于下一个任务，因为是从大到小枚举任务，当前候选机器的时间已经满足上一个任务，那么肯定满足下一个任务
    所以只需要选择一个恰好的 级别 来满足即可，把较大的级别的机器留给后面的任务 
*/
int main(){
    while(cin >> n >> m){
        for(int i = 0; i < n; i++) cin >> mchs[i].first >> mchs[i].second;
        for(int i = 0; i < m; i++) cin >> tasks[i].first >> tasks[i].second;
        
        sort(mchs, mchs + n); sort(tasks, tasks + m);
        multiset<int> ys;  //存储y
        int cnt = 0; long long  res = 0;
        for(int i = m - 1, j = n - 1; i >= 0; i--){
            int x = tasks[i].first, y = tasks[i].second;
           while(j >= 0 && mchs[j].first >= tasks[i].first) ys.insert(mchs[j--].second); //将符合的全部加入set 然后二分最小的
           auto it = ys.lower_bound(y);
           if(it != ys.end()){
               cnt ++;
               res += 500 * x + 2 * y;
               ys.erase(it);
           }
        }
        cout << cnt << ' ' << res << endl;
    }         
    return 0;
}