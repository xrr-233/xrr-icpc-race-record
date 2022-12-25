#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
	
	int caseNum;
	cin >> caseNum;
	while (caseNum--) {
		double a, b, c;
		double x0, x1, y0, y1, y2;
		//ax^2 + bx + c = y0 c' = c - y0
		cin >> a >> b >> c;
		cin >> x0 >> x1 >> y0 >> y1 >> y2;
		if (b * b - 4 * a * (c - y0) < 0) {
			cout << "No\n";
		}
		else {
			double touchBasket = (- b - sqrt(b * b - 4 * a * (c - y0))) / (2 * a);
			double anotherRoot = (- b + sqrt(b * b - 4 * a * (c - y0))) / (2 * a);
			if (anotherRoot >= x0 && anotherRoot <= x1) {
				cout << "No\n";
			}
			else {
				double touchBoard = a * x1 * x1 + b * x1 + c;
				if ((touchBasket > x0 && touchBasket < x1) || (touchBasket > x1 && touchBasket < 2 * x1 - x0 && touchBoard >= y0 && touchBoard <= y2)) {
					cout << "Yes\n";
				}
				else {
					cout << "No\n";
				}
			}
		}
	}
	return 0;
}

