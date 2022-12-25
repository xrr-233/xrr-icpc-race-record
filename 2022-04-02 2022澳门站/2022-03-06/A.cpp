#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int MAXN = 1e5;
int a[MAXN + 1];
bool cmp(int a, int b) {
	return a > b;
}
int main() {
	int T, n, ans;
	scanf("%d", &T);
	for(int o = 1; o <= T; o++) {
		scanf("%d", &n);
		for(int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
		}
		sort(a, a + n, cmp);
		/*for(int i = 0; i < n; i++) {
			printf("%d ", a[i]);
		}
		printf("\n");*/
		ans = 0;
		for(int i = 0; i < n; i++) {
			if((i + 1) % 3 != 0)
				ans += a[i];
		}
		printf("Case #%d: %d\n", o, ans);
	}
	return 0;
}
