#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 1000 + 10;

int w, h, n;

struct Rect
{
	int x1, y1, x2, y2;

	void read() { scanf("%d%d%d%d", &x1, &y1, &x2, &y2); }
}a[maxn];

bool covered[maxn];

bool in(int x, int y, const Rect& r) {
	if(x <= r.x1 || x >= r.x2) return false;
	if(y <= r.y1 || y >= r.y2) return false;
	return true;
}

bool intersect(const Rect& A, const Rect& B) {
	int x1 = max(A.x1, B.x1), x2 = min(A.x2, B.x2);
	if(x1 >= x2) return false;
	int y1 = max(A.y1, B.y1), y2 = min(A.y2, B.y2);
	if(y1 >= y2) return false;
	return true;
}

struct Edge
{
	int v, nxt;
	Edge() {}
	Edge(int v, int nxt): v(v), nxt(nxt) {}
};

int ecnt, head[maxn];
Edge edges[maxn * maxn];

void AddEdge(int u, int v) {
	edges[ecnt] = Edge(v, head[u]);
	head[u] = ecnt++;
}

int tot;
bool vis[maxn];

void dfs(int u) {
	vis[u] = true; tot++;
	for(int i = head[u]; ~i; i = edges[i].nxt) {
		int v = edges[i].v;
		if(vis[v]) continue;
		dfs(v);
	}
}

int main()
{
	scanf("%d%d%d", &w, &h, &n);
	for(int i = 1; i <= n; i++) a[i].read();
	for(int i = 1; i <= n; i++) {
		bool flag[4];
		memset(flag, false, sizeof(flag));
		int cnt = 0;
		covered[i] = false;
		for(int j = i + 1; j <= n; j++) {
			if(!flag[0] && in(a[i].x1, a[i].y1, a[j])) { flag[0] = true; cnt++; }
			if(!flag[1] && in(a[i].x2, a[i].y1, a[j])) { flag[1] = true; cnt++; }
			if(!flag[2] && in(a[i].x1, a[i].y2, a[j])) { flag[2] = true; cnt++; }
			if(!flag[3] && in(a[i].x2, a[i].y2, a[j])) { flag[3] = true; cnt++; }
			if(cnt == 4) { covered[i] = true; break; }
		}
	}
	
	memset(head, -1, sizeof(head));
	for(int i = 1; i <= n; i++)
		for(int j = i + 1; j <= n; j++)
			if(intersect(a[i], a[j])) AddEdge(i, j);

	int ans = 0, id;
	for(int i = 1; i <= n; i++) if(!covered[i]) {
		tot = 0; memset(vis, false, sizeof(vis));
		dfs(i);
		if(tot > ans) { ans = tot; id = i; }
	}

	printf("%d %d\n", ans, id);

	return 0;
}
