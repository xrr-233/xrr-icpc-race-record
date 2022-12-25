#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;
string months[12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
bool is[366];

int get_day(string a, string b) {
	int m, d = 0, ans = 0;
	for(int i = 0; i < 12; i++)
		if(a == months[i]) {
			m = i + 1;
			break;
		}
	for(int i = 0; i < b.size(); i++)
		if(b[i] >= '0' && b[i] <= '9')
			d = d * 10 + (b[i] - '0');
		else
			break;
	for(int i = 1; i < m; i++) {
		ans += days[i - 1];
	}
	ans += d;
	return ans;
}
int main() {
	int T, n;
	string a, b;
	scanf("%d", &T);
	for(int p = 0; p < T; p++) {
		memset(is, 0, sizeof(is));
		scanf("%d", &n);
		for(int o = 0; o < n; o++) {
			cin >> a >> b;
			cout << o << endl;
			if(get_day(a, b) <= 365)
				is[get_day(a, b)] = true;
			else
				printf("!");
		}
		cin >> a >> b;
		bool flag = false;
		for(int o = get_day(a, b) + 1; o <= 365; o++) {
			if(is[o]) {
				printf("Case #%d: ", p + 1);
				int dd = 0;
				for(int i = 0; i < 12; i++) {
					if(o < dd + days[i]) {
						cout << months[i] << ' ' << o - dd;
						if(o - dd == 1 || o - dd == 21 || o - dd == 31)
							cout << "st" << endl;
						else if(o - dd == 2 || o - dd == 22)
							cout << "nd" << endl;
						else if(o - dd == 3 || o - dd == 23)
							cout << "rd" << endl;
						else
							cout << "th" << endl;
						break;
					}
					dd += days[i];
				}
				flag = true;
				break;
			}
		}
		if(!flag)
			printf("Case #%d: See you next year\n", p + 1);
	}
	return 0;
}
