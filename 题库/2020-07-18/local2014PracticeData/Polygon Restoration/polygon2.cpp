#include<bits/stdc++.h>
using namespace std;
const int maxm=55;
int x[maxm],y[maxm];
int dir[maxm][4];//dir[x][0左1右2上3下]
int mark[maxm];
int vis[maxm];
int n,st,ok;
void dfs(int x,int tot,int last){//last是上一条边的方向
    vis[tot]=x;
    if(tot==n){//搜完判断是否和起点相连
        for(int i=0;i<4&&!ok;i++)if(i!=last&&dir[x][i]==st)ok=1;
        return ;
    }
    mark[x]=1;
    for(int i=0;i<4&&!ok;i++){
        if(i!=last&&dir[x][i]&&!mark[dir[x][i]]){
            dfs(dir[x][i],tot+1,i);
        }
    }
    mark[x]=0;
}
signed main(){
    int cas=1;
    while(scanf("%d",&n)&&n){
        st=1;
        for(int i=1;i<=n;i++){
            scanf("%d%d",&x[i],&y[i]);
            if(y[i]<y[st]||(y[i]==y[st]&&x[i]<x[st]))st=i;
        }
        for(int i=1;i<=n;i++)for(int j=0;j<4;j++)dir[i][j]=0;
        for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++){//预处理四个方向最近点
            if(y[i]==y[j]){
                if(x[j]<x[i]){
                    if(!dir[i][0]||x[j]>x[dir[i][0]])dir[i][0]=j,dir[j][1]=i;
                }else{
                    if(!dir[i][1]||x[j]<x[dir[i][1]])dir[i][1]=j,dir[j][0]=i;
                }
            }else if(x[i]==x[j]){
                if(y[j]>y[i]){
                    if(!dir[i][2]||y[j]<y[dir[i][2]])dir[i][2]=j,dir[j][3]=i;
                }else{
                    if(!dir[i][3]||y[j]>y[dir[i][3]])dir[i][3]=j,dir[j][2]=i;
                }
            }
        }
        ok=0;
        for(int i=1;i<=n;i++)mark[i]=0;
        dfs(st,1,-1);
        printf("Polygon #%d: ",cas++);
        if(n>=2&&x[vis[2]]<x[st]){//判断输出方向
            printf("%d ",vis[1]);
            for(int i=n;i>=2;i--)printf("%d ",vis[i]);
        }else{
            for(int i=1;i<=n;i++)printf("%d ",vis[i]);
        }
        puts("");
    }
    return 0;
}
