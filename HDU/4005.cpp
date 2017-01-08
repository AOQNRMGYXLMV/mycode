#include <cstdio>
#include <cstring>
#include <algorithm>
#include <stack>
using namespace std;

const int INF = 0x3f3f3f3f;
const int maxn = 10000 + 10;
const int maxm = 200000 + 10;

struct Edge
{
	int v, w, nxt;
	Edge() {}
	Edge(int v, int w, int nxt): v(v), w(w), nxt(nxt) {}
};

struct Graph
{
	int ecnt, head[maxn];
	Edge edges[maxm];

	void init() { ecnt = 0; memset(head, -1, sizeof(head)); }

	void AddEdge(int u, int v, int w) {
		edges[ecnt] = Edge(v, w, head[u]);
		head[u] = ecnt++;
	}
};

Graph g, t;

int n, m;

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
	memset(pre, 0, sizeof(pre));
	memset(sccno, 0, sizeof(sccno));
	dfs_clock = scc_cnt = 0;
	dfs(1, 0);
}

int ans;

int dfs2(int u, int fa) {
	int min1 = INF, min2 = INF;
	for(int i = t.head[u]; ~i; i = t.edges[i].nxt) {
		int v = t.edges[i].v;
		if(v == fa) continue;
		int tmp = t.edges[i].w;
		tmp = min(tmp, dfs2(v, u));
		if(tmp < min2) min2 = tmp;
		if(min2 < min1) swap(min1, min2);
	}
	ans = min(ans, min2);
	return min1;
}

int main()
{
	while(scanf("%d%d", &n, &m) == 2) {
		g.init();
		while(m--) {
			int u, v, w; scanf("%d%d%d", &u, &v, &w);
			g.AddEdge(u, v, w);
			g.AddEdge(v, u, w);
		}

		find_scc();

		t.init();
		int a, b, minEdge = INF;
		for(int u = 1; u <= n; u++) {
			for(int i = g.head[u]; ~i; i = g.edges[i].nxt) {
				int v = g.edges[i].v;
				if(sccno[u] == sccno[v]) continue;
				int w = g.edges[i].w;
				t.AddEdge(sccno[u], sccno[v], w);
				if(w < minEdge) { minEdge = w; a = sccno[u]; b = sccno[v]; }
			}
		}

		ans = INF;
		dfs2(a, b);
		dfs2(b, a);
		if(ans == INF) ans = -1;
		printf("%d\n", ans);
	}

	return 0;
}
