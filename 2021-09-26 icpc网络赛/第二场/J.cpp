#include <iostream>
#include <cstdio>
#include <map>
#include <algorithm>
using namespace std;
struct Node {
	int x, y, h;
	double s;
};
Node arr[250001];
int Size = 0;
bool cmp(Node a, Node b) {
	return a.h < b.h;
}
map <pair<int, int>, int> M;
int main() {
	int n, h;
	double m;
	scanf("%d%lf", &n, &m);
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			scanf("%d", &h);
			arr[Size].x = i;
			arr[Size].y = j;
			arr[Size].h = h;
			arr[Size++].s = m;
		}
	}
	/*for(int i = 0; i < n * n; i++)
		printf("%d ", arr[i].h);
	printf("\n");*/
	sort(arr, arr + n * n, cmp);
	/*for(int i = 0; i < n * n; i++)
		printf("%d ", arr[i].h);
	printf("\n");*/
	for(int i = 0; i < n * n; i++) {
		M[make_pair(arr[i].x, arr[i].y)] = i;
	}
	bool up, down, left, right;
	double able;
	for(int i = n * n - 1; i >= 0; i--) {
		//printf("%d %d %d\n", arr[i].x, arr[i].y, arr[i].h);
		up = 0, down = 0, left = 0, right = 0;
		able = 0;
		if(arr[i].y > 0 && arr[M[make_pair(arr[i].x, arr[i].y - 1)]].h < arr[i].h) {
			up = 1;
			able++;
		}
		if(arr[i].y < n - 1 && arr[M[make_pair(arr[i].x, arr[i].y + 1)]].h < arr[i].h) {
			down = 1;
			able++;
		}
		if(arr[i].x > 0 && arr[M[make_pair(arr[i].x - 1, arr[i].y)]].h < arr[i].h) {
			left = 1;
			able++;
		}
		if(arr[i].x < n - 1 && arr[M[make_pair(arr[i].x + 1, arr[i].y)]].h < arr[i].h) {
			right = 1;
			able++;
		}
		if(up)
			arr[M[make_pair(arr[i].x, arr[i].y - 1)]].s += arr[i].s / able;
		if(down)
			arr[M[make_pair(arr[i].x, arr[i].y + 1)]].s += arr[i].s / able;
		if(left)
			arr[M[make_pair(arr[i].x - 1, arr[i].y)]].s += arr[i].s / able;
		if(right)
			arr[M[make_pair(arr[i].x + 1, arr[i].y)]].s += arr[i].s / able;
		if(able)
			arr[i].s = 0;
		/*printf("----\n");
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n - 1; j++)
				printf("%.6lf ", arr[M[make_pair(i, j)]].s);
			printf("%.6lf\n", arr[M[make_pair(i, n - 1)]].s);
		}
		printf("----\n");*/
	}
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++)
			if(arr[M[make_pair(i, j)]].h == 0)
				printf("%.6lf ", arr[M[make_pair(i, j)]].s);
			else
				printf("0 ");
		printf("\n");
	}
}
/*
4 3
1 8 2 5
0 7 2 7
9 7 7 1
8 2 5 0
*/
