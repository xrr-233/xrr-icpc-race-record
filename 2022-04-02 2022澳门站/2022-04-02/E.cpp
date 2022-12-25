#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN = 100010;
int n,q,a[MAXN];
bool vis[MAXN];
vector<int> cir[MAXN];


int main(){
	freopen("test.in","r",stdin);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++) vis[i] = false;
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(vis[i] == false){
			int now = i;
			cnt++;
			while(true){
				if(vis[now] == true) break;
				cir[cnt].push_back(now);
				vis[now] = true;
				now = a[now];	
			}
			
		}
	}
	/*
	printf("%d\n",cnt);
	for(int i=1;i<=cnt;i++){
		for(int j=0;j<cir[i].size();j++){
			printf("%d ",cir[i][j]);
		}
		printf("\n");
	}
	*/
	if(cnt >= sqrt(n)){
		
	}else{
		
	}
	return 0;
}
