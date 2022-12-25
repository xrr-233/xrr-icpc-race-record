/*#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
class Hash {
	public:
		int id;
		bool available;
};
vector<vector<Hash*>> projects, profs;
int full_proj, ans;
bool project_available(int prof, int project) {
	vector<Hash*> temp_project = projects[project], temp_prof = profs[prof];
	for(int i = 0; i < temp_project.size() - 1; i++) {
		for(int j = 0; j < temp_prof.size(); j++){
			if(temp_project[i]->available && temp_project[i]->id == temp_prof[j]->id)
				return true;
		}
	}
	return false;
}
void recur(int layer, int max_layer) {
	if(layer == max_layer) {
		ans = max(ans, full_proj);
		//printf("OK with %d\n", full_proj);
		return;
	}
	//printf("!!!!!\n");
	recur(layer + 1, max_layer);
	for(int i = 0; i < projects.size(); i++) {
		//printf("Prof %d in %d: Proj %d\n", layer, max_layer, i);
		if(project_available(layer, i)) {
			vector<Hash*> temp_project = projects[i], temp_prof = profs[layer];
			vector<int> recover;
			int original_full_proj = full_proj;
			//for(int k = 0; k < temp_project.size() - 1; k++)
			//	printf("%d ", temp_project[k]->available);
			//printf("%d ", temp_project[temp_project.size() - 1]->id);
			//printf("\norig = %d full_proj = %d\n", original_full_proj, full_proj);
			for(int k = 0; k < temp_project.size() - 1; k++)
				for(int j = 0; j < temp_prof.size(); j++) {
					//printf("%d\n", k * temp_prof.size() + j);
					if(temp_project[k]->available && temp_project[k]->id == temp_prof[j]->id) {
						temp_project[k]->available = false;
						recover.push_back(k * temp_prof.size() + j);
						//temp_project[temp_project.size() - 1]->id++;
						//if(temp_project[temp_project.size() - 1]->id == temp_project.size() - 1)
						//	full_proj++;
					}
					//printf("%d->%d %d\n", temp_prof[j]->id, temp_project[k]->id, temp_project[k]->available);
				}
			bool flag = false;
			for(int k = 0; k < temp_project.size() - 1; k++)
				if(temp_project[k]->available)
					flag = true;
			if(!flag)
				full_proj++;
			//for(int k = 0; k < temp_project.size() - 1; k++)
			//	printf("%d ", temp_project[k]->available);
			//printf("%d ", temp_project[temp_project.size() - 1]->id);
			//printf("\norig = %d full_proj = %d\n", original_full_proj, full_proj);
			recur(layer + 1, max_layer);
			//printf("Prof %d in %d: Proj %d Recovering\n", layer, max_layer, i);
			int recover_ptr = 0;		
			for(int k = 0; k < temp_project.size() - 1; k++)
				for(int j = 0; j < temp_prof.size(); j++)
					if(k * temp_prof.size() + j == recover[recover_ptr]) {
						temp_project[k]->available = true;
						//temp_project[temp_project.size() - 1]->id--;
						recover_ptr++;
					}
			full_proj = original_full_proj;
			//for(int k = 0; k < temp_project.size() - 1; k++)
			//	printf("%d ", temp_project[k]->available);
			//printf("%d ", temp_project[temp_project.size() - 1]->id);
			//printf("\norig = %d full_proj = %d\n", original_full_proj, full_proj);
			recover.clear();
		}
	}
}
int main() {
	int T, n, m, v, d;
	scanf("%d", &T);
	for(int o = 1; o <= T; o++) {
		projects.clear();
		profs.clear();
		ans = 0;
		full_proj = 0;
		scanf("%d%d", &n, &m);
		for(int i = 0; i < n; i++) {
			vector<Hash*> project;
			scanf("%d", &v);
			for(int j = 0; j < v; j++) {
				scanf("%d", &d);
				Hash* h = new Hash();
				h->id = d;
				h->available = true;
				project.push_back(h);
			}
			Hash* h = new Hash(); // 计数用 
			h->id = 0;
			h->available = false;
			project.push_back(h);
			projects.push_back(project);
		}
		for(int i = 0; i < m; i++) {
			vector<Hash*> prof;
			scanf("%d", &v);
			for(int j = 0; j < v; j++) {
				scanf("%d", &d);
				Hash* h = new Hash();
				h->id = d;
				h->available = false;
				prof.push_back(h);
			}
			profs.push_back(prof);
		}
		recur(0, m);
		printf("Case #%d: %d\n", o, ans);
	}
} */
// 回溯不是正解，正解是状压
// 不过应该也没错啊，怎么过不去
#include <bits/stdc++.h>
using namespace std;

const int Max_N = 12;

int Cases, N, M, a[Max_N][4], b[Max_N][4], c[Max_N], d[Max_N], dp[Max_N][1 << Max_N];

bool cover(int i, int j, int k = N, int w = N) {
	bool tag = true;
	for (int t = 1; t <= d[i]; t++) {
		tag = false;
		for (int s1 = 1; s1 <= c[j]; s1++)
			if (b[i][t] == a[j][s1])
				tag = true;
		for (int s2 = 1; s2 <= c[k]; s2++)
			if (b[i][t] == a[k][s2])
				tag = true;
		for (int s3 = 1; s3 <= c[w]; s3++)
			if (b[i][t] == a[w][s3])
				tag = true;
		if (!tag)
			return false;
	}
	return true;
}

int main() {
	scanf("%d", &Cases);
	for (int cases = 1; cases <= Cases; cases++) {
		scanf("%d%d", &M, &N);
		for (int i = 1; i <= M; i++) {
			scanf("%d", &d[i]);
			for (int j = 1; j <= d[i]; j++)
				scanf("%d", &b[i][j]);
			sort(b[i] + 1, b[i] + 1 + d[i]);
		}
		for (int i = 0; i < N; i++) {
			scanf("%d", &c[i]);
			for (int j = 1; j <= c[i]; j++)
				scanf("%d", &a[i][j]);
			sort(a[i] + 1, a[i] + 1 + c[i]);
		}
		c[N] = 0;

		for (int i = 1; i <= M; i++) {
			for (int st = 0; st < (1 << N); st++)
				dp[i][st] = dp[i - 1][st];

			for (int j = 0; j < N; j++) {
				if (cover(i, j)) {
					for (int st = 0; st < (1 << N); st++) {
						if ((st >> j) & 1)
							continue;
						dp[i][st | (1 << j)] = max(dp[i][st | (1 << j)], dp[i - 1][st] + 1);
					}
				}
			}

			for (int j = 0; j < N; j++) {
				for (int k = 0; k < N; k++) {
					if (cover(i, j, k)) {
						for (int st = 0; st < (1 << N); st++) {
							if (((st >> j) & 1) || ((st >> k) & 1))
								continue;
							dp[i][st | (1 << j) | (1 << k)] = max(dp[i][st | (1 << j) | (1 << k)], dp[i - 1][st] + 1);
						}
					}
				}
			}

			for (int j = 0; j < N; j++) {
				for (int k = 0; k < N; k++) {
					for (int w = 0; w < N; w++) {
						if (cover(i, j, k, w)) {
							for (int st = 0; st < (1 << N); st++) {
								if (((st >> j) & 1) || ((st >> k) & 1) || ((st >> w) & 1))
									continue;
								dp[i][st | (1 << j) | (1 << k) | (1 << w)] = max(dp[i][st | (1 << j) | (1 << k) | (1 << w)], dp[i - 1][st] + 1);
							}
						}
					}
				}
			}
		}
		printf("Case #%d: %d\n", cases, dp[M][(1 << N) - 1]);
	}
	return 0;
} 
/*
4
3 4
3 40 77 64
3 10 40 20
3 40 20 77
2 40 77
2 77 64
2 40 10
2 20 77
4 6
3 1 2 3
3 4 5 6
3 7 8 9
2 10 11
2 1 5
2 2 7
2 10 12
2 4 6
2 3 7
2 8 9
3 4
3 40 77 64
3 10 40 20
3 40 20 77
2 40 77
2 77 64
2 40 10
2 20 77
4 6
3 1 2 3
3 4 5 6
3 7 8 9
2 10 11
2 1 5
2 2 7
2 10 12
2 4 6
2 3 7
2 8 9
*/
/*
1
3 3
3 1 2 3
3 4 5 6
3 7 8 9
2 10 11
2 3 5
2 4 6
*/
