#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
const int maxn=4e6+10;
int n,m;
vector<int>edge[maxn];
int main()
{
	int T,cas=0;
	cin>>T;
	while(T--)
	{
		cas++;
		cout<<"Case #"<<cas<<": "<<endl;
		cin>>n>>m;
		for(int u=1,k;u<=n;u++)
		{
			edge[u].clear();
			cin>>k;
			for(int i=1,v;i<=k;i++)
			{
				cin>>v;
				edge[u].push_back(v);
			}
		}
		while(m--)
		{
			int s,num;
			int flag=1;
			cin>>s>>num;
			for(int i=1,x;i<=num;i++)
			{
			//	cout<<"*"<<s<<endl;
				cin>>x;
				if(x>(int)edge[s].size())
				{
				//	cout<<x<<" "<<s<<" "<<edge[s].size()<<" ";
					cout<<"Packet Loss"<<endl;
					flag=0;
				}
				if(flag)
					s=edge[s][x-1];
			}
			if(flag)
				cout<<s<<endl;
		}
	}
	return 0;
}
/*
2
5 3
3 2 3 3
3 2 5 3
1 4
2 4 5
1 3
1 5 1 1 3 1 1
1 4 2 1 1 2
3 3 1 2 1
4 3
2 2 3
0
2 4 3
0
1 2 2 1
*/
