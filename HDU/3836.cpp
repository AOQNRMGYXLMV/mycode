#include <cstdio>
#include <cstring>
#include <algorithm>
#include <stack>
using namespace std;

const int maxn = 20000 + 10;
const int maxm = 50000 + 10;

struct Edge
{
	int v, nxt;
	Edge() {}
	Edge(int v, int nxt): v(v), nxt(nxt) {}
};

int n, m;

int ecnt, head[maxn];
Edge edges[maxm];

void AddEdge(int u, int v) {
	edges[ecnt] = Edge(v, head[u]);
	head[u] = ecnt++;
}

stack<int> S;
int dfs_clock, pre[maxn], low[maxn];
int scc_cnt, sccno[maxn];

void dfs(int u) {
	pre[u] = low[u] = ++dfs_clock;
	S.push(u);
	for(int i = head[u]; ~i; i = edges[i].nxt) {
		int v = edges[i].v;
		if(!pre[v]) {
			dfs(v);
			low[u] = min(low[u], low[v]);
		}
		else if(!sccno[v]) low[u] = min(low[u], pre[v]);
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
	for(int i = 1; i <= n; i++) if(!pre[i])
		dfs(i);
}

int in[maxn], out[maxn];

int main()
{
	while(scanf("%d%d", &n, &m) == 2) {
		ecnt = 0;
		memset(head, -1, sizeof(head));
		while(m--) {
			int u, v; scanf("%d%d", &u, &v);
			AddEdge(u, v);
		}

		find_scc();
		if(scc_cnt == 1) { puts("0"); continue; }

		memset(in, 0, sizeof(in));
		memset(out, 0, sizeof(out));
		for(int u = 1; u <= n; u++) {
			for(int i = head[u]; ~i; i = edges[i].nxt) {
				int v = edges[i].v;
				if(sccno[u] == sccno[v]) continue;
				out[sccno[u]]++;
				in[sccno[v]]++;
			}
		}

		int in_cnt = 0, out_cnt = 0;
		for(int i = 1; i <= scc_cnt; i++) {
			if(!in[i]) in_cnt++;
			if(!out[i]) out_cnt++;
		}

		printf("%d\n", max(in_cnt, out_cnt));
	}

	return 0;
}
