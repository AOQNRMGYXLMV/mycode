#include <cstdio>
#include <cstring>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

const int maxn = 500 + 10;
const int maxm = maxn * maxn;
const int INF = 0x3f3f3f3f;

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

void dfs(int u) {
	pre[u] = low[u] = ++dfs_clock;
	S.push(u);
	for(int i = g.head[u]; ~i; i = g.edges[i].nxt) {
		int v = g.edges[i].v;
		if(!pre[v]) {
			dfs(v);
			low[u] = min(low[u], low[v]);
		} else if(!sccno[v]) low[u] = min(low[u], pre[v]);
	}
	if(pre[u] == low[u]) {
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
		dfs(i);
}

int d[maxn];
bool inq[maxn];

int SPFA(int st, int ed) {
	memset(d, 0x3f, sizeof(d));
	d[st] = 0;
	queue<int> Q;
	Q.push(st);
	memset(inq, false, sizeof(inq));
	inq[st] = true;

	while(!Q.empty()) {
		int u = Q.front(); Q.pop(); inq[u] = false;
		for(int i = t.head[u]; ~i; i = t.edges[i].nxt) {
			int v = t.edges[i].v;
			int w = t.edges[i].w;
			if(d[u] + w < d[v]) {
				d[v] = d[u] + w;
				if(!inq[v]) { Q.push(v); inq[v] = true; }
			}
		}
	}

	return d[ed];
}

int main()
{
	while(scanf("%d%d", &n, &m) == 2 && n) {
		g.init();
		while(m--) {
			int u, v, w; scanf("%d%d%d", &u, &v, &w);
			g.AddEdge(u, v, w);
		}

		find_scc();

		t.init();
		for(int u = 1; u <= n; u++) {
			for(int i = g.head[u]; ~i; i = g.edges[i].nxt) {
				int v = g.edges[i].v;
				if(sccno[u] == sccno[v]) continue;
				int w = g.edges[i].w;
				t.AddEdge(sccno[u], sccno[v], w);
			}
		}

		int q; scanf("%d", &q);
		while(q--) {
			int u, v; scanf("%d%d", &u, &v);
			int ans = SPFA(sccno[u], sccno[v]);
			if(ans < INF) printf("%d\n", ans);
			else printf("Nao e possivel entregar a carta\n");
		}
		printf("\n");
	}

	return 0;
}
