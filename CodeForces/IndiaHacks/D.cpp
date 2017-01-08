#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

const int maxn = 50 + 5;
const int maxm = 500 + 5;
const int INF = 0x3f3f3f3f;

struct Edge { int u, v, cap, flow; };

struct Dinic
{
	int n, m, s, t;
	vector<Edge> edges;
	vector<int> G[maxn];
	bool vis[maxn];
	int d[maxn];
	int cur[maxn];

	void init() {
		edges.clear();
		for(int i = 1; i <= n; i++) G[i].clear();
	}

	void AddEdge(int u, int v, int cap) {
		edges.push_back((Edge){u, v, cap, 0});
		edges.push_back((Edge){v, u, 0, 0});
		m = edges.size();
		G[u].push_back(m - 2);
		G[v].push_back(m - 1);
	}

	bool BFS() {
		memset(vis, false, sizeof(vis));
		queue<int> Q;
		Q.push(s);
		d[s] = 0;
		vis[s] = true;
		while(!Q.empty()) {
			int u = Q.front(); Q.pop();
			for(int i = 0; i < G[u].size(); i++) {
				Edge& e = edges[G[u][i]];
				if(!vis[e.v] && e.cap > e.flow) {
					vis[e.v] = true;
					d[e.v] = d[u] + 1;
					Q.push(e.v);
				}
			}
		}
		return vis[t];
	}

	int DFS(int u, int a) {
		if(u == t || a == 0) return a;
		int flow = 0, f;
		for(int& i = cur[u]; i < G[u].size(); i++) {
			Edge& e = edges[G[u][i]];
			if(d[u] + 1 == d[e.v] && (f = DFS(e.v, min(a, e.cap-e.flow))) > 0) {
				e.flow += f;
				edges[G[u][i]^1].flow -= f;
				flow += f;
				a -= f;
				if(a == 0) break;
			}
		}
		return flow;
	}

	int Maxflow() {
		int flow = 0;
		while(BFS()) {
			memset(cur, 0, sizeof(cur));
			flow += DFS(s, INF);
		}
		return flow;
	}
};

Dinic g;
int n, m, x;
int u[maxm], v[maxm], c[maxm];

int main()
{
	scanf("%d%d%d", &n, &m, &x);
	g.n = n, g.s = 1, g.t = n;
	for(int i = 0; i < m; i++) {
		scanf("%d%d%d", u + i, v + i, c + i);
	}

	double L = 1.0 / x, R = 1e6;
	for(int i = 0; i < 100; i++) {
		double mid = (L + R) * 0.5;
		g.init();
		for(int i = 0; i < m; i++) {
			g.AddEdge(u[i], v[i], (int)(c[i] / mid));
		}
		if(g.Maxflow() >= x) L = mid;
		else R = mid;
	}

	printf("%.10f\n", L * x);

	return 0;
}
