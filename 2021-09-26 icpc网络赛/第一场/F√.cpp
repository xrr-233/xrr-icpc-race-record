#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
int main()
{
	int T,cas=0;
	cin>>T;
	while(T--)
	{
		cas++;
		double a,b,r;
		cin>>a>>b>>r;
		if(b<=r)
		{
			printf("Case #%d: %.2lf\n",cas,2*a-r);
			continue;
		}
		b-=r;
		double res=sqrt(a*a+b*b)*2-r; 
		printf("Case #%d: %.2lf\n",cas,res);
	}
	return 0;
}
