#include <cstdio>
#include <cstring>
#include <algorithm>
#include <stack>
using namespace std;

const int maxn = 5000 + 10;
const int maxm = 100000 + 10;

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
		dfs(i);
}

int ecnt2, head2[maxn];
Edge edges2[maxm];
int left[maxn];
bool vis[maxn];

void AddEdge2(int u, int v) {
	edges2[ecnt2] = Edge(v, head2[u]);
	head2[u] = ecnt2++;
}

bool find(int u) {
	for(int i = head2[u]; ~i; i = edges2[i].nxt) {
		int v = edges2[i].v;
		if(vis[v]) continue;
		vis[v] = true;
		if(!left[v] || find(left[v])) {
			left[v] = u;
			return true;
		}
	}
	return false;
}

int main()
{
	int T; scanf("%d", &T);
	while(T--) {
		scanf("%d%d", &n, &m);

		ecnt = 0;
		memset(head, -1, sizeof(head));
		while(m--) {
			int u, v; scanf("%d%d", &u, &v);
			AddEdge(u, v);
		}
		find_scc();

		ecnt2 = 0;
		memset(head2, -1, sizeof(head2));
		for(int u = 1; u <= n; u++) {
			for(int i = head[u]; ~i; i = edges[i].nxt) {
				int v = edges[i].v;
				if(sccno[u] == sccno[v]) continue;
				AddEdge2(sccno[u], sccno[v]);
			}
		}

		int match = 0;
		memset(left, 0, sizeof(left));
		for(int i = 1; i <= scc_cnt; i++) {
			memset(vis, 0, sizeof(vis));
			if(find(i)) match++;
		}

		printf("%d\n", scc_cnt - match);
	}

	return 0;
}
