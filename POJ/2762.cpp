#include <cstdio>
#include <cstring>
#include <algorithm>
#include <stack>
using namespace std;

const int maxn = 1000 + 10;
const int maxm = 6000 + 10;

struct Edge
{
	int v, nxt;
	Edge() {}
	Edge(int v, int nxt): v(v), nxt(nxt) {}
};

struct Graph {
	int ecnt, head[maxn];
	Edge edges[maxm];

	void init() { ecnt = 0; memset(head, -1, sizeof(head)); }

	void AddEdge(int u, int v) {
		edges[ecnt] = Edge(v, head[u]);
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
	for(int i = 1; i <= n; i++) if(!pre[i]) dfs(i);
}

int in[maxn];
bool vis[maxn];

bool check() {
	int cnt = 0, id;
	for(int i = 1; i <= scc_cnt; i++)
		if(!in[i]) { cnt++; id = i; }
	if(cnt >= 2) return false;
	stack<int> s;
	s.push(id);
	memset(vis, false, sizeof(vis));
	vis[id] = true;
	while(!s.empty()) {
		int u = s.top(); s.pop();
		for(int i = t.head[u]; ~i; i = t.edges[i].nxt) {
			int v = t.edges[i].v;
			in[v]--;
			if(!in[v]) {
				if(!s.empty()) return false;
				else { s.push(v); vis[v] = true; }
			}
		}
	}
	for(int i = 1; i <= scc_cnt; i++) if(!vis[i]) return false;
	return true;
}

int main()
{
	int T; scanf("%d", &T);
	while(T--) {
		scanf("%d%d", &n, &m);
		g.init();
		while(m--) {
			int u, v; scanf("%d%d", &u, &v);
			g.AddEdge(u, v);
		}

		find_scc();

		t.init();
		memset(in, 0, sizeof(in));
		for(int u = 1; u <= n; u++) {
			for(int i = g.head[u]; ~i; i = g.edges[i].nxt) {
				int v = g.edges[i].v;
				if(sccno[u] == sccno[v]) continue;
				t.AddEdge(sccno[u], sccno[v]);
				in[sccno[v]]++;
			}
		}

		if(check()) printf("Yes\n");
		else printf("No\n");
	}

	return 0;
}
