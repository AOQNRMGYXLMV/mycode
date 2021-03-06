#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 200000 + 10;
const int INF = 0x3f3f3f3f;

struct Edge
{
	int v, nxt;
	Edge(int v = 0, int nxt = 0): v(v), nxt(nxt) {}
};

int ecnt, head[maxn];
Edge edges[maxn * 2];

void AddEdge(int u, int v) {
	edges[ecnt] = Edge(v, head[u]);
	head[u] = ecnt++;
}

int n, q, w[maxn];

int sz[maxn], fa[maxn], son[maxn], dep[maxn];

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

int top[maxn], id[maxn], pos[maxn], tot;

void dfs2(int u, int tp) {
	id[u] = ++tot;
	pos[tot] = u;
	top[u] = tp;
	if(!son[u]) return;
	dfs2(son[u], tp);
	for(int i = head[u]; ~i; i = edges[i].nxt) {
		int v = edges[i].v;
		if(v == fa[u] || v == son[u]) continue;
		dfs2(v, v);
	}
}

struct Node
{
	int sum, pre, suf, sub;
	Node() {}
	Node(int a, int b, int c, int d): sum(a), pre(b), suf(c), sub(d) {}
	Node operator + (const Node& t) const {
		Node ans;
		ans.sum = sum + t.sum;
		ans.pre = max(pre, sum + t.pre);
		ans.suf = max(t.suf, t.sum + suf);
		ans.sub = max(max(sub, t.sub), suf + t.pre);
		return ans;
	}
};

Node T[maxn << 2];
int set[maxn << 2];

void build(int o, int L, int R) {
	if(L == R) {
		T[o].sum = T[o].pre = T[o].suf = T[o].sub = w[pos[L]];
		return;
	}
	int M = (L + R) / 2;
	build(o<<1, L, M);
	build(o<<1|1, M+1, R);
	T[o] = T[o<<1] + T[o<<1|1];
}

void pushdown(int o, int L, int R) {
	if(set[o] != INF) {
		set[o<<1] = set[o<<1|1] = set[o];
		int lc = o<<1, rc = o<<1|1;
		int M = (L + R) / 2;
		T[lc].sum = set[o] * (M - L + 1);
		T[rc].sum = set[o] * (R - M);
		T[lc].pre = T[lc].suf = T[lc].sub = set[o] > 0 ? T[lc].sum : set[o];
		T[rc].pre = T[rc].suf = T[rc].sub = set[o] > 0 ? T[rc].sum : set[o];
		set[o] = INF;
	}
}

void update(int o, int L, int R, int qL, int qR, int v) {
	if(qL <= L && R <= qR) {
		set[o] = v;
		T[o].sum = (R - L + 1) * v;
		T[o].pre = T[o].suf = T[o].sub = v > 0 ? T[o].sum : v;
		return;
	}
	pushdown(o, L, R);
	int M = (L + R) / 2;
	if(qL <= M) update(o<<1, L, M, qL, qR, v);
	if(qR > M) update(o<<1|1, M+1, R, qL, qR, v);
	T[o] = T[o<<1] + T[o<<1|1];
}

void UPDATE(int u, int v, int val) {
	int t1 = top[u], t2 = top[v];
	while(t1 != t2) {
		if(dep[t1] < dep[t2]) { swap(u, v); swap(t1, t2); }
		update(1, 1, n, id[t1], id[u], val);
		u = fa[t1]; t1 = top[u];
	}
	if(dep[u] > dep[v]) swap(u, v);
	update(1, 1, n, id[u], id[v], val);
}

Node query(int o, int L, int R, int qL, int qR) {
	if(qL <= L && R <= qR) return T[o];
	pushdown(o, L, R);
	int M = (L + R) / 2;
	if(qR <= M) return query(o<<1, L, M, qL, qR);
	else if(qL > M) return query(o<<1|1, M+1, R, qL, qR);
	else return query(o<<1, L, M, qL, qR) + query(o<<1|1, M+1, R, qL, qR);
}

void updateans(Node& q, bool& flag, int L, int R) {
	if(!flag) { q = query(1, 1, n, L, R); flag = true; }
	else q = query(1, 1, n, L, R) + q;
}

int QUERY(int u, int v) {
	Node q1, q2;
	bool flag1 = false, flag2 = false;
	int t1 = top[u], t2 = top[v];
	while(t1 != t2) {
		if(dep[t1] > dep[t2]) {
			updateans(q1, flag1, id[t1], id[u]);
			u = fa[t1]; t1 = top[u];
		} else {
			updateans(q2, flag2, id[t2], id[v]);;
			v = fa[t2]; t2 = top[v];
		}
	}
	if(dep[u] > dep[v]) updateans(q1, flag1, id[v], id[u]);
	else updateans(q2, flag2, id[u], id[v]);
	if(!flag1) return q2.sub;
	if(!flag2) return q1.sub;
	swap(q1.pre, q1.suf);
	return (q1 + q2).sub;
}

int main()
{
	scanf("%d%d", &n, &q);
	for(int i = 1; i <= n; i++) scanf("%d", w + i);

	ecnt = 0;
	memset(head, -1, sizeof(head));
	for(int i = 1; i < n; i++) {
		int u, v; scanf("%d%d", &u, &v);
		AddEdge(u, v); AddEdge(v, u);
	}

	int root = (n + 1) / 2;

	dfs(root);
	tot = 0;
	dfs2(root, root);
	
	memset(set, 0x3f, sizeof(set));
	build(1, 1, n);

	while(q--) {
		int op, a, b, c; scanf("%d%d%d%d", &op, &a, &b, &c);
		if(op == 1) UPDATE(a, b, c);
		else printf("%d\n", QUERY(a, b));
	}

	return 0;
}
