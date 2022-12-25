#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int MAXN = 1e5;
const int MAXM = 1e5;
class Edge {
	public:
		int u;
		int v;
		int w;
};
class EdgeList {
	public:
		int to;
		int Next;
		int w;
};
class PointList {
	public:
		int first;
		bool vis;
};
EdgeList edgeList[MAXM + 5];
PointList pointList[MAXN + 5];
Edge edge[MAXM + 5];
int fa[MAXN + 5];
int sta[MAXN + 5], sta_edge[MAXN + 5], Size, edge_max, globalFlag;
int find_fa(int x) {
	if(fa[x] == x)
		return x;
	else {
		fa[x] = fa[fa[x]];
		return find_fa(fa[x]);
	}
}
void dfs(int x, int last) {
	sta[++Size] = x;
	pointList[x].vis = true;
	/*cout << "sta:";
	for(int i = 1; i <= Size; i++)
		cout << sta[i] << ' ';
	cout << endl;
	cout << pointList[x].first << endl;*/
	for(int i = pointList[x].first; i; i = edgeList[i].Next) {
		//cout << x << "->" << edgeList[i].to << ":" << edgeList[i].w << endl;
		if(globalFlag)
			return;
		if(find_fa(edgeList[i].to) != find_fa(x) || edgeList[i].w > edge_max || edgeList[i].to == last)
			continue;
		if(!pointList[edgeList[i].to].vis) {
			sta_edge[Size] = edgeList[i].w;
			dfs(edgeList[i].to, x);
		}
		else {
			sta_edge[Size] = edgeList[i].w;
			/*cout << "jiancedaohuan" << endl;
			cout << "sta:";
			for(int j = 1; j <= Size; j++)
				cout << sta[j] << ' ';
			cout << endl;
			cout << x << "->" << edgeList[i].to << ":" << edgeList[i].w << endl;*/
			int start;
			for(int j = 1; j <= Size; j++)
				if(sta[j] == edgeList[i].to) {
					start = j;
					break;
				}
			//cout << start << endl;
			//cout << "!" << endl;
			sort(sta_edge + start, sta_edge + Size + 1);
			for(int i = start; i < Size; i++)
				printf("%d ", sta_edge[i]);
			printf("%d\n", sta_edge[Size]);
			globalFlag = true;n
		}
	}
	Size--;
}
int main() {
	int T, n, m, fa1, fa2;
	scanf("%d", &T);
	while(T--) {
		scanf("%d%d", &n, &m);
		
		Size = 0;
		for(int i = 1; i <= n; i++) {
			fa[i] = i;
			pointList[i].first = 0;
			pointList[i].vis = false;
		}
		bool flag = false;
		
		for(int i = 1; i <= m; i++) {
			scanf("%d%d", &edge[i].u, &edge[i].v);
			edge[i].w = i;
			edgeList[2 * i - 1].Next = pointList[edge[i].u].first;
			edgeList[2 * i - 1].to = edge[i].v;
			edgeList[2 * i - 1].w = i;
			pointList[edge[i].u].first = 2 * i - 1;
			edgeList[2 * i].Next = pointList[edge[i].v].first;
			edgeList[2 * i].to = edge[i].u;
			edgeList[2 * i].w = i;
			pointList[edge[i].v].first = 2 * i;
		}
		
		for(int i = 1; i <= m; i++) {
			fa1 = find_fa(edge[i].u);
			fa2 = find_fa(edge[i].v);
			if(fa1 != fa2)
				fa[fa2] = fa1;
			else {
				//cout << "!" << endl;
				flag = true;
				globalFlag = false;
				edge_max = i;
				dfs(fa1, 0);
				break;
			}
			/*for(int j = 1; j <= n; j++)
				cout << fa[j] << ' ';
			cout << endl;*/
		}
		if(!flag)
			printf("-1\n");
	}
}
/*
2
6 8
1 2
2 3
5 6
3 4
2 5
5 4
5 1
4 2
4 2
1 2
4 3
*/
