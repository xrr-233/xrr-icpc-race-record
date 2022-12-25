#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn=9999;
int num[10];
int nex(int x)
{
    return 4== x?0:1+x;
}
int pre(int x)
{
    return 0==x?4:x-1;
}
int find_mindex()
{
    int mindex=maxn;
    int minval=0;
    for(int i=0;i<5;i++)
    {
        if(num[i]<minval)
        {
            mindex=i;
            minval=num[i];
        }
    }
    return mindex;
}
int main()
{
    int t;
    scanf("%d",&t);

    for(int c=1;c<=t;c++)
    {
        for(int i=0;i<5;i++)
        {
            scanf("%d",&num[i]);
        }
        int minndex,predex,nextdex;
        while(find_mindex()!=maxn)
        {
            minndex=find_mindex();
            num[minndex]=-num[minndex];
            predex=pre(minndex);
            num[predex]-=num[minndex];
            nextdex=nex(minndex);
            num[nextdex]-=num[minndex];
        }
        printf("Pentagon #%d:\n",c);
        printf("%d %d %d %d %d\n\n",num[0],num[1],num[2],num[3],num[4]);


    }
    return 0;
}
