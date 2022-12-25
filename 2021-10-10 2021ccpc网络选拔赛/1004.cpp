#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
using namespace std;
long long x;
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%lld",&x);
		if(x==1)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
