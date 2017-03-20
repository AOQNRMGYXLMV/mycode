#include <cstdio>
#include <cmath>
#include <algorithm>
using std::abs;
using std::swap;

const int maxn = 1010;

typedef long long LL;

struct Point
{
	int x, y;
	Point(int x = 0, int y = 0): x(x), y(y) {}
	void read() { scanf("%d%d", &x, &y); }
	Point operator - (const Point& t) const {
		return Point(x - t.x, y - t.y);
	}
};

int n, m;
Point p[maxn], dir[maxn];
int angle[maxn];

int sign(int x) { if(!x) return 0; return x > 0 ? 1 : -1; }

Point Normalize(Point A) {
	return Point(sign(A.x), sign(A.y));
}

int Cross(Point A, Point B) { return A.x * B.y - A.y * B.x; }

int Length(Point A) { if(A.x) return abs(A.x); return abs(A.y); }

int left, right, top, bottom;

bool intersect() {
	for(int i = 1; i <= n; i++) {
		if(p[i].x <= left && p[i+1].x <= left) continue;
		if(p[i].x >= right && p[i+1].x >= right) continue;
		if(p[i].y <= bottom && p[i+1].y <= bottom) continue;
		if(p[i].y >= top && p[i+1].y >= top) continue;
		return true;
	}
	return false;
}

int main()
{
	int q; scanf("%d", &q);
	while(q--) {
		scanf("%d%d", &n, &m);
		for(int i = 1; i <= n; i++) p[i].read();
		p[n + 1] = p[1];
		for(int i = 1; i <= n; i++) dir[i] = Normalize(p[i+1]-p[i]);
		dir[0] = dir[n];
		for(int i = 1; i <= n; i++) angle[i] = Cross(dir[i - 1], dir[i]);
		angle[n + 1] = angle[1];

		bool ok = true;
		for(int i = 1; i <= n; i++) {
			if(angle[i] < 0 && angle[i+1] < 0 && Length(p[i+1]-p[i]) < m) {
				ok = false; break;
			}

			if(dir[i].x) {
				int delta = m * dir[i].x;
				left = p[i].x; right = p[i+1].x;
				if(angle[i] > 0) left -= delta;
				if(angle[i+1] > 0) right += delta;
				top = p[i].y; bottom = top - delta;
			} else {
				int delta = m * dir[i].y;
				top = p[i].y; bottom = p[i+1].y;
				if(angle[i] > 0) top -= delta;
				if(angle[i+1] > 0) bottom += delta;
				left = p[i].x; right = left + delta;
			}
			if(left > right) swap(left, right);
			if(bottom > top) swap(bottom, top);
			if(intersect()) { ok = false; break; }
		}

		printf("%s\n", ok ? "Yes" : "No");
	}

	return 0;
}
