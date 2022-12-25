#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <vector>
#define INF 500005
using namespace std;

struct node {
	int a, i;
	node() {}
	node(int x, int y) : a(x), i(y) {}
	bool operator < (const node t) const
    {
        return a < t.a;
    }
}arr[100001];
vector<node> start_a_queue[500001];

bool cmp1(node a, node b) {
	if(a.a != b.a)
		return a.a < b.a;
	else
		return a.i > b.i;
}
bool cmp2(node a, node b) {
	if(a.a != b.a)
		return a.a > b.a;
	else
		return a.i > b.i;
}
bool cmp3(node a, node b) {
	return a.a > b.a;
}
bool cmp4(node a, node b) {
	return a.a < b.a;
}

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		int n, m, L = 0, temp_m;
		scanf("%d%d", &n, &m);
		for(int i = 0; i < n; i++) {
			scanf("%d", &arr[i].a);
			L += arr[i].a;
			arr[i].a = L;
			arr[i].i = i + 1;
		}
		if(L == 0) {
			map<int, int> M;
			for(int i = n - 1; i >= 0; i--)
				M[arr[i].a] = arr[i].i;
			for(int i = 0; i < m; i++) {
				scanf("%d", &temp_m);
				if(temp_m == 0)
					printf("0\n");
				else if(M[temp_m] == 0)
					printf("-1\n");
				else
					printf("%d\n", M[temp_m]);
			}
		} 
		else if(L > 0) {
			sort(arr, arr + n, cmp1);
			for(int i = 0; i < L; i++)
				start_a_queue[i].clear();
			for(int i = n - 1; i >= 0; i--) {
				int mod = arr[i].a % L;
				if(mod < 0)
					mod += L;
				if(start_a_queue[mod].size() == 0) {
					node temp_node;
					temp_node.a = arr[i].a;
					temp_node.i = arr[i].i;
					start_a_queue[mod].push_back(temp_node);
				}
				else if(arr[i].a != start_a_queue[mod][start_a_queue[mod].size() - 1].a) {
					node temp_node;
					temp_node.a = arr[i].a;
					temp_node.i = arr[i].i;
					start_a_queue[mod].push_back(temp_node);
				}
			}
			for(int i = 0; i < m; i++) {
				scanf("%d", &temp_m);
				if(temp_m == 0) {
					printf("0\n");
					continue;
				}
				int id = temp_m % L;
				if(id < 0)
					id += L;
				if(start_a_queue[id].size() == 0)
					printf("-1\n");
				else {// 2 -2
					int start_a_ptr = lower_bound(start_a_queue[id].begin(), start_a_queue[id].end(), node(temp_m, 0), cmp3) - start_a_queue[id].begin();
					//printf("%d\n", start_a_ptr);
					if(start_a_ptr < start_a_queue[id].size()) {
						int x = (temp_m - start_a_queue[id][start_a_ptr].a) / L;
						printf("%d\n", x * n + start_a_queue[id][start_a_ptr].i);
					}
					else
						printf("-1\n");
				}
			}
		}
		else if(L < 0) {
			sort(arr, arr + n, cmp2);
			for(int i = 0; i < -L; i++)
				start_a_queue[i].clear();
			for(int i = n - 1; i >= 0; i--) {
				int mod = arr[i].a % -L;
				if(mod < 0)
					mod += -L;
				if(start_a_queue[mod].size() == 0) {
					node temp_node;
					temp_node.a = arr[i].a;
					temp_node.i = arr[i].i;
					start_a_queue[mod].push_back(temp_node);
				}
				else if(arr[i].a != start_a_queue[mod][start_a_queue[mod].size() - 1].a) {
					node temp_node;
					temp_node.a = arr[i].a;
					temp_node.i = arr[i].i;
					start_a_queue[mod].push_back(temp_node);
				}
			}
			for(int i = 0; i < m; i++) {
				scanf("%d", &temp_m);
				if(temp_m == 0) {
					printf("0\n");
					continue;
				}
				int id = temp_m % -L;
				if(id < 0)
					id += -L;
				if(start_a_queue[id].size() == 0)
					printf("-1\n");
				else {
					int start_a_ptr = lower_bound(start_a_queue[id].begin(), start_a_queue[id].end(), node(temp_m, 0), cmp4) - start_a_queue[id].begin();
					//printf("%d\n", start_a_ptr);
					if(start_a_ptr < start_a_queue[id].size()) {
						int x = (temp_m - start_a_queue[id][start_a_ptr].a) / L;
						printf("%d\n", x * n + start_a_queue[id][start_a_ptr].i);
					}
					else
						printf("-1\n");
				}
			}
		}
	}
	return 0;
}
