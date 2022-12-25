#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#define ll long long
using namespace std;
class Point {
	public:
		ll x;
		ll y;
		double angle;
		//double jijiao_angle;
};
class Vector2 {
	public:
		ll x;
		ll y;
		Vector2(int x, int y) {
			this->x = x;
			this->y = y;
		}
};
double cross(Vector2 base, Vector2 aim) {
	return base.x * aim.y - base.y * aim.x;
}
const int MAXN = 1e6;
const int MAXX = 1e9;
Point point[MAXN + 5];
double get_dis(ll x, ll y) {
	return sqrt(double(x * x + y * y));
}
bool cmp(Point a, Point b) {
	return a.angle < b.angle;
}
int sta[MAXN + 5];
vector<Point> points;
void tubao(int n, int mini) {
	int Size = 0;
	sta[++Size] = (mini + n - 1) % n;
	sta[++Size] = mini;
	for(int i = 1; i <= n; i++) {
		Point nextPoint = Point[(mini + i) % n], lastPoint, thisPoint;
		do {
			lastPoint = sta[Size - 1];
			thisPoint = sta[Size];
			Vector2 lastVector = new Vector2(thisPoint.x - lastPoint.x, thisPoint.y - lastPoint.y);
			Vector2 thisVector = new Vector2(nextPoint.x - thisPoint.x, nextPoint.y - thisPoint.y);
			if(cross(lastVector, thisVector) >= 0)
				Size--;
			else {
				sta[++Size] = (mini + i) % n;
				break;
			}
		}
		while(true);
	}
	for(int i = 2; i <= Size; i++)
		points.push_back(Point[sta[i]]);
	sort(points.begin(), points.end(), cmp);
	int l = points.size();
	for(int i = 0; i < l; i++) {
		points.push_back(point[i]);
		point[l + i].angle += 2 * acos(-1);
	}
	int ll = 0, rr = 0;
	
}
int main() {
	int T, n;
	ll x, y, minx = MAXX, miny = MAXX, mini;
	scanf("%d", &T);
	while(T--) {
		points.clear();
		scanf("%d", &n);
		for(int i = 0; i < n; i++) {
			scanf("%lld%lld", &x, &y);
			point[i].x = x+;
			point[i].y = y;
			point[i].angle = acos(x / get_dis(x, y));
			if(y < miny || (y == miny && x < minx)) {
				minx = x;
				miny = y;
			}
			//if(y < 0)
			//	point[i].angle += acos(-1);
			//point[i].jijiao_angle = acos((x + MAXX) / get_dis(x + MAXX, y + MAXX));
			//cout << point[i].angle << endl;
		}
		sort(point, point + n, cmp);
		for(int i = 0; i < n; i++)
			if(point[i].x == minx && point[i].y == miny) {
				mini = i;
				break;
			}
		tubao(n, mini);
	}
}
