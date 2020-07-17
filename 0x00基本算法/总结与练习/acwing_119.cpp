/*
* @Description: 119. 袭击
* @Author: Xiaobin Ren
* @Date:   2020-07-17 15:05:33
* @Last Modified time: 2020-07-17 23:32:14
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

const int N = 200010;
const double INF = 1e10;
struct Point{
    double x, y;
    bool type;  //区分种类
    bool operator< (const Point &W) const{
        return x < W.x;
    }
}points[N],temp[N];


double get_dist(Point a, Point b){
    if(a.type == b.type) return INF;
    double dx = a.x - b.x, dy = a.y - b.y;
    return sqrt(dx * dx + dy * dy);
}

double  dfs(int l, int r){
    if(l >= r) return INF;
    int mid = l + r >> 1;
    double mid_x = points[mid].x;
    double res = min(dfs(l, mid), dfs(mid + 1, r));
    
    {
        int k = 0, i = l, j = mid + 1;
        while(i <= mid && j <= r)
            if (points[i].y <=points[j].y) temp[k++] = points[i++];
            else temp[k++] = points[j++];
        while(i <= mid) temp[k++] = points[i++];
        while(j <= r) temp[k++] = points[j++];
        
        for(int i = 0, j = l; i < k; i++, j++) points[j] = temp[i];
    }
    
    int k = 0;
    for(int i = l; i <= r; i++)
        if(points[i].x >= mid_x - res && points[i].x <= mid_x + res)
            temp[k++] = points[i];        
    for(int i = 0; i < k; i++)
        for(int j = i - 1; j > 0; j--)
            res = min(res, get_dist(temp[i], temp[j]));
    return res;
}

int main(){
    int T, n;
    cin >> T;
    while(T--){
        cin >> n;
        for(int i = 0; i < n; i++){
            cin >> points[i].x >> points[i].y;
            points[i].type = 0;
        }
        for(int i = n; i < 2*n; i++){
            cin >> points[i].x >> points[i].y;
            points[i].type = 1;
        }
        sort(points, points + n * 2);  //按照横坐标排序
        
        printf("%.3f\n", dfs(0, n * 2 - 1));
    }
    return 0;
}






