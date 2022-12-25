#include<bits/stdc++.h>
using namespace std;
bool g[1<<10][1<<10];
void turnOff(int x,int xx,int y,int yy) {
	for(int j=y;j<=yy;j++) {
		for(int i=x;i<=xx;i++) {
			g[j][i]=false;
		}
	}
}
void go(int x,int xx,int y,int yy) {
	
	//2*2正方形 
	if(x+1==xx&&y+1==yy) {
		return;
	}
	//取中点 
	int mx=(x+xx)/2;
	int my=(y+yy)/2;
	int mlx=(x+mx)/2;
	int mrx=(mx+1+xx)/2+1;
	turnOff(x, mlx, y, my);
	turnOff(mrx, xx, y, my);
	go(mlx + 1, mrx - 1, y, my);
	go(x, mx, my + 1, yy);
	go(mx + 1, xx, my + 1,yy);
}
int main(){
	int t;
	cin>>t;
	int num=0,k;
	while(t--) {
		num++;
		cin>>k;
		int n=1<<k;
		for(int i=0;i<n;i++) {
			for(int j=0;j<n;j++) {
				g[i][j]=true;
			}
		}
		go(0,n-1,0,n-1);
		cout<<"Triangle #"<<num<<":"<<endl;
		for(int i=0;i<n;i++) {
			for(int j=0;j<n;j++) {
				if(g[i][j]) {
					cout<<"X";
				}
				else {
					cout<<" ";
				}
			}
			cout<<endl;
		}
		cout<<endl;
	}
	return 0;
}

