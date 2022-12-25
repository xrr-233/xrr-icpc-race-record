#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#define LL long long
using namespace std;
const int N=2e5+10;
int n,t;
LL a[N],b[N],sum1,sum2,sum3,sum4,sum5;
void pre(int num){
	for(int i = 1;i <= n;i++) {
		sum1 += a[i] * b[i];
//		if(num <= 1) continue;
		sum2 += a[i] * b[i] * b[i];
//		if(num <= 2) continue;
		sum3 += a[i] * b[i] * b[i] * b[i];
//		if(num <= 3) continue;  
		sum4 += a[i] * b[i] * b[i] * b[i] * b[i];
//		if(num <= 4) continue;
		sum5 += a[i] * b[i] * b[i] * b[i] * b[i] * b[i];
	}
	return ;
}
void init(){
	scanf("%d %d",&n,&t);
	for(int i = 1;i <= n;i++) scanf("%lld",&a[i]);
	for(int i = 1;i <= n;i++) scanf("%lld",&b[i]);
	pre(t);
	return ;
}
void solve(int a){
	if(a == 1) {
		printf("%lld",sum1);
		return ;
		
	}
	if(a == 2){
		if(sum1 != 0) printf("infinity");
		else {
			if(sum2 % 2 == 0) printf("%lld",-sum2 / 2);
			else { printf("%lld",-sum2);printf("/2");}
		}
	}
	if(a == 3){
		if(sum1 != 0 || sum2 != 0) printf("infinity");
		else {
			if(sum3 % 3 == 0) printf("%lld",sum3 / 3);
			else {printf("%lld",sum3);printf("/3");}
		}
	}
	if(a == 4){
		if(sum1 != 0 || sum2 != 0 || sum3 != 0) printf("infinity");
		else {
			if(sum4 % 4 == 0) printf("%lld",-sum4 / 4);
			else {
				if (sum4 % 2 == 0) {printf("%lld",-sum4/2);printf("/2");}
				else {printf("%lld",-sum4);printf("/4");}
			}
		}
	}
	if(a == 5){
		if(sum1 != 0 || sum2 != 0 || sum3 != 0 || sum4 != 0) printf("infinity");
		else {
			if(sum5 % 5 == 0) printf("%lld",sum5 / 5);
			else { printf("%lld",sum5);printf("/5");}
		}
	}
	return ;
}
int main(){
	init();
	if(t == 0) {
		printf("0");
		return 0;		
	}
	solve(t);
	return 0;
}

