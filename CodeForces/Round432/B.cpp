#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <set>
#include <vector>
#include <iostream>
#include <string>
#include <cmath>
using namespace std;
#define REP(i, a, b) for(int i = a; i < b; i++)
#define PER(i, a, b) for(int i = b - 1; i >= a; i--)
#define SZ(a) ((int)a.size())
#define MP make_pair
#define PB push_back
#define EB emplace_back
#define ALL(a) a.begin(), a.end()
typedef long long LL;
typedef pair<int, int> PII;

struct Point {
	LL x, y;

	Point() {}
	Point(LL x, LL y): x(x), y(y) {}

	void read() { scanf("%lld%lld", &x, &y); }

	Point operator - (const Point& t) const {
		return Point(x - t.x, y - t.y);
	}
};

Point p[3];

LL Dist2(const Point& A, const Point& B) {
	return (A.x-B.x)*(A.x-B.x) + (A.y-B.y)*(A.y-B.y);
}

LL Cross(const Point& A, const Point& B) {
	return A.x*B.y - A.y*B.x;
}

int main() {
	REP(i, 0, 3) p[i].read();
	if(Cross(p[2] - p[1], p[1] - p[0]) == 0) {
		printf("No\n");
	} else if(Dist2(p[0], p[1]) != Dist2(p[1], p[2])) {
		printf("No\n");
	} else {
		printf("Yes\n");
	}

	return 0;
}


