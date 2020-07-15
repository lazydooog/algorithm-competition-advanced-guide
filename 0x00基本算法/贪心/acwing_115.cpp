/*
* @Description: 115. 给树染色
* @Author: Xiaobin Ren
* @Date:   2020-07-15 21:22:27
* @Last Modified time: 2020-07-15 21:23:08
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

const int N = 1010;

int n, root;

struct Node{
    int father;
    int size;  
    int sum;    //权值和
    double avg;  //均值
}nodes[N];

int find(){  //找最大的节点 下标
    double avg = 0;
    int res = -1;
    for(int i = 1; i <= n; i++){
        if(i != root && nodes[i].avg > avg){
            avg = nodes[i].avg;
            res = i;
        }
    }
    return res;
}

int main(){
    int res = 0;
    cin >> n >> root;
    for(int i = 1; i <=n; i++) {   //注意题目 节点从 1 开始
        auto & nd = nodes[i];
        cin >> nd.sum;
        nd.size = 1;
        nd.avg = nd.sum;
        res += nd.sum;
    }
    for(int i = 0, a, b ; i < n - 1; i++){
        cin >> a >> b;
        nodes[b].father = a;
    }
    
   
    for(int i = 0; i < n - 1; i++){
        int ver = find();
        int f = nodes[ver].father;
        res += nodes[ver].sum * nodes[f].size;
        nodes[ver].avg = -1;  //下一次find就不会再找这个节点了 随便复制一个很小的数
        for(int j = 1; j <= n; j++)
            if(nodes[j].father == ver) nodes[j].father = f; //合并根节点
        nodes[f].sum += nodes[ver].sum;
        nodes[f].size += nodes[ver].size;
        nodes[f].avg = (double)nodes[f].sum / nodes[f].size;
        
    }
    
    cout << res << endl;
    return 0;
}
