#include <bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
#define mp make_pair

typedef pair<int, int> PII;

const int Max_N = 100005;

namespace Disjoint_set {
	int fa[Max_N];

	void init(int _n) {
		for (int i = 1; i <= _n; i++)
			fa[i] = i;
	}

	int getf(int u) {
		return fa[u] == u ? u : fa[u] = getf(fa[u]);
	}

	void merge(int u, int v) {
		int r1 = getf(u), r2 = getf(v);
		if (r1 != r2) {
			fa[r1] = r2;
		}
	}
}

bool visited[Max_N];
int T, N, F[Max_N], val[Max_N], pos[Max_N];
int head[Max_N], adj[Max_N << 1], nxt[Max_N << 1], mxpos[Max_N << 1], total;
PII v[Max_N];

inline void addedge(int u, int v) {
	++total, adj[total] = v, nxt[total] = head[u], head[u] = total;
}

void Solve(int v) {
	visited[v] = true;
	for (int i = head[v]; i; i = nxt[i]) {
		if (!visited[ adj[i] ]) {
			int p = mxpos[i];
			F[p] = F[v] + 1;
			Solve(p);
		}
	}
}

int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &N);
		for (int i = 1; i <= N; i++)
			head[i] = 0;
		total = 0;
		Disjoint_set::init(N);
		for (int i = 1; i <= N; i++)
			F[i] = 0;
		
		for (int u, v, i = 1; i <= N - 1; i++) {
			scanf("%d%d", &u, &v);
			addedge(u, v), addedge(v, u);
		}
		for (int ai, i = 1; i <= N; i++) {
			scanf("%d", &ai);
			v[i] = mp(ai, i), val[i] = ai;
		}
		sort(v + 1, v + 1 + N);
		
		for (int i = 1; i <= N; i++)
			pos[i] = i;
		for (int i = 1; i <= N; i++) {
			int p = v[i].sec;
			for (int j = head[p]; j; j = nxt[j])
				if (val[ adj[j] ] < val[p]) {
					int q = Disjoint_set::getf(adj[j]);
					mxpos[j] = pos[q];
					Disjoint_set::merge(p, q);
				} else {
					mxpos[j] = 0;
				}
			int q = Disjoint_set::getf(p);
			pos[q] = p;
		}

		for (int i = 1; i <= N; i++)
			visited[i] = false;
		Solve(v[N].sec);
		for (int i = 1; i <= N; i++)
			printf("%d\n", F[i] + 1);
	}
	return 0;
}