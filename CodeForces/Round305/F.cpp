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

const int maxn = 200000 + 10;

vector<int> row[maxn], col[maxn], G[maxn];

char ans[maxn];

struct Point {
	int x, y, id;
	void read() { scanf("%d%d", &x, &y); }
	bool operator < (const Point& t) const {
		return x < t.x || (x == t.x && y < t.y);
	}
};

bool cmp(const Point& A, const Point& B) {
	return A.y < B.y || (A.y == B.y && A.x < B.x);
}

Point p[maxn];

void dfs(int u, int p = -1, int c = 0) {
	ans[u] = c ? 'r' : 'b';
	for(int v : G[u]) if(v != p && !ans[v])
		dfs(v, u, c ^ 1);
}

int main() {
	int n; scanf("%d", &n);
	REP(i, 0, n) {
		p[i].read();
		p[i].id = i;
	}
	sort(p, p + n);
	for(int i = 0, j; i < n; i = j) {
		for(j = i; j < n && p[j].x == p[i].x; j++);
		for(int k = i + 1; k < j; k += 2) {
			G[p[k].id].PB(p[k-1].id);
			G[p[k-1].id].PB(p[k].id);
		}
	}
	sort(p, p + n, cmp);
	for(int i = 0, j; i < n; i = j) {
		for(j = i; j < n && p[j].y == p[i].y; j++);
		for(int k = i + 1; k < j; k += 2) {
			G[p[k].id].PB(p[k-1].id);
			G[p[k-1].id].PB(p[k].id);
		}
	}

	REP(i, 0, n) if(!ans[i]) dfs(i);
	ans[n] = 0;
	printf("%s\n", ans);

	return 0;
}

