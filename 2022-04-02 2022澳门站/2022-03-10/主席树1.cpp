#include <iostream>
#include <cstdio>
using namespace std;
const int MAXN = 1e6;
const int MAXM = 1e6;
int a[MAXN + 1];
int n, m;

namespace SegmentTree {
	class SegNode {
		public:
			SegNode* left;
			SegNode* right;
			int value;
			SegNode() {
				this->left = NULL;
				this->right = NULL;
			}
	};
	SegNode* history[MAXM + 1];
	void init() {
		for(int i = 0; i <= m; i++)
			history[i] = new SegNode();
	}
	void build(SegNode* now_node, int l, int r) {
		if(l == r) {
			now_node->value = a[l];
			return;
		}
		int mid = (l + r) >> 1;
		now_node->left = new SegNode();
		now_node->right = new SegNode();
		build(now_node->left, l, mid);
		build(now_node->right, mid + 1, r);
	}
	void modify(SegNode* now_node, SegNode* hist_node, int l, int r, int loc, int value) {
		if(l == r && l == loc) {
			now_node->value = value;
			return;
		}
		int mid = (l + r) >> 1;
		if(loc <= mid) {
			now_node->right = hist_node->right;
			now_node->left = new SegNode();
			modify(now_node->left, hist_node->left, l, mid, loc, value);
		}
		else {
			now_node->left = hist_node->left;
			now_node->right = new SegNode();
			modify(now_node->right, hist_node->right, mid + 1, r, loc, value);
		}
	}
	int query(SegNode* now_node, int l, int r, int loc) {
		if(l == r && l == loc) {
			return now_node->value;
		}
		int mid = (l + r) >> 1;
		if(loc <= mid)
			return query(now_node->left, l, mid, loc);
		else
			return query(now_node->right, mid + 1, r, loc);
	}
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	SegmentTree::init();
	SegmentTree::build(SegmentTree::history[0], 1, n);
	int ver, op, loc, value;
	for (int i = 1; i <= m; i++) {
		scanf("%d%d%d", &ver, &op, &loc);
		if(op == 1) {
			scanf("%d", &value);
			SegmentTree::modify(SegmentTree::history[i], SegmentTree::history[ver], 1, n, loc, value);
		}
		else {
			SegmentTree::history[i] = SegmentTree::history[ver];
			printf("%d\n", SegmentTree::query(SegmentTree::history[i], 1, n, loc));
		}
		/*for(int j = 1; j <= n; j++)
			printf("%d ", SegmentTree::query(SegmentTree::history[i], j));
		printf("\n");*/
	}
	return 0;
}
// https://www.luogu.com.cn/problem/P3919
// MLE+TLE 看别人过的才100多MB，我这肯定有问题 
