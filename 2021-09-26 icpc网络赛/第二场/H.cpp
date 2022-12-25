#include<iostream>
#include<cstdio>
using namespace std;
int r,k;
int main()
{
	scanf("%d%d",&r,&k);
	if(128%r==0)
	{
		if(k>2*r)
			printf("-1");
		else
		{
			int p=128/r,lst=1;
			for(int i=0;i<k;i++)
			{
				int j=1;
				for(;j<lst;j++)
					printf("0");
				for(;j<lst+p;j++)
					printf("1");
				for(;j<=256;j++)
					printf("0");
				lst+=p;
				puts("");
			}
		}
	}
	else
	{
		int p=128/r+1,q=128%r;
		if(k>128/p+r)
			printf("-1");
		else
		{
			int lst=1;
			for(int i=0;i<k;i++)
			{
				int j=1;
				for(;j<lst;j++)
						printf("0");
				for(;j<lst+p;j++)
					printf("1");
				for(;j<=256;j++)
					printf("0");
				lst+=p;
				puts("");
			}
		}
	}
	return 0;
}
