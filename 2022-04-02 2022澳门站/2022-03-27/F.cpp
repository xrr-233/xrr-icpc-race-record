#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
const int MAXN = 200010;
int n,m;
bool a[MAXN<<2];
void pushup(int id){a[id] = a[id<<1]&a[id<<1|1];}
void pushdown(int id){
    if(a[id]){
        a[id<<1] = true;
        a[id<<1|1] = true;
    }
    return ;
}
void build(int id,int l,int r){
    if(l == r){
        a[id]=false;
        return;
    }
    int mid = (l+r)>>1;
    build(id<<1,l,mid);
    build(id<<1|1,mid+1,r);
    pushup(id);
}
void update(int id,int l,int r,int x,int y){
    if(y<x) return;
    if(x<=l && r<=y){
        a[id] = true;
        return;
    }
    pushdown(id);
    int mid = (l+r)>>1;
    if(x<=mid) update(id<<1,l,mid,x,y);
    if(y>mid) update(id<<1|1,mid+1,r,x,y);
    pushup(id);
}
struct edge{
    int u,v,len;
}E[MAXN];
bool cmp(edge a,edge b){
    return a.len<b.len;
}
int main(){
    //freopen("test.in","r",stdin);
    while(cin>>n){
        cin>>m;
        build(1,1,n);
        //printf("%d\n",n+(n-1)/2-1);
        for(int i=1;i<=m;i++){
            int x,y;
            scanf("%d%d",&x,&y);
            if(x>y) swap(x,y);
            if(y-x <= n/2){
                E[i].u = x;
                E[i].v = y;
                E[i].len = y-x;
            }else{
                E[i].u = y;
                E[i].v = x+n;
                E[i].len = x+n-y;
            }
        }
        int fans = -1;
        sort(E+1,E+1+m,cmp);
        //for(int i=1;i<=m;i++) printf("%d %d %d\n",E[i].u,E[i].v,E[i].len);printf("\n");
        for(int i=1;i<=m;i++){
            update(1,1,n,E[i].u,min(E[i].v-1, n));
            if(E[i].v-1 > n) {
            	update(1,1,n,1,E[i].v-1-n);
			}
            /*printf("%d\n", a[1]);
            printf("%d %d\n", a[2], a[3]);
            printf("%d %d %d %d\n", a[4], a[5], a[6], a[7]);
            printf("%d %d %d %d %d %d %d %d\n", 
			a[8], a[9], a[10], a[11], a[12], a[13], a[14], a[15]);*/
            if(a[1] == true){
                fans = n-E[i].len;
                break;
            }
        }
        if(fans == -1) fans = E[m].len;
        printf("%d\n",fans);
    }
    return 0;
}
/*
6 5
1 2
2 3
3 4
4 5
5 1
*/
