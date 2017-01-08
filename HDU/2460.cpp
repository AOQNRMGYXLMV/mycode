#include <cstdio>
#include <cstring>
#include <algorithm>
#include <stack>
#include <vector>
using namespace std;

const int maxn = 100000 + 10;
const int maxm = 200000 + 10;

struct Graph
{
	vector<int> G[maxn];

	void init(int n) { for(int i = 1; i <= n; i++) G[i].clear(); }

	void AddEdge(int u, int v) { G[u].push_back(v); }
};

int n, m;
Graph g, t;

stack<int> S;
int dfs_clock, pre[maxn], low[maxn];
int scc_cnt, sccno[maxn];

void dfs(int u, int fa) {
	pre[u] = low[u] = ++dfs_clock;
	S.push(u);
	bool flag = false;
	for(int v : g.G[u]) {
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
		dfs(i, -1);
}

int bridges;
int fa[maxn], dep[maxn];
bool covered[maxn];

void dfs2(int u) {
	for(int v : t.G[u]) {
		if(v == fa[u]) continue;
		dep[v] = dep[u] + 1;
		fa[v] = u;
		dfs2(v);
	}
}

void update(int u, int v) {
	if(dep[u] < dep[v]) swap(u, v);
	while(dep[u] > dep[v]) {
		if(!covered[u]) { covered[u] = true; bridges--; }
		u = fa[u];
	}
	while(u != v) {
		if(!covered[u]) { covered[u] = true; bridges--; }
		if(!covered[v]) { covered[v] = true; bridges--; }
		u = fa[u]; v = fa[v];
	}
}

int main()
{
	int kase = 1;
	while(scanf("%d%d", &n, &m) == 2) {
		if(!n && !m) break;
		g.init(n);
		while(m--) {
			int u, v; scanf("%d%d", &u, &v);
			g.AddEdge(u, v);
			g.AddEdge(v, u);
		}
		find_scc();

		t.init(scc_cnt);
		for(int u = 1; u <= n; u++) {
			for(int v : g.G[u]) {
				if(sccno[u] == sccno[v]) continue;
				t.AddEdge(sccno[u], sccno[v]);
			}
		}
		dfs2(1);

		printf("Case %d:\n", kase++);

		bridges = scc_cnt - 1;
		memset(covered, false, sizeof(covered));
		int q; scanf("%d", &q);
		while(q--) {
			int u, v; scanf("%d%d", &u, &v);
			update(sccno[u], sccno[v]);
			printf("%d\n", bridges);
		}
		printf("\n");
	}

	return 0;
}
