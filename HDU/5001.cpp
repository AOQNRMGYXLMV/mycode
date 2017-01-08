#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 50 + 10;
const int maxm = 2500 + 10;

double dp[2][maxn];

struct Edge
{
	int v, nxt;
	Edge() {}
	Edge(int v, int nxt): v(v), nxt(nxt) {}
};

int ecnt, head[maxn];
Edge edges[maxm];

void AddEdge(int u, int v) {
	edges[ecnt] = Edge(v, head[u]);
	head[u] = ecnt++;
}

int deg[maxn];

int main()
{
	int T; scanf("%d", &T);
	while(T--) {
		int n, m, d; scanf("%d%d%d", &n, &m, &d);
		ecnt = 0;
		memset(head, -1, sizeof(head));
		memset(deg, 0, sizeof(deg));
		while(m--) {
			int u, v; scanf("%d%d", &u, &v);
			AddEdge(u, v);
			AddEdge(v, u);
			deg[u]++;
			deg[v]++;
		}

		for(int forbid = 1; forbid <= n; forbid++) {
			memset(dp[0], 0, sizeof(dp[0]));
			for(int i = 1; i <= n; i++) if(i != forbid)
				dp[0][i] = 1.0 / n;
			dp[0][forbid] = 0;
			int cur = 0;
			for(int i = 0; i < d; i++) {
				memset(dp[cur^1], 0, sizeof(dp[cur^1]));
				for(int u = 1; u <= n; u++) if(u != forbid) {
					for(int j = head[u]; ~j; j = edges[j].nxt) {
						int v = edges[j].v;
						if(v == forbid) continue;
						dp[cur^1][v] += dp[cur][u] / deg[u];
					}
				}
				cur ^= 1;
			}
			double ans = 0;
			for(int i = 1; i <= n; i++)
				if(i != forbid) ans += dp[cur][i];
			printf("%.10f\n", ans);
		}
	}

	return 0;
}
