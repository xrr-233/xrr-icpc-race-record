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
#include<vector>
#define LL long long
const LL mod = 1e9 + 7;
const int N = 2e5 + 5;
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
int head[N],c[N],to[2*N],nxt[2*N],tot;
LL sum[N],son[N],ans;
void add(int x,int y){
    to[++tot] = y;
    nxt[tot] = head[x];
    head[x] = tot;
}
void dfs(int x,int fa){
    son[x] = 1;
    LL a = sum[c[x]];
    LL b = a;
    for(int i = head[x];i;i = nxt[i]){
        int v = to[i];
        if(v != fa){
            dfs(v,x);
            son[x] += son[v];
            ans += (son[v] - sum[c[x]] + a - 1) * (son[v] - sum[c[x]] + a) / 2;
            a = sum[c[x]];
        }
    }
    sum[c[x]] += son[x]-(sum[c[x]]-b);
}
int vis[N],cas;
void init(){
    memset(head,0,sizeof(head));
    memset(to,0,sizeof(to));
    memset(nxt,0,sizeof(nxt));
    memset(sum,0,sizeof(sum));
    memset(vis,0,sizeof(vis));
    tot = 0,ans = 0;
}
int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        LL cnt = 0;
        init();
        for(int i = 1;i <= n;i++){
            c[i] = read();
            if(!vis[c[i]]){
                cnt++;
                vis[c[i]] = 1;
            }
        }
        for(int i = 0;i < n - 1;i++){
            int u = read(),v = read();
            add(u,v);
            add(v,u);
        }
        dfs(1,0);
        LL tmp = 1LL * n * (n - 1) * cnt / 2;
        for(int i = 1;i <= n;i++){
            if(vis[i]) tmp -= (n - sum[i]) * (n - sum[i] - 1) / 2;
        }
        printf("Case #%d: %lld\n",++cas,tmp - ans);
    }
}
