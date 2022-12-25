#include <iostream>
#include <cstdio>
#include <map>
#include <vector>
#include <cmath>
#include <cstring>
#define maxn 100000
using namespace std;

map <int, int> M;
vector <vector <int> > V;

bool isprime[maxn + 1];
int prime[10000];
void Euler() {
	memset(isprime, false, sizeof(isprime));
	memset(prime, 0, sizeof(prime));
    for(int i = 2; i <= maxn; i++) {
        if(!isprime[i]){
            prime[++prime[0]] = i;
        }
    	//cout << prime[0] << endl;
        for(int j = 1; j <= prime[0] && prime[j] * i <= maxn; j++){
            isprime[prime[j] * i] = 1;
            if(i % prime[j] == 0)
				break;
        }
    }
}

bool ef(int i, int l, int r, int N) {
	// 因数为i, 寻找最左的l/比l大的数与最右的r/比r小的数, 看两个指针中间的数字是否比N多或等于N
	if(M[i] == 0)
		return false;
	vector <int> temp = V[M[i]];
	//cout << i << ':' << endl;
	//for(int i = 0; i < temp.size(); i++)
	//	cout << temp[i] << ' ';
	//cout << endl;
	int p1, p2;
	int L = 0, R = temp.size() - 1, mid;
	while(L != R) {
		if(R - L == 1) {
			p1 = R;
			break;
		}
		mid = (L + R) >> 1;
		if(temp[mid] < l)
			L = mid;
		else if(temp[mid] > l)
			R = mid;
		else {
			p1 = mid;
			break;
		}
	}
	while(p1 > 0 && temp[p1 - 1] >= l)
		p1--;
	L = 0, R = temp.size() - 1;
	if(L == R) {
		//cout << 0 << ' ' << 0 << endl;
		if(N <= 1)
			return true;
		else
			return false;
	}
	while(L != R) {
		if(R - L == 1) {
			p2 = L;
			break;
		}
		mid = (L + R) >> 1;
		if(temp[mid] > r)
			R = mid;
		else if(temp[mid] < r)
			L = mid;
		else {
			p2 = mid;
			break;
		}
	}
	while(p2 < temp.size() - 1 && temp[p2 + 1] <= r)
		p2++;
	//cout << p1 << ' ' << p2 << endl;
	if(p2 - p1 + 1 >= N)
		return true;
	else
		return false;
} 

void fj(int t, int x) {
	if(t == 1)
		return;
	if(isprime[t]) {
		for(int i = 1; prime[i] <= sqrt(t); i++) {
			while(t % prime[i] == 0) {
				if(M[prime[i]] == 0) {
					V.resize(V.size() + 1);
					M[prime[i]] = V.size() - 1;
				}
				V[M[prime[i]]].push_back(x);
				t /= prime[i];
			}
		}
		if(t == 1)
			return;
	}
	if(M[t] == 0) {
		V.resize(V.size() + 1);
		M[t] = V.size() - 1;
	}
	V[M[t]].push_back(x);
}

bool fj2(int t, int l, int r) {
	int N = 0;
	if(t > 1 && isprime[t]) {
		for(int i = 1; prime[i] <= sqrt(t); i++) {
			N = 0;
			bool flag = false;
			while(t % prime[i] == 0) {
				if(!flag)
					flag = true;
				N++;
				t /= prime[i];
			}
			if(flag && !ef(prime[i], l, r, N))
				return false;
		}
	}
	if(t == 1)
		return true;
	return ef(t, l, r, 1);
}

int main() {
	Euler();
	/*
	cout << prime[0] << endl;
	for(int i = 1; i <= prime[0]; i++)
		cout << prime[i] << ' ';
	*/
	int T, n, m, t, l, r, d;
	scanf("%d", &T);
	while(T--) {
		M.clear();
		V.clear();
		V.resize(1);
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; i++) {
			scanf("%d", &t);
			fj(t, i);
		}
		for (int i = 0; i < m; i++) {
			scanf("%d%d%d", &l, &r, &d);
			if(d == 1) {
				printf("Yes\n");
			}
			else {
				if(!fj2(d, l - 1, r - 1))
					printf("No\n");
				else
					printf("Yes\n");
			}
		}
	}
	return 0;
} 

