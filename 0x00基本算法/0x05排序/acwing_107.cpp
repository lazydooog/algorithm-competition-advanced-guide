/*
* @Description: 107. 超快速排序
* @Author: Xiaobin Ren
* @Date:   2020-07-13 10:06:09
* @Last Modified time: 2020-07-13 11:16:46
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

const int N = 500010;
long long  tmp[N];
long long  q[N];
long long  cnt;

void merge_sort(long long a[], int l, int r){
	if(l >= r) return;
	int mid = l + r >> 1;
	merge_sort(a, l, mid); merge_sort(a, mid + 1, r);

	int k = 0, i = l, j = mid + 1;
	while(i <= mid && j <= r)
		if (a[i] < a[j]) 
			tmp[k++] = a[i++];
		else {
			tmp[k++] = a[j++];
			cnt += mid - i + 1;
		}
	while(i <= mid) tmp[k++] = a[i++];
	while(j <= r) tmp[k++] = a[j++];

	for(int i = l, j = 0; i <= r; i++, j++) a[i] = tmp[j];
}


int main(){
    long long n;
    while(scanf("%lld", &n) && n){
        cnt = 0;
        for(int i = 0; i < n; i++) scanf("%lld", &q[i]);
        merge_sort(q, 0, n - 1);
        cout << cnt << endl;
    }
    
    return 0;
}