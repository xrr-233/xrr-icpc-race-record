#include <iostream>
#include <cstdio>
#include <cstring>
#include <deque>
using namespace std;
const int MAXV = 100;
const int MAXE = 10000;
const int MAXW = MAXV * 1000;
class Vertice {
	public:
		int first;
		int dist;
		bool visit;
		int pre;
};
class Edge {
	public: 
		int Next;
		int to;
		int w;
};
Vertice vertice[MAXV + 1];
Edge edge[MAXE * 2 + 1];
void add_edge(int u, int v, int w, int Size) {
	edge[Size].Next = vertice[u].first;
	edge[Size].to = v;
	edge[Size].w = w;
	vertice[u].first = Size;
}
void init(int v, int e) {
	for(int i = 1; i <= v; i++) {
		vertice[i].first = 0;
		vertice[i].dist = MAXW + 1;
		vertice[i].visit = false;
		vertice[i].pre = 0;
	}
	/*for(int i = 1; i <= e; i++) {
		edge[i].Next = 0;
		edge[i].to = 0;
		edge[i].w = 0;
	}*/
}
void spfa_slf_lll(int s, int t) {
	deque<int> Q;
	vertice[s].visit = true;
	vertice[s].dist = 0;
	Q.push_back(s);
	int num = 1;
	int sum = vertice[s].dist;
	while(!Q.empty()) {
		int cur = Q.front();
		//printf("%d\n", cur);
		while(num * vertice[cur].dist > sum) {
			Q.pop_front();
			Q.push_back(cur);
			cur = Q.front();
		}
		Q.pop_front();
		vertice[cur].visit = false;
		num--;
		sum -= vertice[cur].dist;
		
		for(int i = vertice[cur].first; i; i = edge[i].Next) {
			int to = edge[i].to;
			//printf("%d->%d\n", cur, to);
			if(vertice[to].dist > vertice[cur].dist + edge[i].w) {
				vertice[to].dist = vertice[cur].dist + edge[i].w;
				vertice[to].pre = cur;
				if(!vertice[to].visit) {
					vertice[to].visit = true;
					if(!Q.empty() && vertice[to].dist < vertice[Q.front()].dist)
						Q.push_front(to);
					else
						Q.push_back(to);
					num++;
					sum += vertice[to].dist;
				}
			}
		} 
	}
}
int main() {
	int v, e, a, b, c;
	scanf("%d%d", &v, &e);
	while(!(v == 0 && e == 0)) {
		init(v, e);
		for(int i = 1; i <= e; i++) {
			scanf("%d%d%d", &a, &b, &c);
			add_edge(a, b, c, i * 2 - 1);
			add_edge(b, a, c, i * 2);
		}
		spfa_slf_lll(1, v);
		printf("%d\n", vertice[v].dist);
		scanf("%d%d", &v, &e);
	}
}
//恭喜你通过了这道题！
//https://nanti.jisuanke.com/t/T1600
