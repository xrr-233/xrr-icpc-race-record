#define B cout << "BreakPoint" << endl;
#define O(x) cout << #x << " " << x << endl;
#define O_(x) cout << #x << " " << x << " ";
#define Msz(x) cout << "Sizeof " << #x << " " << sizeof(x)/1024/1024 << " MB" << endl;
#include<cstdio>
#include<cmath>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
#include<set>
#define LL long long
const int inf = 1e9 + 9;
const int N = 2e6 + 5;
using namespace std;
inline int read() {
	int s = 0,w = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9') {
		if(ch == '-')
			w = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9') {
		s = s * 10 + ch - '0';
		ch = getchar();
	}
	return s * w;
}
int b[N],n,m;
int cnt,res,ans;
struct node{
    int l,r;
    inline bool operator <(const node &b)const{
        return r>b.r;
    }
}a[N];
priority_queue<node>q;
bool cmp(node a,node b){
    if(a.l != b.l) return a.l < b.l;
    return a.r > b.r; 
}
void solve(int o){
    while(!q.empty()) q.pop();
    n = read(),m = read();
    for(int i = 1;i <= n;i++){
        a[i].l = read();
		a[i].r = read();
    }
    for(int i = 1;i <= m;i++) b[i] = read();
    sort(b + 1,b + m + 1);
    sort(a + 1,a + n + 1,cmp);
    res = 0,ans = 0;
    for(int i = 1;i <= m;i++){
        while(res < n && a[res + 1].l <= b[i]) {
			res++;
			q.push(a[res]);
		}
        while(!q.empty()&&q.top().r < b[i]) q.pop();
        ans = max(ans,n - (int)q.size() + 1);
		if(q.size()) q.pop();
    }
    if(ans > n) printf("Case #%d: IMPOSSIBLE!\n",cnt);
    else printf("Case #%d: %d\n",o,ans);
}
int main(){
    int t = read();
    for(int i = 1;i <= t;i++) solve(i);
    return 0;
}

