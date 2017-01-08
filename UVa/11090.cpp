#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 50 + 5;
const int maxm = 3000;
const double INF = 1e9;

struct Edge
{
	int v, nxt;
	double w;
	Edge() {}
	Edge(int v, int nxt, double w): v(v), nxt(nxt), w(w) {}
};

int n, m;

int ecnt, head[maxn];
Edge edges[maxm];

void AddEdge(int u, int v, double w) {
	edges[ecnt] = Edge(v, head[u], w);
	head[u] = ecnt++;
}

double d[maxn][maxn];

int main()
{
	int T; scanf("%d", &T);
	for(int kase = 1; kase <= T; kase++) {
		printf("Case #%d: ", kase);

		scanf("%d%d", &n, &m);
		ecnt = 0;
		memset(head, -1, sizeof(head));
		while(m--) {
			int u, v;
			double w;
			scanf("%d%d%lf", &u, &v, &w);
			AddEdge(u, v, w);
		}
		
		int s = ++n;
		for(int i = 1; i < n; i++) AddEdge(s, i, 0);
		for(int i = 0; i <= n; i++)
			for(int j = 1; j <= n; j++) d[i][j] = INF;
		d[0][s] = 0;
		for(int k = 0; k < n; k++) {
			for(int u = 1; u <= n; u++) if(d[k][u] < INF) {
				for(int i = head[u]; ~i; i = edges[i].nxt) {
					int v = edges[i].v;
					double w = edges[i].w;
					if(d[k][u] + w < d[k + 1][v])
						d[k + 1][v] = d[k][u] + w;
				}
			}
		}

		double ans = INF;
		for(int v = 1; v <= n; v++) {
			double tmp = -INF;
			if(d[n][v] >= INF) continue;
			for(int k = 0; k < n; k++)
				tmp = max(tmp, (d[n][v] - d[k][v]) / (n - k));
			ans = min(ans, tmp);
		}

		if(ans >= 1e7 + 100) puts("No cycle found.");
		else printf("%.2f\n", ans);
	}

	return 0;
}
