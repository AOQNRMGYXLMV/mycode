#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 300000 + 10;

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
int color[maxn];

int dfs_clock, pre[maxn], low[maxn];
bool isbridge[maxn];

void dfs(int u, int fa) {
	low[u] = pre[u] = dfs_clock;
	for(int i = head[u]; ~i; i = edges[i].nxt) {
		if(i == fa ^ 1) continue;
		int v = edges[i].v;
		if(!pre[v]) {
			dfs(v, i);
			low[u] = min(low[u], low[v]);
			if(low[v] > low[u]) isbridge[i>>1] = true;
		}
	}
}

int main()
{
	scanf("%d%d", &n, &m);

	memset(head, -1, sizeof(head));
	for(int i = 0; i < m; i++) {
		int u, v;
		scanf("%d%d%d", &u, &v, &color[i]);
		AddEdge(u, v); AddEdge(v, u);
	}



	return 0;
}
