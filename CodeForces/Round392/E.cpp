#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 200000 + 10;

typedef long long LL;

int n, head[maxn];

struct Edge
{
	int u, v, nxt, w, p;
	Edge() {}
	Edge(int u, int v, int n, int w, int p): u(u), v(v), nxt(n), w(w), p(p) {}
};

int ecnt;
Edge edges[maxn];

void init() { memset(head, -1, sizeof(head)); }

void AddEdge(int u, int v, int w, int p) {
	edges[ecnt] = Edge(u, v, head[u], w, p);
	head[u] = ecnt++;
}

int fa[maxn], allocation[maxn];
LL minw[maxn], maxw[maxn], add[maxn];

bool dfs_min(int u) {
	for(int i = head[u]; ~i; i = edges[i].nxt) {
		int v = edges[i].v, w = edges[i].w, p = edges[i].p;
		fa[v] = i;
		if(!dfs_min(v)) return false;
		if((LL)p < minw[v]) return false;
		else if(p > minw[v]) {
			int t = min(p - minw[v], (LL)w - 1);
			w -= t;
		}
		minw[u] += minw[v];
		minw[u] += w;
	}
	return true;
}

void dfs_max(int u) {
	for(int i = head[u]; ~i; i = edges[i].nxt) {
		int v = edges[i].v, w = edges[i].w, p = edges[i].p;
		dfs_max(v);
		maxw[u] += w;
		maxw[u] += maxw[v];
	}
	add[u] = maxw[u];
	if(u != 1 && (LL)edges[fa[u]].p < maxw[u]) maxw[u] = edges[fa[u]].p;
}

void dfs(int u) {
	if(u == 1) {
		allocation[u] = maxw[u];
		for(int i = head[u]; ~i; i = edges[i].nxt) {
			int v = edges[i].v;
			allocation[v] = maxw[v];
			dfs(v);
		}
		return;
	}
	LL overfllow = add[u] - allocation[u];
	for(int i = head[u]; ~i; i = edges[i].nxt) {
		int v = edges[i].v, &p = edges[i].p, &w = edges[i].w;
		if(overfllow) {
			LL t = min(maxw[v] - minw[v], overfllow);
			allocation[v] = maxw[v] - t;
			overfllow -= t;
			t = min(overfllow, min((LL)p - allocation[v], (LL)w - 1));
			overfllow -= t;
			w -= t; p -= t;
		} else allocation[v] = maxw[v];
		dfs(v);
	}
}

int main()
{
	scanf("%d", &n);
	init();
	for(int i = 0; i < n - 1; i++) {
		int u, v, w, p;
		scanf("%d%d%d%d", &u, &v, &w, &p);
		AddEdge(u, v, w, p);
	}

	if(!dfs_min(1)) { printf("-1\n"); return 0; }

	dfs_max(1);
	dfs(1);

	printf("%d\n", n);
	for(int i = 0; i < n - 1; i++) {
		Edge& e = edges[i];
		printf("%d %d %d %d\n", e.u, e.v, e.w, e.p);
	}

	return 0;
}
