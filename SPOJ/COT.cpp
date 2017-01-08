#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 100000 + 10;

struct Edge
{
	int v, nxt;
	Edge() {}
	Edge(int v, int nxt): v(v), nxt(nxt) {}
};

int head[maxn], ecnt;
Edge edges[maxn * 2];

void AddEdge(int u, int v) {
	edges[ecnt] = Edge(v, head[u]);
	head[u] = ecnt++;
}

int fa[maxn], L[maxn];

void dfs(int u) {
	for(int i = head[u]; ~i; i = edges[i].nxt) {
		int v = edges[i].v;
		if(v == fa[u]) continue;
		fa[v] = u;
		L[v] = L[u] + 1;
		dfs(v);
	}
}

int n, m;

int anc[maxn][20];

void preprocess() {
	memset(anc, 0, sizeof(anc));
	for(int i = 1; i <= n; i++) anc[i][0] = fa[i];
	for(int j = 1; (1 << j) < n; j++)
		for(int i = 1; i <= n; i++) if(anc[i][j-1])
			anc[i][j] = anc[anc[i][j-1]][j-1];
}

int LCA(int u, int v) {
	if(L[u] < L[v]) swap(u, v);
	int log;
	for(log = 0; (1 << log) < L[u]; log++);
	for(int i = log; i >= 0; i--)
		if(L[u] - (1<<i) >= L[v]) u = anc[u][i];
	if(u == v) return u;
	for(int i = log; i >= 0; i--)
		if(anc[u][i] && anc[u][i] != anc[v][i])
			u = anc[u][i], v = anc[v][i];
	return fa[u];
}

int a[maxn], b[maxn], tot;

struct Node
{
	int lch, rch, sum;
};

int sz;
Node T[maxn << 5];
int root[maxn];

int newnode() {
	sz++;
	T[sz].lch = T[sz].rch = T[sz].sum = 0;
	return sz;
}

int update(int pre, int L, int R, int p) {
	int rt = newnode();
	T[rt].lch = T[pre].lch;
	T[rt].rch = T[pre].rch;
	T[rt].sum = T[pre].sum + 1;
	if(L == R) return rt;
	int M = (L + R) / 2;
	if(p <= M) T[rt].lch = update(T[pre].lch, L, M, p);
	else T[rt].rch = update(T[pre].rch, M+1, R, p);
	return rt;
}

void dfs2(int u) {
	root[u] = update(root[fa[u]], 1, tot, a[u]);
	for(int i = head[u]; ~i; i = edges[i].nxt) {
		int v = edges[i].v;
		if(v == fa[u]) continue;
		dfs2(v);
	}
}

int tmp;

int query(int u, int v, int l, int L, int R, int k) {
	if(L == R) return L;
	int M = (L + R) / 2;
	int sum = T[T[u].lch].sum + T[T[v].lch].sum - T[T[l].lch].sum * 2;
	if(L <= tmp && tmp <= M) sum++;
	if(sum >= k) return query(T[u].lch, T[v].lch, T[l].lch, L, M, k);
	else return query(T[u].rch, T[v].rch, T[l].rch, M+1, R, k - sum);
}

int main()
{
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++) {
		scanf("%d", a + i);
		b[i] = a[i];
	}
	ecnt = 0;
	memset(head, -1, sizeof(head));
	for(int i = 1; i < n; i++) {
		int u, v; scanf("%d%d", &u, &v);
		AddEdge(u, v); AddEdge(v, u);
	}

	dfs(1);
	preprocess();

	sort(b + 1, b + 1 + n);
	tot = unique(b + 1, b + 1 + n) - b - 1;
	for(int i = 1; i <= n; i++)
		a[i] = lower_bound(b + 1, b + 1 + tot, a[i]) - b;
	dfs2(1);
	
	while(m--) {
		int u, v, k; scanf("%d%d%d", &u, &v, &k);
		int lca = LCA(u, v);
		tmp = a[lca];
		int ans = query(root[u], root[v], root[lca], 1, tot, k);
		printf("%d\n", b[ans]);
	}

	return 0;
}
