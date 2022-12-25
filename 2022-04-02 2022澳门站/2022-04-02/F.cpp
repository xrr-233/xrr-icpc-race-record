#include <bits/stdc++.h>
using namespace std;
const int MAXN = 500010;
int n,a[MAXN],ans[MAXN]; 
priority_queue<pair<int,int> > q;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++) q.push(make_pair(a[i],i));
	int std = n-1;
	int cnt = 0;
	bool fl = true;
	while(!q.empty()){
		if(cnt>=2*n){
			fl=false;
			break;
		}
		pair<int,int> top = q.top();
		if(top.first < std){
			break;			
		}
		q.pop();
		q.push(make_pair(top.first-n,top.second));
		std--;
		cnt++;
	}
	if(!fl){
		printf("Recurrent\n");
		return 0;
	}
	for(int i=1;i<=n;i++) ans[i]=0;
	while(!q.empty()){
		pair<int,int> top = q.top();
		q.pop();
		ans[top.second] = top.first+n-1-std;
	}
	for(int i=1;i<n;i++) printf("%d ",ans[i]);printf("%d",ans[n]);
	return 0;
}
