#include <iostream>
using namespace std;
int digui(int m, int n) {
	if(m == 1 || n == 1) {
		if(m == n)
			return 4;
		else
			return 2;
	}	
	else if(m == 2 || n == 2)
		return m * n;
	return 4 + digui(m - 2, n - 2);
}
int main() {
	int T, m, n;
	scanf("%d", &T);
	for(int p = 1; p <= T; p++) {
		scanf("%d %d", &m, &n);
		if(m == 1 && n == 1)
			printf("Case #%d: 1\n", p);
		else {
			if(n > m) {
				int temp = n;
				n = m;
				m = temp;
			}
			printf("Case #%d: %d\n", p, digui(m, n));
		}
	}
	return 0;
}
