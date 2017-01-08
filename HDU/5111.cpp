#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#define MP make_pair
#define F first
#define S second
using namespace std;

typedef pair<int, int> PII;
const int maxn = 100000 + 10;

struct Edge
{
	int v, nxt;
	Edge() {}
	Edge(int v, int nxt): v(v), nxt(nxt) {}
};

struct Tree
{
	int n, w[maxn];
	int ecnt, head[maxn];
	Edge edges[maxn];
	int fa[maxn], dep[maxn], sz[maxn], son[maxn];

	void init() { ecnt = 0; memset(head, -1, sizeof(head)); }

	void AddEdge(int u, int v) {
		edges[ecnt] = Edge(v, head[u]);
		head[u] = ecnt++;
	}

	bool read() {
		if(scanf("%d", &n) != 1) return false;
		init();
		for(int u = 2; u <= n; u++) {
			scanf("%d", fa + u);
			AddEdge(fa[u], u);
		}
		for(int i = 1; i <= n; i++) scanf("%d", w + i);
		return true;
	}

	void dfs(int u) {
		sz[u] = 1; son[u] = 0;
		for(int i = head[u]; ~i; i = edges[i].nxt) {
			int v = edges[i].v;
			dep[v] = dep[u] + 1;
			dfs(v);
			sz[u] += sz[v];
			if(sz[v] > sz[son[u]]) son[u] = v;
		}
	}
};

Tree t1, t2;

int n1, n2;
int x[maxn];

int tot;
int id[maxn], pos[maxn], top[maxn];

void dfs2(int u, int tp) {
	id[u] = ++tot;
	int p = lower_bound(x + 1, x + 1 + n1, t1.w[u]) - x;
	pos[p] = tot;
	top[u] = tp;
	if(!t1.son[u]) return;
	dfs2(t1.son[u], tp);
	for(int i = t1.head[u]; ~i; i = t1.edges[i].nxt) {
		int v = t1.edges[i].v;
		if(v == t1.son[u]) continue;
		dfs2(v, v);
	}
}

vector<PII> inter;

void getIntervals(int u, int v) {
	inter.clear();
	while(top[u] != top[v]) {
		if(t1.dep[top[u]] < t1.dep[top[v]]) swap(u, v);
		inter.push_back(MP(id[top[u]], id[u]));
		u = t1.fa[top[u]];
	}
	if(t1.dep[u] > t1.dep[v]) swap(u, v);
	inter.push_back(MP(id[u], id[v]));
}

int anc[maxn][20];

void preprocess() {
	memset(anc, 0, sizeof(anc));
	for(int i = 1; i <= n2; i++) anc[i][0] = t2.fa[i];
	for(int j = 1; (1 << j) < n2; j++)
		for(int i = 1; i <= n2; i++) if(anc[i][j-1])
			anc[i][j] = anc[anc[i][j-1]][j-1];
}

int LCA(int u, int v) {
	int log;
	if(t2.dep[u] < t2.dep[v]) swap(u, v);
	for(log = 0; (1 << log) < t2.dep[u]; log++);
	for(int i = log; i >= 0; i--)
		if(t2.dep[u] - (1<<i) >= t2.dep[v]) u = anc[u][i];
	if(u == v) return u;
	for(int i = log; i >= 0; i--)
		if(anc[u][i] && anc[u][i] != anc[v][i])
			u = anc[u][i], v = anc[v][i];
	return t2.fa[u];
}

const int maxnode = maxn << 5;

int sz, root[maxn];
int lch[maxnode], rch[maxnode], sum[maxnode];

int update(int pre, int L, int R, int p) {
	int rt = ++sz;
	sum[rt] = sum[pre] + 1;
	if(L < R) {
		int M = (L + R) / 2;
		if(p <= M) { rch[rt] = rch[pre]; lch[rt] = update(lch[pre], L, M, p); }
		else { lch[rt] = lch[pre]; rch[rt] = update(rch[pre], M+1, R, p); }
	}
	return rt;
}

void build(int u, int p) {
	if(!t2.w[u]) root[u] = root[p];
	else root[u] = update(root[p], 1, n1, t2.w[u]);
	for(int i = t2.head[u]; ~i; i = t2.edges[i].nxt) {
		int v = t2.edges[i].v;
		build(v, u);
	}
}

int query(int u, int v, int lca, int L, int R, int qL, int qR) {
	if(qL <= L && R <= qR) { return sum[u] + sum[v] - sum[lca] * 2; }
	int ans = 0;
	int M = (L + R) / 2;
	if(qL <= M) ans += query(lch[u], lch[v], lch[lca], L, M, qL, qR);
	if(qR > M) ans += query(rch[u], rch[v], rch[lca], M+1, R, qL, qR);
	return ans;
}

int main()
{
	while(t1.read()) {
		t2.read();
		n1 = t1.n; n2 = t2.n;
		for(int i = 1; i <= n1; i++) x[i] = t1.w[i];
		sort(x + 1, x + 1 + n1);

		t1.dfs(1); t2.dfs(1);
		preprocess();
		tot = 0; dfs2(1, 1);

		for(int i = 1; i <= n2; i++) {
			int p = lower_bound(x + 1, x + 1 + n1, t2.w[i]) - x;
			if(p < 1 || p > n2 || x[p] != t2.w[i]) t2.w[i] = 0;
			else t2.w[i] = pos[p];
		}

		sz = 1;
		build(1, 0);

		int q; scanf("%d", &q);
		while(q--) {
			int u1, v1, u2, v2;
			scanf("%d%d%d%d", &u1, &v1, &u2, &v2);
			getIntervals(u1, v1);
			int ans = 0;
			int lca = LCA(u2, v2);
			for(PII a : inter) {
				if(a.F <= t2.w[lca] && t2.w[lca] <= a.S) ans++;
				ans += query(root[u2], root[v2], root[lca], 1, n1, a.F, a.S);
			}
			printf("%d\n", ans);
		}
	}
	
	return 0;
}
