#include <cstdio>
#include <cstring>
#include <algorithm>
#include <stack>
using namespace std;

const int maxn = 5000 + 10;
const int maxm = 20000 + 10;

struct Edge
{
    int v, nxt;
    Edge() {}
    Edge(int v, int nxt): v(v), nxt(nxt) {}
};

int n, m;

struct Graph
{
    int ecnt, head[maxn];
    Edge edges[maxm];

    void init() { ecnt = 0; memset(head, -1, sizeof(head)); }

    void AddEdge(int u, int v) {
		edges[ecnt] = Edge(v, head[u]);
		head[u] = ecnt++;
	}
};

Graph g, t;

stack<int> S;
int dfs_clock, pre[maxn], low[maxn];
int scc_cnt, sccno[maxn];

void dfs(int u, int p) {
    pre[u] = low[u] = ++dfs_clock;
    S.push(u);
    for(int i = g.head[u]; ~i; i = g.edges[i].nxt) {
        if(p != -1 && (p ^ i) == 1) continue;
        int v = g.edges[i].v;
        if(!pre[v]) {
            dfs(v, i);
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
        dfs(i, -1);
}

int deg[maxn];

int main()
{
    scanf("%d%d", &n, &m);

	g.init();
    while(m--) {
        int u, v; scanf("%d%d", &u, &v);
        g.AddEdge(u, v); g.AddEdge(v, u);
    }

    find_scc();

	t.init();
	for(int u = 1; u <= n; u++) {
		for(int i = g.head[u]; ~i; i = g.edges[i].nxt) {
			int v = g.edges[i].v;
			if(sccno[u] == sccno[v]) continue;
			deg[sccno[u]]++;
		}
	}

	int cnt = 0;
	for(int i = 1; i <= scc_cnt; i++) if(deg[i] == 1) cnt++;
	printf("%d\n", (cnt + 1) / 2);

    return 0;
}
