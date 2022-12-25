#include<bits/stdc++.h>
using namespace std;
int v[55][55];
bool vv[55],flag;
int n,x[55],y[55],start=1;
int ans[55];
int line(int i,int j) //判断i，j在不在一条直线
{
    if(i==j) return 0;
    if((x[i]-x[j]) && !(y[i]-y[j])) return 1;//平行x轴
    if(!(x[i]-x[j]) && (y[i]-y[j])) return 2;//平行y轴
    return 0;
}
bool X1(int i,int j) //判断ij之间有没有点,平行x轴
{
    for(int k=1;k<=n;k++)
    {
        if(line(i,k)==1 && line(j,k)==1)
        {
            if((x[i]-x[k])>0 && (x[j]-x[k])<0) return 0;
            if((x[i]-x[k])<0 && (x[j]-x[k])>0) return 0;
        }
    }
    return 1;
}
bool X2(int i,int j) //判断ij之间有没有点，平行y轴
{
    for(int k=1;k<=n;k++)
    {
        if(line(i,k)==2 && line(j,k)==2)
        {
            if((y[i]-y[k])>0 && (y[j]-y[k])<0) return 0;
            if((y[i]-y[k])<0 && (y[j]-y[k])>0) return 0;
        }
    }
    return 1;
}
int link(int i,int j)//判断ij能不能直连
{
    if(i==j) return 0;
    int tmp=line(i,j);
    if(!tmp) return 0;
    if(tmp==1)
    {
        if(X1(i,j)) return 1;
    }else if(tmp==2)
        if(X2(i,j)) return 2;
    return 0;
}
void dfs(int fx,int pos,int cnt) //fx是上一条边的方向
{
    ans[cnt]=pos;
    for(int i=1;i<=n && flag;i++)
    {
        if(!vv[i] && v[i][pos] && v[i][pos]!=fx)
        {
            vv[i]=1;
            dfs(v[i][pos],i,cnt+1);
            vv[i]=0;
        }
    }
    if(cnt>n && pos==start)
    {
        flag=0;
        return;
    }
}
int main()
{
    int ttt=1;
    while(scanf("%d",&n) && n)
    {
        start=1;
        memset(ans,0,sizeof ans);
        for(int i=1;i<=n;i++)
        {
            scanf("%d%d",x+i,y+i);
            if(y[i]<y[start]) start=i;
            else if(y[i]==y[start] && x[start]>x[i]) start=i;
        }
        for(int i=1;i<=n;i++)
            for(int j=i+1;j<=n;j++)
                v[i][j]=v[j][i]=link(i,j);
        flag=1;
        memset(vv,0,sizeof vv);
        dfs(0,start,1);
        cout<<"Polygon #"<<ttt++<<": "<<ans[1];
        if(line(ans[1],ans[2])==1)
            for(int i=2;i<=n;i++) cout<<' '<<ans[i];
        else
            for(int i=n;i>1;i--) cout<<' '<<ans[i];
        cout<<' '<<endl;
    }
    return 0;
}
