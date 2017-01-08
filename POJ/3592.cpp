#include <cstdio>
#include <cstring>
#include <algorithm>
#include <stack>
using namespace std;

const int maxn = 40 + 5;

int n, m;
char s[maxn][maxn];

const int maxv = maxn * maxn;
const int maxe = maxv << 2;

struct Edge
{
	int v, nxt;
	Edge() {}
	Edge(int v, int nxt): v(v), nxt(nxt) {}
};

struct Graph
{
	int ecnt, head[maxv];
	Edge edges[maxe];

	void init() { ecnt = 0; memset(head, -1, sizeof(head)); }

	void AddEdge(int u, int v) {
		edges[ecnt] = Edge(v, head[u]);
		head[u] = ecnt++;
	}
};

Graph g, t;

int id(int i, int j) { return i * m + j; }

stack<int> S;
int dfs_clock, pre[maxv], low[maxv];
int scc_cnt, sccno[maxv];

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
	for(int i = 0; i < n * m; i++) if(!pre[i])
		dfs(i);
}

int w[maxv], d[maxv];

void dfs2(int u) {
	d[u] = 0;
	int Max = 0;
	for(int i = t.head[u]; ~i; i = t.edges[i].nxt) {
		int v = t.edges[i].v;
		dfs2(v);
		Max = max(Max, d[v]);
	}
	d[u] = Max + w[u];
}

int main()
{
	int T; scanf("%d", &T);
	while(T--) {
		scanf("%d%d", &n, &m);

		for(int i = 0; i < n; i++) scanf("%s", s[i]);

		g.init();
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				if(s[i][j] == '#') continue;
				int u = id(i, j);
				if(i < n - 1 && s[i + 1][j] != '#')
					g.AddEdge(u, id(i + 1, j));
				if(j < m - 1 && s[i][j + 1] != '#')
					g.AddEdge(u, id(i, j + 1));
				if(s[i][j] == '*') {
					int x, y; scanf("%d%d", &x, &y);
					g.AddEdge(u, id(x, y));
				}
			}
		}

		find_scc();
		for(int i = 1; i <= scc_cnt; i++) w[i] = 0;
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				if('0' <= s[i][j] && s[i][j] <= '9')
					w[sccno[id(i, j)]] += s[i][j] - '0';

		t.init();
		for(int u = 0; u < n * m; u++) {
			for(int i = g.head[u]; ~i; i = g.edges[i].nxt) {
				int v = g.edges[i].v;
				if(sccno[u] == sccno[v]) continue;
				t.AddEdge(sccno[u], sccno[v]);
			}
		}

		dfs2(sccno[0]);
		printf("%d\n", d[sccno[0]]);
	}

	return 0;
}
