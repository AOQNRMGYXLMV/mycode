#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 100000 + 10;
const int maxnode = maxn * 4;

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

int n;

int fa[maxn], sz[maxn], son[maxn], dep[maxn];

void dfs(int u) {
	sz[u] = 1; son[u] = 0;
	for(int i = head[u]; ~i; i = edges[i].nxt) {
		int v = edges[i].v;
		if(v == fa[u]) continue;
		fa[v] = u;
		dep[v] = dep[u] + 1;
		dfs(v);
		sz[u] += sz[v];
		if(sz[v] > sz[son[u]]) son[u] = v;
	}
}

int tot, top[maxn], id[maxn], pos[maxn];

void dfs2(int u, int tp) {
	top[u] = tp;
	id[u] = ++tot;
	pos[tot] = u;
	if(!son[u]) return;
	dfs2(son[u], tp);
	for(int i = head[u]; ~i; i = edges[i].nxt) {
		int v = edges[i].v;
		if(v == fa[u] || v == son[u]) continue;
		dfs2(v, v);
	}
}

int color[maxn], addv[2][maxnode];
int fir[2][maxnode];

void build(int o, int L, int R) {
	if(L == R) {
		fir[0][o] = 0; fir[1][o] = L;
		addv[0][o] = 1; addv[1][o] = sz[pos[L]];
		return;
	}
	int M = (L + R) / 2;
	build(o<<1, L, M);
	build(o<<1|1, M+1, R);

	fir[0][o] = 0;
	fir[1][o] = R;
}

void pushdown(int o) {
	for(int i = 0; i < 2; i++) {
		int& t = addv[i][o];
		if(!t) continue;
		addv[i][o<<1] += t;
		addv[i][o<<1|1] += t;
		t = 0;
	}
}

void update(int o, int L, int R, int qL, int qR, int col, int v) {
	if(qL <= L && R <= qR) {
		addv[col][o] += v;
		return;
	}
	pushdown(o);
	int M = (L + R) / 2;
	if(qL <= M) update(o<<1, L, M, qL, qR, col, v);
	if(qR > M) update(o<<1|1, M+1, R, qL, qR, col, v);
}

void UPDATE(int u, int v, int col, int val) {
	while(top[u] != top[v]) {
		update(1, 1, n, id[top[u]], id[u], col, val);
		u = fa[top[u]];
	}
	update(1, 1, n, id[v], id[u], col, val);
}

int querysize(int o, int L, int R, int p, int col) {
	if(L == R) return addv[col][o];
	pushdown(o);
	int M = (L + R) / 2;
	if(p <= M) return querysize(o<<1, L, M, p, col);
	else return querysize(o<<1|1, M+1, R, p, col);
}

int queryfir(int o, int L, int R, int qL, int qR, int col) {
	if(qL <= L && R <= qR) return fir[col][o];
	int ans = 0;
	int M = (L + R) / 2;
	if(qR > M) ans = queryfir(o<<1|1, M+1, R, qL, qR, col);
	if(ans) return ans;
	if(qL <= M) ans = queryfir(o<<1, L, M, qL, qR, col);
	return ans;
}

int QueryFir(int u, int col) {
	int ans = 0;
	int t = top[u];
	while(t != 1) {
		ans = queryfir(1, 1, n, id[t], id[u], col);
		if(ans) return ans;
		u = fa[t]; t = top[u];
	}
	return queryfir(1, 1, n, 1, id[u], col);

}

int QuerySuf(int u, int col) {
	int ans = id[u];
	while(top[u] != 1) {
		int t = queryfir(1, 1, n, id[top[u]], id[u], col ^ 1);
		if(t) return t == id[u] ? ans : t + 1;
		ans = id[top[u]];
		u = fa[top[u]];
	}
	int t = queryfir(1, 1, n, 1, id[u], col ^ 1);
	if(!t) return 1;
	return t == id[u] ? ans : t + 1;
}

void change(int o, int L, int R, int p) {
	if(L == R) {
		int u = pos[L];
		int& c = color[u];
		c ^= 1;
		fir[c][o] = L;
		fir[c ^ 1][o] = 0;
		return;
	}
	int M = (L + R) / 2, lenr = R - M;
	if(p <= M) change(o<<1, L, M, p);
	else change(o<<1|1, M+1, R, p);
	fir[0][o] = fir[0][o<<1|1] ? fir[0][o<<1|1] : fir[0][o<<1];
	fir[1][o] = fir[1][o<<1|1] ? fir[1][o<<1|1] : fir[1][o<<1];
}

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) color[i] = 1;

	ecnt = 0;
	memset(head, -1, sizeof(head));
	for(int i = 1; i < n; i++) {
		int u, v; scanf("%d%d", &u, &v);
		AddEdge(u, v);
		AddEdge(v, u);
	}

	dfs(1);
	tot = 0;
	dfs2(1, 1);

	build(1, 1, n);
	int _; scanf("%d", &_);
	while(_--) {
		int op, u; scanf("%d%d", &op, &u);
		if(op == 0) {
			int v = pos[QuerySuf(u, color[u])];
			int ans = querysize(1, 1, n, id[v], color[v]);
			printf("%d\n", ans);
		} else {
			if(u != 1) {
				int v = pos[QueryFir(fa[u], color[u] ^ 1)];
				if(!v) v = 1;
				int sub = querysize(1, 1, n, id[u], color[u]);
				UPDATE(fa[u], v, color[u], -sub);

				v = pos[QueryFir(fa[u], color[u])];
				if(!v) v = 1;
				int add = querysize(1, 1, n, id[u], color[u] ^ 1);
				UPDATE(fa[u], v, color[u] ^ 1, add);
			}

			change(1, 1, n, id[u]);
		}
	}

	return 0;
}
