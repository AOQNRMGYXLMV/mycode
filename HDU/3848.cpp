#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 10000 + 10;
const int INF = 0x3f3f3f3f;

struct Edge
{
	int v, w, nxt;
	Edge() {}
	Edge(int v, int w, int nxt): v(v), w(w), nxt(nxt) {}
};

int ecnt, head[maxn];
Edge edges[maxn * 2];

void AddEdge(int u, int v, int w) {
	edges[ecnt] = Edge(v, w, head[u]); head[u] = ecnt++;
	edges[ecnt] = Edge(u, w, head[v]); head[v] = ecnt++;
}

int n;

int ans;
int minv[maxn];
int child[maxn];

void dfs(int u, int p) {
	minv[u] = INF;
	int minp = INF;
	child[u] = 0;
	for(int i = head[u]; ~i; i = edges[i].nxt) {
		int v = edges[i].v;
		if(v == p) continue;
		child[u]++;
		int w = edges[i].w;
		dfs(v, u);
		minv[u] = min(minv[u], minv[v] + w);
		ans = min(ans, minp + minv[v] + w);
		minp = min(minp, minv[v] + w);
	}
	if(!child[u]) minv[u] = 0;
}

int main()
{
	freopen("in.txt", "r", stdin);
	while(scanf("%d", &n) == 1 && n) {
		ecnt = 0;
		memset(head, -1, sizeof(head));
		for(int i = 1; i < n; i++) {
			int u, v, w; scanf("%d%d%d", &u, &v, &w);
			AddEdge(u, v, w);
		}

		ans = INF;
		dfs(1, 0);
		if(child[1] == 1) ans = min(ans, minv[1]);
		printf("%d\n", ans);
	}

	return 0;
}
