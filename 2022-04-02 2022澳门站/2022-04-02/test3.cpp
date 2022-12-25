#include <iostream>
#include <cstring>
using namespace std;
const int MAXN = 1e5;
const int MAXK = 1e5;
int satisfaction[MAXN + 5];
int like[MAXN + 5];
int bucket[MAXK + 5];
bool isOdd[MAXN + 5];
int main() {
	int T, n, k, m, round, piece;
	scanf("%d", &T);
	while(T--) {
		scanf("%d%d%d", &n, &k, &m);
		memset(satisfaction, 0, sizeof(satisfaction));
		memset(bucket, 0, sizeof(bucket));
		memset(isOdd, false, sizeof(isOdd));
		for(int i = 0; i < n; i++) {
			scanf("%d", &like[i]);
			bucket[like[i]]++;
			if(bucket[like[i]] % 2 == 1)
				isOdd[i] = true;
		}
		//for(int i = 1; i <= k; i++)
		//	printf("%d ", bucket[i]);
		//for(int i = 0; i < n; i++)
		//	printf("%d ", isOdd[i]);
		round = (m - 1) / n + 1;
		piece = (m - 1) % n;
		for(int i = 0; i < n; i++) {
			int temp_round;
			if(i <= piece)
				temp_round = round;
			else
				temp_round = round - 1;
			if(bucket[like[i]] % 2 == 0) {
				if(isOdd[i])
					satisfaction[i] = 0;
				else
					satisfaction[i] = temp_round;
			}
			else {
				if(temp_round % 2 == 1) {
					if(isOdd[i])
						satisfaction[i] = temp_round / 2;
					else
						satisfaction[i] = temp_round / 2 + 1;
				}
				else {
					satisfaction[i] = temp_round / 2;
				}
			}
		}
		for(int i = 0; i < n - 1; i++)
			printf("%d ", satisfaction[i]);
		printf("%d\n", satisfaction[n - 1]);
	}
}
