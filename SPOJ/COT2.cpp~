#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

const int maxn = 40000 + 10;
const int maxq = 100000 + 10;

struct Edge
{
	int v, nxt;
	Edge() {}
	Edge(int v, int nxt): v(v), nxt(nxt) {}
};

int ecnt, head[maxn];
Edge edges[maxn * 2];

void AddEdge(int u, int v) {
	edges[ecnt] = Edge(v, head[u]);
	head[u] = ecnt++;
}

int n, m;

int a[maxn], b[maxn], tot;

int anc[maxn][20], dep[maxn];
int group[maxn], blocks, sz;

int S[maxn], top;

void dfs(int u) {
	int cur = top;
	for(int i = head[u]; ~i; i = edges[i].nxt) {
		int v = edges[i].v;
		if(v == anc[u][0]) continue;
		anc[v][0] = u;
		dep[v] = dep[u] + 1;
		dfs(v);
		if(top - cur >= sz) {
			blocks++;
			while(top != cur) group[S[top--]] = blocks;
		}
	}
	S[++top] = u;
}

struct Query
{
	int u, v, id;
	bool operator < (const Query& t) const {
		return group[u] < group[t.u] || (group[u] == group[t.u] && group[v] < group[t.v]);
	}
}q[maxq];

void preprocess() {
	for(int j = 1; (1 << j) < n; j++)
		for(int i = 1; i <= n; i++) if(anc[i][j-1])
			anc[i][j] = anc[anc[i][j-1]][j-1];
}

int LCA(int u, int v) {
	if(dep[u] < dep[v]) swap(u, v);
	int log;
	for(log = 0; (1 << log) < dep[u]; log++);
	for(int i = log; i >= 0; i--)
		if(dep[u] - (1<<i) >= dep[v]) u = anc[u][i];
	if(u == v) return u;
	for(int i = log; i >= 0; i--)
		if(anc[u][i] && anc[u][i] != anc[v][i])
			u = anc[u][i], v = anc[v][i];
	return anc[u][0];
}

int cnt[maxn], dif, in[maxn];

void xorvertex(int u) {
	if(in[u]) { cnt[a[u]]--; if(!cnt[a[u]]) dif--; }
	else { cnt[a[u]]++; if(cnt[a[u]] == 1) dif++; }
	in[u] ^= 1;
}

void xorpath(int u, int v) {
	if(dep[u] < dep[v]) swap(u, v);
	while(dep[u] > dep[v]) { xorvertex(u); u = anc[u][0]; }
	while(u != v) {
		xorvertex(u); xorvertex(v);
		u = anc[u][0]; v = anc[v][0];
	}
}

int ans[maxq];

int main()
{
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++) {
		scanf("%d", a + i);
		b[i] = a[i];
	}
	sort(b + 1, b + 1 + n);
	tot = unique(b + 1, b + 1 + n) - b - 1;
	for(int i = 1; i <= n; i++)
		a[i] = lower_bound(b + 1, b + 1 + tot, a[i]) - b;

	ecnt = 0;
	memset(head, -1, sizeof(head));
	for(int i = 1; i < n; i++) {
		int u, v; scanf("%d%d", &u, &v);
		AddEdge(u, v); AddEdge(v, u);
	}

	sz = (int)sqrt(n);
	dfs(1);
	while(top) group[S[top--]] = blocks;
        preprocess();

	for(int i = 1; i <= m; i++) {
		scanf("%d%d", &q[i].u, &q[i].v);
		q[i].id = i;
		if(q[i].u > q[i].v) swap(q[i].u, q[i].v);
	}

	sort(q + 1, q + 1 + m);

	int u = 1, v = 1;
	for(int i = 1; i <= m; i++) {
		xorpath(u, q[i].u);
		xorpath(v, q[i].v);
		u = q[i].u, v = q[i].v;
		int lca = LCA(u, v);
		ans[q[i].id] = dif;
		if(!cnt[a[lca]]) ans[q[i].id]++;
	}

	for(int i = 1; i <= m; i++) printf("%d\n", ans[i]);

	return 0;
}
