#include <bits/stdc++.h>
using namespace std;

const int Max_N = 25;

int Cases, G;
string toCheck;
string listOfSchool[6][Max_N];

int main() {
	cin >> Cases;
	for (int cases = 1; cases <= Cases; cases++) {
		cin >> G >> toCheck;
		for (int i = 0; i <= 5; i++)
			for (int j = 1; j <= 20; j++) {
				cin >> listOfSchool[i][j];
			}
		
		int ret = -1;
		for (int x = G; x >= 0; x--) {
			map<string, bool> M;
			int cnt = 0;
			for (int i = 1; cnt < x; i++)
				for (int j = 0; j < 5 && cnt < x; j++)
					if (!M.count(listOfSchool[j][i])) {
						M[ listOfSchool[j][i] ] = true;
						++cnt;
					}
			for (int i = 1; cnt < G; i++)
				if (!M.count(listOfSchool[5][i])) {
					M[ listOfSchool[5][i] ] = true;
					++cnt;
				}
			if (!M.count(toCheck)) {
				ret = G - x;
				break;
			}
		}
		if (ret == -1)
			printf("Case #%d: ADVANCED!\n", cases);
		else {
			printf("Case #%d: %d\n", cases, ret);
		}
	}
	return 0;
}