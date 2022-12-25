#define B cout << "BreakPoint" << endl;
#define O(x) cout << #x << " " << x << endl;
#define O_(x) cout << #x << " " << x << " ";
#define Msz(x) cout << "Sizeof " << #x << " " << sizeof(x)/1024/1024 << " MB" << endl;
#include<cstdio>
#include<cmath>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
#define LL long long
const int inf = 1e9 + 9;
const int N = 2e5 + 5;
using namespace std;
inline LL read() {
	LL s = 0,w = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9') {
		if(ch == '-')
			w = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9') {
		s = s * 10 + ch - '0';
		ch = getchar();
	}
	return s * w;
}
int n;
LL x[N],y[N];
void init() {
    for (int i = 1; i <= n+2; i++) x[i] = 0,y[i] = 0;
    for (int i = 1; i <= n; i++) x[i] = read(),y[i] = read();
    int res = min(2, n);
    if (n > 1) {
        for (int o = 1; o <= 100 ; o++) {
            int a = rand() % n + 1,b = rand() % n + 1;
            while (a == b) {
                a = rand() % n + 1;
                b = rand() % n + 1;
            }
            int cnt = 0;
            for (int i = 1; i <= n; i++) {
                LL x1 = x[i] - x[a], y1 = y[i] - y[a];
                LL x2 = x[i] - x[b], y2 = y[i] - y[b];
                if (x1 * y2 == y1 * x2) ++cnt;
            }
            res = max(res, cnt);
        }
    }
    int ans = max(n % 3, res - 2 * (n - res));
    printf("%d\n", ans);
}
int main(){
    while(cin>>n) init();
    return 0;
}
