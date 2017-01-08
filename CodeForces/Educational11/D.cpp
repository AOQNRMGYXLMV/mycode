#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long LL;

struct Point
{
	int x, y;
	Point(int x = 0, int y = 0): x(x), y(y) {}
	void read() { scanf("%d%d", &x, &y); }
};

bool operator < (const Point& A, const Point& B) {
	return A.x < B.x || (A.x == B.x && A.y < B.y);
}

Point operator + (const Point& A, const Point& B) {
	return Point(A.x + B.x, A.y + B.y);
}

bool operator == (const Point& A, const Point& B) {
	return A.x == B.x && A.y == B.y;
}

const int maxn = 2000 + 10;

int n;
Point p[maxn], mid[maxn * maxn];

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) p[i].read();
	int tot = 0;
	for(int i = 1; i <= n; i++) {
		for(int j = i + 1; j <= n; j++) {
			mid[tot++] = p[i] + p[j];
		}
	}

	LL ans = 0;
	sort(mid, mid + tot);
	for(int j, i = 0; i < tot; i = j) {
		j = i;
		while(j < tot && mid[j] == mid[i]) j++;
		ans += (LL)(j - i) * (j - i - 1) / 2;
	}

	printf("%lld\n", ans);

	return 0;
}
