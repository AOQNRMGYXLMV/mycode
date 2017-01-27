#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 100000 + 10;
const int maxm = 1000000 + 10;

int n, m;
int u[maxm], v[maxm], w[maxm], r[maxm];

bool cmp(int i, int j) { return w[i] < w[j]; }

int pa[maxn];
void init() { for(int i = 1; i <= n; i++) pa[i] = i; }
int findset(int x) { return pa[x] == x ? x : pa[x] = findset(pa[x]); }

int ecnt, head[maxn];
struct Edge
{
	int v, nxt, w;
	Edge() {}
	Edge(int v, int nxt, int w): v(v), nxt(nxt), w(w) {}
};

Edge edges[maxn * 2];

void AddEdge(int u, int v, int w) {
	edges[ecnt] = Edge(v, head[u], w);
	head[u] = ecnt++;
	edges[ecnt] = Edge(u, head[v], w);
	head[v] = ecnt++;
}

double ans2, tot;

int sz[maxn];
void dfs(int u, int fa) {
	sz[u] = 1;
	for(int i = head[u]; ~i; i = edges[i].nxt) {
		int v = edges[i].v;
		if(v == fa) continue;
		dfs(v, u);
		sz[u] += sz[v];
		ans2 += (double)edges[i].w * sz[v] * (n - sz[v]) / tot;
	}
}

int main()
{
	int T; scanf("%d", &T);
	while(T--) {
		scanf("%d%d", &n, &m);
		tot = (double)n * (n - 1) / 2;
		for(int i = 0; i < m; i++) {
			scanf("%d%d%d", u + i, v + i, w + i);
			r[i] = i;
		}
		sort(r, r + m, cmp);
		
		init();
		ecnt = 0;
		memset(head, -1, sizeof(head));
		long long ans1 = 0;
		ans2 = 0;
		for(int i = 0, cc = n; i < m; i++) {
			int pu = findset(u[r[i]]), pv = findset(v[r[i]]);
			if(pu != pv) {
				pa[pu] = pv;
				ans1 += w[r[i]];
				AddEdge(u[r[i]], v[r[i]], w[r[i]]);
				cc--;
			}
			if(cc == 1) break;
		}

		dfs(1, 0);
		printf("%lld %.2f\n", ans1, ans2);
	}

	return 0;
}
