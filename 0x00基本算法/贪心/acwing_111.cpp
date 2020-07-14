/*
* @Description: 111. 畜栏预定
* @Author: Xiaobin Ren
* @Date:   2020-07-14 17:32:45
* @Last Modified time: 2020-07-14 21:11:31
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

typedef pair<int , int> PII;
const int N = 50010;
int n;  
pair<PII,int> cows[N];
int id[N];

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
      cin >> cows[i].first.first >> cows[i].first.second;
      cows[i].second = i;
    }
    sort(cows, cows + n);
    priority_queue <PII, vector<PII>, greater<PII> > heap;
    for(int i = 0; i < n; i++){
        auto cow = cows[i].first;
        //注意堆顶存放的是结束时间最早的一个栏，如果连结束时间最早的都不能插入，那么只能新建
        if(heap.empty() || heap.top().first >= cow.first){   //新建一个栏
            PII stall = {cow.second,heap.size() + 1};  //编号从1开始 注意题目
            id[cows[i].second] = stall.second;
            heap.push(stall);
        }
        else{    //插入当前栏中，然后更新堆顶 也就是最早结束的
            auto stall = heap.top();
            heap.pop();
            stall.first = cow.second;
            id[cows[i].second] = stall.second;
            heap.push(stall);
        }
   
    }
     
    cout << heap.size() << endl;
    for(int i = 0; i < n; i++) cout << id[i] << endl;
    
    
    return 0;
}






