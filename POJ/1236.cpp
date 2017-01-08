#include <cstdio>
#include <cstring>
#include <algorithm>
#include <stack>
using namespace std;

const int maxn = 100 + 10;

struct Edge
{
	int v, nxt;
	Edge() {}
	Edge(int v, int nxt): v(v), nxt(nxt) {}
};

int n;

int ecnt, head[maxn];
Edge edges[maxn * maxn];

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

int out[maxn], in[maxn];

int main()
{
	ecnt = 0;
	memset(head, -1, sizeof(head));
	scanf("%d", &n);
	for(int u = 1; u <= n; u++) {
		int v; scanf("%d", &v);
		while(v) {
			AddEdge(u, v);
			scanf("%d", &v);
		}
	}
	
	find_scc();
	for(int u = 1; u <= n; u++) {
		for(int i = head[u]; ~i; i = edges[i].nxt) {
			int v = edges[i].v;
			if(sccno[u] == sccno[v]) continue;
			out[sccno[u]]++;
			in[sccno[v]]++;
		}
	}

	int ans1 = 0, ans2 = 0;
	for(int i = 1; i <= scc_cnt; i++) {
		if(!in[i]) ans1++;
		if(!out[i]) ans2++;
	}

	printf("%d\n", ans1);
	if(scc_cnt == 1) printf("0\n");
	else printf("%d\n", max(ans1, ans2));
	
	return 0;
}
