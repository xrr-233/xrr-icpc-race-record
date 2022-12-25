#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<ctime>
using namespace std;
const int maxn=1e2+10;
int n,sgn[maxn],a[maxn],b[maxn],c[maxn];
int main()
{
	srand(time(0));
	freopen("in.txt","w",stdout);
	n=60;
	printf("%d\n",n);
	for(int i=0;i<n;i++)
		printf("%d ",rand()%2==0?-1:1);
	printf("\n");
	for(int i=0;i<n;i++)
		printf("%d ",rand()%2);
	printf("\n");
	for(int i=0;i<n;i++)
		printf("%d ",rand()%2);
	printf("\n");
	return 0;
}
