#define B cout << "Breakpoint" << ednl;
#define O(x) cout <<#x<<" "<<x << endl;
#define o(x) cout << #x << " " << x << " ";
#include<bits/stdc++.h>
#define LL long long
const int inf = 1e9+9;
const int N = 2e5+5;
using namespace std;
inline int read(){
	int s = 0,w = 1;
	char ch = getchar();
	while(ch < '0'||ch>'9'){
		if(ch == '-')
			w = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9'){
		s = s*10+ch-'0';
		ch = getchar();
	}
	return s * w;
}
inline void out(int x){
	if(x > 10){
		out(x/10);
	}
	putchar(x % 10 + '0');
}
int a[70][70],n;
void init(){
	n = read();
	for(int i = 1;i <= n+2;i++)
	for(int j = 1;j <= n+2;j++)
	a[i][j] =0;
	vector<int>c;
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n;j++){
			a[i][j] = read();
		}
	}
	for(int i = 1;i <= n;i++){
		if(i%2==1)
			for(int j = 1;j <= n;j++){
				c.push_back(a[i][j]);
			}
		else 
			for(int j = n;j >= 1;j--){
				c.push_back(a[i][j]);
			}
	}
	int l = c.size(),res = 0;
	for(int i = 1;i < l;i++){
		if(c[i] > c[i-1]) res--;
		else res++;
	}
	if(res >= 0) {
		for(int i = 0;i < l-1;i++){
			printf("%d ",c[i]);
		}
		printf("%d\n",c[l-1]);
	}
	else {
		for(int i = l-1;i > 0;i--){
			printf("%d ",c[i]);
		}
		printf("%d\n",c[0]);
	}
	return ;
}
int main(){
	int t = read();
	while(t--) init();
	return 0;
}
/*
2
2
4 3
2 1
2
1 2
3 4
*/
