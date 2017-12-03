#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
#define PB push_back
#define PII pair<int, int>
#define REP(i, a, b) for(int i = a; i < b; i++)
#define PER(i, a, b) for(int i = b - 1; i >= a; i--)
#define ALL(x) x.begin(), x.end()

const int maxn = 500 + 10;
const int off = 200;
bool vis[maxn][maxn];
struct Point {
	int x, y;
	Point(int x = 0, int y = 0):x(x), y(y) {}
	void read() { scanf("%d%d", &x, &y); }
	Point operator - (const Point& t) const {
		return Point(x - t.x, y - t.y);
	}
	Point operator + (const Point& t) const {
		return Point(x + t.x, y + t.y);
	}
	Point rotate() {
		return Point(-y, x);
	}
	bool check() {
		if(x<0||x>=maxn||y<0||y>=maxn) return false;
		return vis[x][y];
	}
};

int n;
Point p[maxn];

int main() {
	while(scanf("%d", &n) == 1) {
		memset(vis, false, sizeof(vis));
		REP(i, 0, n) {
			p[i].read();
			p[i].x += off;
			p[i].y += off;
			vis[p[i].x][p[i].y] = true;
		}
		int ans = 0;
		REP(i, 0, n) REP(j, 0, n) if(i != j) {
			Point V = (p[j]-p[i]).rotate();
			if((p[i]+V).check() && (p[j]+V).check())
				ans++;
		}
		ans >>= 2;
		printf("%d\n", ans);
	}

	return 0;
}

