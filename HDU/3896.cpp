#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 100000 + 10;
const int maxm = 1000000 + 10;

struct Edge
{
	int v, nxt;
	Edge() {}
	Edge(int v, int nxt): v(v), nxt(nxt) {}
};

int ecnt, head[maxn];
Edge edges[maxm];

void AddEdge(int u, int v) {
	edges[ecnt] = Edge(v, head[u]); head[u] = ecnt++;
	edges[ecnt] = Edge(u, head[v]); head[v] = ecnt++;
}

int n, m;

int fa[maxn], dep[maxn];
int dfs_clock, pre[maxn], post[maxn], low[maxn];
bool isbridge[maxn], iscut[maxn];

void dfs(int u) {
	bool flag = false;
	int child = 0;
	pre[u] = low[u] = ++dfs_clock;
	for(int i = head[u]; ~i; i = edges[i].nxt) {
		int v = edges[i].v;
		if(v == fa[u] && !flag) { flag = true; continue; }
		child++;
		if(!pre[v]) {
			fa[v] = u;
			dep[v] = dep[u] + 1;
			dfs(v);
			low[u] = min(low[u], low[v]);
			if(low[v] >= pre[u]) {
				iscut[u] = true;
				if(low[v] > pre[u]) isbridge[v] = true;
			}
		} else low[u] = min(low[u], pre[v]);
	}
	if(u == 1 && child == 1) iscut[u] = false;
	post[u] = dfs_clock;
}

int anc[maxn][20];

void preprocess() {
	memset(anc, 0, sizeof(anc));
	for(int i = 1; i <= n; i++) anc[i][0] = fa[i];
	for(int j = 1; (1 << j) < n; j++)
		for(int i = 1; i <= n; i++) if(anc[i][j-1])
			anc[i][j] = anc[anc[i][j-1]][j-1];
}

int upward(int u, int x) {
	for(int i = 0; i < 20; i++)
		if((x >> i) & 1) u = anc[u][i];
	return u;
}

int insubtree(int u, int v) {
	if(pre[v] <= pre[u] && pre[u] <= post[v]) return 1;
	return 0;
}

bool juedgeVertex(int a, int b, int c) {
	int in1 = insubtree(a, c);
	int in2 = insubtree(b, c);
	if(in1 & in2) {
		a = upward(a, dep[a] - dep[c] - 1);
		b = upward(b, dep[b] - dep[c] - 1);
		if(a == b) return true;
		if(low[a] >= pre[c]) return false;
		if(low[b] >= pre[c]) return false;
	}
	if(in1 ^ in2) {
		if(!in1) swap(a, b);
		a = upward(a, dep[a] - dep[c] - 1);
		if(low[a] >= pre[c]) return false;
	}
	return true;
}

int main()
{
	while(scanf("%d%d", &n, &m) == 2) {
		ecnt = 0;
		memset(head, -1, sizeof(head));
		while(m--) {
			int u, v;
			scanf("%d%d", &u, &v);
			AddEdge(u, v);
		}

		dfs_clock = 0;
		memset(pre, 0, sizeof(pre));
		memset(isbridge, false, sizeof(isbridge));
		memset(iscut, false, sizeof(iscut));
		dfs(1);
		preprocess();

		int q;
		scanf("%d", &q);
		while(q--) {
			int op, a, b, c, d;
			scanf("%d%d%d%d", &op, &a, &b, &c);
			bool ok = true;
			if(op == 1) {
				scanf("%d", &d);
				if(dep[c] < dep[d]) swap(c, d);
				int in1 = insubtree(a, c);
				int in2 = insubtree(b, c);
				if(isbridge[c] && (in1 ^ in2) == 1) ok = false;
			} else {
				ok = juedgeVertex(a, b, c);
			}
			printf("%s\n", ok ? "yes" : "no");
		}
	}

	return 0;
}
