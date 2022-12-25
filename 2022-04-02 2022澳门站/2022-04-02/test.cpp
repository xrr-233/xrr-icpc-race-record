#include <bits/stdc++.h>
using namespace std;
int n,k;
bool fl;
void out(int x){
	if(fl){
		printf(" %d",x);
		return;	
	}else{
		printf("%d",x);
		fl = true;	
	} 
	
}
int main(){
	scanf("%d%d",&n,&k);
	fl = false;
	for(int i=1;i<=min(n,k);i++){
		int now = i;
		while(now<=n) out(now),now+=k;
	}
	return 0;
}
