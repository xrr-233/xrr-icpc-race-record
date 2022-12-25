#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
const int maxn=2e6+10;
const long long inf=0x3f3f3f3f3f3f3f3f;
int n,m;
long long a[maxn];
inline long long read()
{
	long long sum=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')
			f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		sum=sum*10+ch-'0';
		ch=getchar();
	}
	return sum*f;
}
struct node
{
	int l,r;
	long long val,lazy;
}tr[maxn<<4];
inline void build(int l,int r,int k)
{
	tr[k].l=l,tr[k].r=r;
	if(l==r)
	{
		tr[k].val=inf;
		tr[k].lazy=inf;
		return;
	}
	int mid=(l+r)>>1;
	build(l,mid,k<<1);
	build(mid+1,r,k<<1|1);
	tr[k].val=inf;
	tr[k].lazy=inf;
}
inline void down(int k)
{
	tr[k].val=min(tr[k].val,tr[k].lazy);
	tr[k<<1].lazy=min(tr[k].lazy,tr[k<<1].lazy);
	tr[k<<1].val=min(tr[k<<1].val,tr[k].lazy);
	tr[k<<1|1].lazy=min(tr[k].lazy,tr[k<<1|1].lazy);
	tr[k<<1|1].val=min(tr[k<<1|1].val,tr[k].lazy);
	tr[k].lazy=inf;
}
inline void modify(int l,int r,int k,long long val)
{
	if(l<=tr[k].l&&tr[k].r<=r)
	{
		tr[k].lazy=min(tr[k].lazy,val);
		tr[k].val=min(tr[k].val,val);
		return;
	}
	down(k);
	int mid=(tr[k].l+tr[k].r)>>1;
	if(r<=mid)
		modify(l,r,k<<1,val);
	else
		if(l>mid)
			modify(l,r,k<<1|1,val);
		else
		{
			modify(l,mid,k<<1,val);
			modify(mid+1,r,k<<1|1,val);
		}
}
inline long long query(int pos,int k)
{
	if(tr[k].l==tr[k].r)
		return tr[k].val;
	if(tr[k].lazy!=inf)
		down(k);
	int mid=(tr[k].l+tr[k].r)>>1;
	if(pos<=mid)
		return query(pos,k<<1);
	return query(pos,k<<1|1);
}
int main()
{
	int T,cas=0;
	T=read();
	while(T--)
	{
		n=read(),m=read();
		register long long sum=0;
		memset(a,-1,sizeof(a));
		build(1,n,1);
		for(register int i=1,l,r;i<=m;i++)
		{
			long long val;
			l=read(),r=read(),val=read();
			int len=(r-l+1);
			sum+=1ll*len*(len-1)*val/2;
			modify(l+1,r,1,val);
/*			for(int j=2;j<=n;j++)
				printf("%lld ",query(j,1));
			printf("\n");*/
		}
		register long long res=0;
		bool flag=1;
		for(register int i=2;i<=n;i++)
		{
			long long x=query(i,1);
			if(x==inf)
			{
				flag=0;
				break;
			}
			res+=x;
		}
		cas++;
		printf("Case #%d: ",cas);
		if(!flag)
			printf("Gotta prepare a lesson\n");
		else
			printf("%lld\n",sum-res);
	}
	return 0;
}
/*
1
5 3
3 2 3 3
3 2 5 3
1 4
2 4 5
1 3
1 5 1 1 3 1 1
1 4 2 1 1 2
3 3 1 2 1
*/
