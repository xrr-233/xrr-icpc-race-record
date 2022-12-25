#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100010;
int T,n,m;
struct edge{
	int v;
	int next;
	int len;
}E[MAXN<<1];
int p[MAXN],eid;
void init(){
	for(int i=1;i<=n;i++) p[i] = -1;
	eid = 0;
}
void insert(int u,int v,int len){
	E[eid].v = v;
	E[eid].len = len;
	E[eid].next = p[u];
	p[u] = eid++;
}
int fa[MAXN];
int get(int x){
	if(x == fa[x]) return x;
	return fa[x] = get(fa[x]);
}
void merge(int x,int y){
	fa[get(x)] = get(y);
}
bool vis[MAXN];
int deg[MAXN];
queue<int> q;
void bfs(){
	while(!q.empty()){
		int u = q.front();
		q.pop();
		deg[u] = 0;
		for(int i=p[u];i!=-1;i=E[i].next){
			int v = E[i].v;
			deg[v]--;
			if(deg[v] == 1){
				q.push(v);
			}
		}
	}
}
set<int> ans;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++) vis[i] = false;
		for(int i=1;i<=n;i++) fa[i]=i;
		init();
		bool fl = false;
		int root = -1;
		for(int i=1;i<=m;i++){
			int x,y;
			scanf("%d%d",&x,&y);
			if(fl) continue;
			int fx = get(x);
			int fy = get(y);
			if(fx == fy){
				fl = true;
				insert(x,y,i);
				insert(y,x,i);
				root = fx;
				continue;
			}else{
				merge(fx,fy);
				vis[fx] = true;
				vis[fy] = true;
				insert(x,y,i);
				insert(y,x,i);
			}
		}
		if(!fl){
			printf("-1\n");
			continue;
		}
		for(int i=1;i<=n;i++) deg[i] = 0;
		for(int u=1;u<=n;u++){
			for(int i=p[u];i!=-1;i=E[i].next){
				int v = E[i].v;
				int len = E[i].len;
				//printf("%d %d %d\n",u,v,len);
				if(get(u) == root && get(v) == root){
					deg[u]++;
					deg[v]++;
				}
			}
		}
		for(int i=1;i<=n;i++) deg[i] = deg[i]/2;
		//for(int i=1;i<=n;i++) printf("%d ",deg[i]);printf("\n");
		while(!q.empty()) q.pop();
		for(int i=1;i<=n;i++){
			if(deg[i] == 1){
				q.push(i);
			}
		}
		bfs();
		//for(int i=1;i<=n;i++) printf("%d ",deg[i]);printf("\n");
		int cnt=0;
		ans.clear();
		for(int u=1;u<=n;u++){
			for(int i=p[u];i!=-1;i=E[i].next){
				int v = E[i].v;
				int len = E[i].len;
				//printf("%d %d %d\n",u,v,len);
				if(deg[u] == 2 && deg[v] == 2){
					ans.insert(len);	
				}
			}
		}
		set<int>::iterator it;
		for(it = ans.begin();it != ans.end(); it++){
			if(it == ans.begin()) printf("%d",*it);
			else printf(" %d",*it);
		}
		printf("\n");
	}
	return 0;
}
