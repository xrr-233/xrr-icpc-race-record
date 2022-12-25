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
inline LL read() {
	LL s = 0,w = 1;
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
LL c[N],L,n,m;
struct node{
    LL x, y;
    node(LL _x = 0, LL _y = 0):x(_x),y(_y){}
    bool operator < (const node &a) const{
        return x > a.x;
    }
}now,last;
priority_queue<node>q1, q2;
void init(){
	while(!q1.empty()) q1.pop();
    while(!q2.empty()) q2.pop();
    L = read(),n = read(),m = read();
    for(int i = 1;i <= n;i++){
        LL x = read();
        last.x = last.y = x;
        q1.push(last);
    }
    for(int i = 1;i <= m;i++){
        LL x = read();
        last.x = last.y = x;
        q2.push(last);
    }
    return ;
}
void solve(int k){
	for(int i = 1;i <= L;i++){
        last = q1.top(); 
		q1.pop();
        c[i] = last.x;
        last.x += last.y;
        q1.push(last);
    }
    LL ans = 0;
    for(int i = L;i >= 1;i--){
        last = q2.top(); 
		q2.pop();
        ans = max(ans, last.x + c[i]);
        last.x += last.y;
        q2.push(last);
    }
    printf("Case #%d: %lld\n", k, ans);
}
int main(){
	int t = read();
	for(int i = 1;i <= t;i++){
		init();
		solve(i);
	}
    return 0;
}





