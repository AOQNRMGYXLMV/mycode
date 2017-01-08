#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 100000 + 10;
const int M = 20;
int n, m;

struct Edge
{
	int v, w, nxt;
	Edge() {}
	Edge(int v, int w, int nxt): v(v), w(w), nxt(nxt) {}
};

int ecnt, head[maxn];
Edge edges[maxn * 2];

void AddEdge(int u, int v, int w) {
	edges[ecnt] = Edge(v, w, head[u]);
	head[u] = ecnt++;
}

struct Node
{
	int lch, rch, cnt, sum;
}T[maxn << 5];
int sz, root[maxn];

int update(int pre, int L, int R, int pos) {
	int rt = ++sz;
	T[rt] = T[pre];
	T[rt].cnt++;
	T[rt].sum += pos;
	if(L < R) {
		int M = (L + R) / 2;
		if(pos <= M) T[rt].lch = update(T[pre].lch, L, M, pos);
		else T[rt].rch = update(T[pre].rch, M+1, R, pos);
	}
	return rt;
}

int query(int u, int v, int l, int L, int R, int k) {
	if(L == R) return L;
	int M = (L + R) / 2;
	int sum = T[T[u].lch].cnt + T[T[v].lch].cnt - T[T[l].lch].cnt * 2;
	if(sum >= k) return query(T[u].lch, T[v].lch, T[l].lch, L, M, k);
	else return query(T[u].rch, T[v].rch, T[l].rch, M+1, R, k - sum);
}

int fa[maxn], dep[maxn];

void dfs(int u) {
	for(int i = head[u]; ~i; i = edges[i].nxt) {
		int v = edges[i].v;
		if(v == fa[u]) continue;
		fa[v] = u;
		dep[v] = dep[u] + 1;
		root[v] = update(root[u], 0, M, edges[i].w);
		dfs(v);
	}
}

int anc[maxn][20];

void preprocess() {
	memset(anc, 0, sizeof(anc));
	for(int i = 1; i <= n; i++) anc[i][0] = fa[i];
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
	return fa[u];
}

int bsearch(int u, int v, int l, int x) {
	int L = 0, R = M, cnt = 0, sum = 0;
	while(L < R) {
		int mid = (L + R) / 2;
		int tcnt = T[T[u].lch].cnt + T[T[v].lch].cnt - T[T[l].lch].cnt * 2;
		int tsum = T[T[u].lch].sum + T[T[v].lch].sum - T[T[l].lch].sum * 2;
		if((cnt + tcnt) * mid - tsum - sum > x) {
			u = T[u].lch, v = T[v].lch, l = T[l].lch;
			R = mid;
		} else {
			cnt += tcnt; sum += tsum;
			u = T[u].rch, v = T[v].rch, l = T[l].rch;
			L = mid + 1;
		}
	}
	return L - 1;
}

int main()
{
	freopen("in.txt", "r", stdin);
	int _; scanf("%d", &_);
	for(int kase = 1; kase <= _; kase++) {
		printf("Case #%d:\n", kase);

		scanf("%d%d", &n, &m); sz = 0;
		ecnt = 0;
		memset(head, -1, sizeof(head));
		for(int i = 1; i < n; i++) {
			int u, v, w; scanf("%d%d%d", &u, &v, &w);
			AddEdge(u, v, w); AddEdge(v, u, w);
		}

		dfs(1); preprocess();
		while(m--) {
			int u, v, k, a, b;
			scanf("%d%d%d%d%d", &u, &v, &k, &a, &b);
			int lca = LCA(u, v);
			int base = query(root[u], root[v], root[lca], 0, M, 1);
			if(a <= b) printf("%d\n", base + k / a);
			else {
				int ans = base;
				if(k >= a) ans += (k - a) / b + 1;
				int x = k / b;
				ans = max(ans, bsearch(root[u], root[v], root[lca], x));
				printf("%d\n", ans);
			}
		}
	}

	return 0;
}
