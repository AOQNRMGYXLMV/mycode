#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

const double eps = 1e-9;
const double PI = acos(-1.0);

int dcmp(double x) {
	if(fabs(x) < eps) return 0;
	return x < 0 ? -1 : 1;
}

struct Point
{
	double x, y;
	
	Point(double x = 0, double y = 0): x(x), y(y) {}
	
	void read() { scanf("%lf%lf", &x, &y); }
	
	Point operator - (const Point& t) const {
		return Point(x - t.x, y - t.y);
	}

	bool operator < (const Point& t) const {
		return x < t.x || (x == t.x && y < t.y);
	}
};

double Dot(const Point& A, const Point& B) {
	return A.x * B.x + A.y * B.y;
}

double Length(const Point& A) { return sqrt(Dot(A, A)); }

vector<Point> seg;

int main()
{
	Point C1, C2;
	double r1, r2;
	int v, T;
	C1.read();
	scanf("%d%d", &v, &T);
	r1 = (double)v * T;

	int n; scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		C2.read(); scanf("%lf", &r2);

        

		double d = Length(C1 - C2);
		if(dcmp(d - r2) <= 0) {
            if(n == 1 && dcmp(r2 - 1e9) == 0) printf("%.11f\n", 0.5);
			else printf("%.11f\n", 1.0);
			return 0;
		}
		if(dcmp(d - r1 - r2) >= 0) continue;

		double ang1, ang2 = atan2(C2.y-C1.y, C2.x-C1.x), ang3, delta;
		if(dcmp(r1*r1 - (d*d - r2*r2)) >= 0) {
			delta = asin(r2 / d);
		} else {
			delta = acos((r1*r1+d*d-r2*r2) / (r1*d*2.0));
		}

		ang1 = ang2 - delta;
		ang3 = ang2 + delta;
		
		int d1 = dcmp(ang1 + PI), d2 = dcmp(PI - ang3);
		if(d1 >= 0 && d2 >= 0) {
			seg.push_back(Point(ang1, ang3));
		} else if(d1 < 0) {
			seg.push_back(Point(ang1 + PI * 2, PI));
			seg.push_back(Point(-PI, ang3));
		} else {
			seg.push_back(Point(ang1, PI));
			seg.push_back(Point(-PI, ang3 - PI * 2));
		}
	}

	sort(seg.begin(), seg.end());
	if(seg.empty()) { printf("%.11f\n", 0.0); return 0; }
	Point cur = seg[0];
	double len = 0;
	for(int i = 1; i < seg.size(); i++) {
		if(dcmp(cur.y - seg[i].x) >= 0) {
			cur.y = max(cur.y, seg[i].y);
		} else {
			len += cur.y - cur.x;
			cur = seg[i];
		}
	}
	len += cur.y - cur.x;

	printf("%.11lf\n", len / PI / 2);

	return 0;
}
