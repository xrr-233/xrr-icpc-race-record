#include <iostream>
#include <cstdio>
#include <cstring>
#define MOD 998244353
using namespace std;

long long ans = 0;
long long list[10];
char S[100001];

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		memset(list, 0, sizeof(list));
		memset(S, '\0', sizeof(S));
		scanf("%s", S);
		//cout << S << endl;
		int l = strlen(S);
		/*for(int j = 0; j < 10; j++)
			cout << list[j] << ' ';
		cout << endl;*/
		for(int i = 0; i < l; i++) {
			if(S[i] == 'n') {
				list[2] += list[1];
				list[2] %= MOD;
				list[0] += 1;
				list[0] %= MOD;
			}
			else if(S[i] == 'u') {
				list[1] += list[0];
				list[1] %= MOD;
			}
			else if(S[i] == 'h') {
				list[8] += list[7];
				list[8] %= MOD;
				list[6] += list[5];
				list[6] %= MOD;
				list[5] += list[4];
				list[5] %= MOD;
				list[3] += list[2];
				list[3] %= MOD;
			}
			else if(S[i] == 'e') {
				list[7] += list[6];
				list[7] %= MOD;
				list[4] += list[3];
				list[4] %= MOD;
			}
			else if(S[i] == 'a') {
				list[9] += list[9];
				list[9] += list[8];
				list[9] %= MOD;
			}
			/*for(int j = 0; j < 10; j++)
				cout << list[j] << ' ';
			cout << endl;*/
		}
		printf("%d\n", list[9] % MOD);
	}
	return 0;
} 
