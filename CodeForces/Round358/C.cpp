#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 100000 + 10;
typedef long long LL;

struct Edge
{
	int v, w, nxt;
	Edge() {}
	Edge(int v, int w, int nxt): v(v), w(w), nxt(nxt) {}
};

int ecnt, head[maxn];
Edge edges[maxn * 2];

void AddEdge(int u, int v, int w) {
	edges[ecnt] = Edge(v, w, head[u]);
	head[u] = ecnt++;
}

int a[maxn], sz[maxn], fa[maxn];
LL d[maxn];

void dfs(int u) {
	sz[u]++;
	for(int i = head[u]; ~i; i = edges[i].nxt) {
		int v = edges[i].v;
		if(v == fa[u]) continue;
		fa[v] = u;
		dfs(v);
		sz[u] += sz[v];
	}
}

int dfs2(int u, int p) {
	if(u != 1) d[u] = max(0LL, d[fa[u]] + edges[p].w);
	if(d[u] > a[u]) return sz[u];
	int ans = 0;
	for(int i = head[u]; ~i; i = edges[i].nxt) {
		int v = edges[i].v;
		if(v == fa[u]) continue;
		ans += dfs2(v, i);
	}
	return ans;
}

int main()
{
	int n; scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", a + i);
	ecnt = 0;
	memset(head, -1, sizeof(head));
	for(int u = 2; u <= n; u++) {
		int v, w; scanf("%d%d", &v, &w);
		AddEdge(u, v, w);
		AddEdge(v, u, w);
	}

	dfs(1);
	printf("%d\n", dfs2(1, -1));

	return 0;
}
