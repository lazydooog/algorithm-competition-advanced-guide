/*
* @Description: 115. 给树染色
* @Author: Xiaobin Ren
* @Date:   2020-07-15 21:22:27
* @Last Modified time: 2020-07-15 22:15:09
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

/*
	这个贪心题，不要被树节点的顺序套进去
	对于一个给定的树，染色方法是唯一的，先每次找到均值最大的节点，然后和其父节点合并
	不需要理会根节点，直接合并 n - 1 次，最后肯定会合并为一个点，而且这个点必定为根节点。
	为什么一定到最后的时候，权值最大的点一定是根节点呢？因为合并的过程总是“自下而上”的合并。
	也就是说既然父节点染色后才能染色子节点，那么就逆向思维，先把最大的子节点染色，然后立马染色父节点，直到最后一直向上合并到
	父节点。 好了，现在我们把刚才的过程全部逆推，那么逆推的过程就是从“根节点” 开始染色的过程，也就是最优解的染色路径了。
*/
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
        nodes[ver].avg = -1;  //下一次find就不会再找这个节点了 随便赋值一个很小的数
        for(int j = 1; j <= n; j++)
            if(nodes[j].father == ver) nodes[j].father = f; //合并根节点
        nodes[f].sum += nodes[ver].sum;
        nodes[f].size += nodes[ver].size;
        nodes[f].avg = (double)nodes[f].sum / nodes[f].size;
        
    }
    
    cout << res << endl;
    return 0;
}
