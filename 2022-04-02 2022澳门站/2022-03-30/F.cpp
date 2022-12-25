#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
const int MAXN = 1e5;
const int MAXM = 1e5;
const int MOD = 1e9 + 7;
int a[MAXN + 1];
int b[MAXM + 1];
bool visit_a[MAXN + 1];
bool visit_b[MAXM + 1];
int map_a[MAXN + 1];
int map_b[MAXM + 1];
vector<pair<int, int> > vec_a;
vector<pair<int, int> > vec_b;
long long fast_power(int n, int m)  {
	long long res = 1ll;
	while(m) {
		if(m & 1)
			res = 1ll * res * n % MOD;
  		n = 1ll * n * n % MOD;
  		m >>= 1;
 	}
 	return res;
}

int main() {
	int n, m, T = 0;
	long long ans, sum;
	// cin >> n >> m;
	// cout << fast_power(n, m) << endl;
	while(~scanf("%d%d", &n, &m)) {
		ans = 0;
		T++;
		memset(visit_a, 0, sizeof(visit_a));
		memset(visit_b, 0, sizeof(visit_b));
		memset(map_a, 0, sizeof(map_a));
		memset(map_b, 0, sizeof(map_b));
		vec_a.clear();
		vec_b.clear();
		for(int i = 0; i < n; i++)
			scanf("%d", &a[i]);
		for(int i = 0; i < m; i++)
			scanf("%d", &b[i]);
		for(int i = 0; i < n; i++) {
			if(!visit_a[i]) {
				int ring_size = 0;
				int at = i;
				while(!visit_a[at]) {
					visit_a[at] = 1;
					at = a[at];
					ring_size++;
				}
				map_a[ring_size]++;
			}
		}
		for(int i = 0; i < m; i++) {
			if(!visit_b[i]) {
				int ring_size = 0;
				int at = i;
				while(!visit_b[at]) {
					visit_b[at] = 1;
					at = b[at];
					ring_size++;
				}
				map_b[ring_size]++;
			}
		}
		for(int i = 1; i <= n; i++) {
			//printf("%d ", map_a[i]);
			if(map_a[i] > 0)
				vec_a.push_back(make_pair(i, map_a[i]));
		}
		//printf("\n");
		for(int i = 1; i <= m; i++) {
			//printf("%d ", map_b[i]);
			if(map_b[i] > 0)
				vec_b.push_back(make_pair(i, map_b[i]));
		}
		//printf("\n");
		for(int i = 0; i < vec_a.size(); i++) {
			sum = 0;
			//printf("i iter %d:\n", i);
			for(int j = 0; j <= vec_b.size(); j++) {
				//printf("j iter %d:\n", j);
				if((vec_b[j].first > vec_a[i].first) || j == vec_b.size()) {
					if(i == 0) {
						ans = fast_power(sum, vec_a[i].second);
					}
					else {
						ans = (ans * fast_power(sum, vec_a[i].second)) % MOD;
					}
					break;
				}
				else if(vec_a[i].first % vec_b[j].first == 0) {
					sum += vec_b[j].first * vec_b[j].second;
				}
				//printf("sum: %d\n", sum);
			}
		}
		printf("Case #%d: %d\n", T, ans);
	}
}
