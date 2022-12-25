#include <bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
#define mp make_pair

typedef long long int64;
typedef pair<int, int> PII;

const int Max_N = 205;
const int Max_M = 10005;
const int INF = 0x3F3F3F3F;

int Cases, N, M, K, w[Max_N], x[Max_N], p[Max_N];
vector<PII> r[Max_N];

void relax() {
	bool tag = false;
	do {
		tag = false;
		for (int i = 1; i <= K; i++) {
			int nw = 0;
			for (size_t j = 0; j < r[i].size(); j++) {
				nw =  min(nw + w[ r[i][j].fir ] * r[i][j].sec, M + 1);
			}
			if (nw < w[ x[i] ]) {
				w[ x[i] ] = nw;
				tag = true;
			}
		}
	} while (tag);
}

int f[Max_N][Max_M];

void dp() {
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= M; j++)
			f[i][j] = f[i - 1][j];
		for (int j = w[i]; j <= M; j++) {
			f[i][j] = max(f[i][j - w[i]] + p[i], f[i][j]);
		}
	}
}


int main() {
	scanf("%d", &Cases);
	for (int cases = 1; cases <= Cases; cases++) {
		scanf("%d%d%d", &M, &N, &K);
		for (int di, i = 1; i <= N; i++) {
			scanf("%d", &di);
			if (di == 1)
				scanf("%d", &w[i]);
			else
				w[i] = M + 1;
			scanf("%d", &p[i]);
		}
		for (int yi, i = 1; i <= K; i++) {
			scanf("%d%d", &x[i], &yi);
			r[i].clear();
			for (int u, v, j = 1; j <= yi; j++) {
				scanf("%d%d", &u, &v);
				r[i].push_back(mp(u, v));
			}
		}

		relax();

		dp();

		printf("Case #%d: %d\n", cases, f[N][M]);
	}
	return 0;
}