#include <cstdio>
#include <cstring>
#include <algorithm>
#include <stack>
using namespace std;

const int maxn = 10000 + 10;
const int maxm = 50000 + 10;

struct Edge
{
	int v, nxt;
	Edge() {}
	Edge(int v, int nxt): v(v), nxt(nxt) {}
};

int ecnt, head[maxn];
Edge edges[maxm];

void AddEdge(int u, int v) {
	edges[ecnt] = Edge(v, head[u]);
	head[u] = ecnt++;
}

int n, m;

stack<int> S;
int dfs_clock, pre[maxn], low[maxn];
int scc_cnt, sccno[maxn], cnt[maxn];

void dfs(int u) {
	pre[u] = low[u] = ++dfs_clock;
	S.push(u);
	for(int i = head[u]; ~i; i = edges[i].nxt) {
		int v = edges[i].v;
		if(!pre[v]) {
			dfs(v);
			low[u] = min(low[u], low[v]);
		} else if(!sccno[v]) low[u] = min(low[u], pre[v]);
	}

	if(pre[u] == low[u]) {
		scc_cnt++;
		cnt[scc_cnt] = 0;
		for(;;) {
			int x = S.top(); S.pop();
			sccno[x] = scc_cnt;
			cnt[scc_cnt]++;
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

int out[maxn];

int main()
{
	scanf("%d%d", &n, &m);

	ecnt = 0;
	memset(head, -1, sizeof(head));
	while(m--) {
		int u, v; scanf("%d%d", &u, &v);
		AddEdge(u, v);
	}

	find_scc();
	
	memset(out, 0, sizeof(out));
	for(int u = 1; u <= n; u++) {
		for(int i = head[u]; ~i; i = edges[i].nxt) {
			int v = edges[i].v;
			if(sccno[u] == sccno[v]) continue;
			out[sccno[u]]++;
		}
	}

	int ans = 0;
	int num = 0, id;
	for(int i = 1; i <= scc_cnt; i++) if(!out[i]) { num++; id = i; }
	if(num == 1) ans = cnt[id];
	printf("%d\n", ans);

	return 0;
}
