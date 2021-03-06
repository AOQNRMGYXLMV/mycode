#include <cstdio>
#include <cstring>
#include <algorithm>
#include <stack>
using namespace std;

const int maxn = 300000 + 10;

struct Edge
{
	int v, color, nxt;
	Edge() {}
	Edge(int v, int c, int n): v(v), color(c), nxt(n) {}
};

int n, m;

struct Graph
{
	int ecnt, head[maxn];
	Edge edges[maxn * 2];

	void init() { ecnt = 0; memset(head, -1, sizeof(head)); }

	void AddEdge(int u, int v, int color) {
		edges[ecnt] = Edge(v, color, head[u]);
		head[u] = ecnt++;
	}
};

Graph g, t;

stack<int> S;
int dfs_clock, pre[maxn], low[maxn];
int scc_cnt, sccno[maxn];

void dfs(int u, int fa) {
	pre[u] = low[u] = ++dfs_clock;
	S.push(u);
	bool flag = false;
	for(int i = g.head[u]; ~i; i = g.edges[i].nxt) {
		int v = g.edges[i].v;
		if(v == fa && !flag) { flag = true; continue; }
		if(!pre[v]) {
			dfs(v, u);
			low[u] = min(low[u], low[v]);
		} else if(!sccno[v]) low[u] = min(low[u], pre[v]);
	}

	if(low[u] == pre[u]) {
		scc_cnt++;
		for(;;) {
			int x = S.top(); S.pop();
			sccno[x] = scc_cnt;
			if(x == u) break;
		}
	}
}

void find_scc() {
	dfs_clock = scc_cnt = 0;
	memset(pre, 0, sizeof(pre));
	memset(sccno, 0, sizeof(sccno));
	for(int i = 1; i <= n; i++) if(!pre[i])
		dfs(i, 0);
}

int a, b;

int colv[maxn];

int fa[maxn], dep[maxn], cole[maxn];

void dfs2(int u) {
	for(int i = t.head[u]; ~i; i = t.edges[i].nxt) {
		int v = t.edges[i].v;
		if(v == fa[u]) continue;
		fa[v] = u;
		dep[v] = dep[u] + 1;
		if(t.edges[i].color) cole[v] = 1;
		dfs2(v);
	}
}

bool query(int u, int v) {
	if(colv[u] || colv[v]) return true;
	if(dep[u] < dep[v]) swap(u, v);
	while(dep[u] > dep[v]) {
		if(cole[u]) return true;
		u = fa[u];
		if(colv[u]) return true;
	}
	while(u != v) {
		if(cole[u] || cole[v]) return true;
		u = fa[u]; v = fa[v];
		if(colv[u] || colv[v]) return true;
	}
	return false;
}

int main()
{
	scanf("%d%d", &n, &m);
	g.init();
	while(m--) {
		int u, v, c; scanf("%d%d%d", &u, &v, &c);
		g.AddEdge(u, v, c); g.AddEdge(v, u, c);
	}
	scanf("%d%d", &a, &b);

	find_scc();

	t.init();
	for(int u = 1; u <= n; u++) {
		for(int i = g.head[u]; ~i; i = g.edges[i].nxt) {
			int v = g.edges[i].v;
			int c = g.edges[i].color;
			if(sccno[u] == sccno[v]) {
				if(c == 1) colv[sccno[u]] = 1;
			} else {
				t.AddEdge(sccno[u], sccno[v], c);
			}
		}
	}

	dfs2(1);
	if(query(sccno[a], sccno[b])) puts("YES");
	else puts("NO");

	return 0;
}
