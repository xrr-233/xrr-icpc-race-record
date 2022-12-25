#include<iostream>
#include<cstdio>
using namespace std;
const int maxn=1e2+10;
int n,sgn[maxn],a[maxn],b[maxn],c[maxn];
int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&sgn[i]);
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(int i=0;i<n;i++)
		scanf("%d",&b[i]);
	int x=0;
	for(int i=0;i<n;i++)
	{
		c[i]=a[i]+b[i]+x;
		x=(c[i]+2)/2-1;
		c[i]=(c[i]+2)%2;
		if(sgn[i]!=sgn[i+1])
			x=-x;
	}
	/*printf("%d\n",n);
	for(int i=0;i<n;i++)
		printf("%d ",sgn[i]);
	printf("\n");*/
	for(int i=0;i<n;i++)
	{
		if(i)
			printf(" ");
		printf("%d",c[i]);
	}
	return 0;
}
