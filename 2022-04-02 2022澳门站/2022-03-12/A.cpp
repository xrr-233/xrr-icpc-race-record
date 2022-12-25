#include <bits/stdc++.h>
using namespace std;

const int Max_N = 100005;
const int Mod = 1000000007;

int fexp(int base, int exp) {
	int ret = 1;
	for (; exp; exp >>= 1) {
		if (exp & 1)
			ret = 1LL * ret * base % Mod;
		base = 1LL * base * base % Mod;
	}
	return ret;
}

int Cases, N, K;
int dfac[Max_N], fac[Max_N], inv[Max_N];

int main() {
	fac[0] = 1;
	for (int i = 1; i < Max_N; i++)
		fac[i] = 1LL * fac[i - 1] * i % Mod;
	inv[Max_N - 1] = fexp(fac[Max_N - 1], Mod - 2);
	for (int i = Max_N - 2; i >= 0; i--)
		inv[i] = 1LL * inv[i + 1] * (i + 1) % Mod;
	
	scanf("%d", &Cases);
	for (int cases = 1; cases <= Cases; cases++) {
		scanf("%d%d", &N, &K);
		K = min(N, K - 1);
		dfac[0] = 1;
		for (int i = 1; i <= K; i++)
			dfac[i] = 1LL * dfac[i - 1] * (N - i + 1) % Mod;
		int ans = fexp(2, N);
		for (int i = 0; i <= K; i++)
			ans = (ans - 1LL * dfac[i] * inv[i]) % Mod;
		ans = (ans + Mod) % Mod;
		printf("Case #%d: %d\n", cases, ans);
	}
	return 0;
}

// by ljq 
