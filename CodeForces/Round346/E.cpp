#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 100000 + 10;

struct Edge
{
	int v, nxt;
	Edge() {}
	Edge(int v, int nxt): v(v), nxt(nxt) {}
};

int n, m;

int ecnt, head[maxn];
Edge edges[maxn * 2];

void AddEdge(int u, int v) {
	edges[ecnt] = Edge(v, head[u]);
	head[u] = ecnt++;
}

int dfs_clock;
int pre[maxn], low[maxn];

int bridges, sz;

void dfs(int u, int p) {
	sz++;
	pre[u] = low[u] = ++dfs_clock;
	for(int i = head[u]; ~i; i = edges[i].nxt) {
		int v = edges[i].v;
		if(!pre[v]) {
			dfs(v, u);
			low[u] = min(low[u], low[v]);
			if(low[v] > low[u]) bridges++;
		} else if(v != p) low[u] = min(low[u], pre[v]);
	}
}

int main()
{
	scanf("%d%d", &n, &m);

	ecnt = 0;
	memset(head, -1, sizeof(head));
	while(m--) {
		int u, v; scanf("%d%d", &u, &v);
		AddEdge(u, v); AddEdge(v, u);
	}

	int ans = 0;
	for(int i = 1; i <= n; i++) if(!pre[i]) {
		sz = 0;
		bridges = 0;
		dfs(i, 0);
		if(bridges == sz - 1) ans++;
	}

	printf("%d\n", ans);

	return 0;
}
