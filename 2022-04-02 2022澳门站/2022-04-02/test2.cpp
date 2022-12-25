#include <bits/stdc++.h>
using namespace std;
long long n,k,x,y;
string s;
void solve(char a){
	if(a == 'U') y++;
	if(a == 'D') y--;
	if(a == 'L') x--;
	if(a == 'R') x++;
	return ;
}
long long dis(long long x,long long y){
	return abs(x)+abs(y);
}
void init(){
	x = 0,y = 0;
	long long ans = 0,res = 0;
	scanf("%lld%lld",&n,&k);
	cin >> s;
	int l = s.size();
	for(int i = 0;i < l; i++) {
		solve(s[i]);
		res = dis(x,y);
		ans = max(res,ans);
	}
	x = x*(k-1);
	y = y*(k-1);
	for(int i = 0;i < l; i++) {
		solve(s[i]);
		res = dis(x,y);
		ans = max(res,ans);
	}
	printf("%lld\n",ans);
	return ;
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		init();
	}
}
