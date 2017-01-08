#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

struct Edge
{
	int v, nxt;
	Edge() {}
	Edge(int v, int nxt): v(v), nxt(nxt) {}
};

const int maxn = 100000 + 10;

vector<int> child[maxn];

int ecnt, head[maxn];
Edge edges[maxn];
int vis[maxn];

void init() {
	ecnt = 0;
	memset(head, -1, sizeof(head));
	memset(vis, 0, sizeof(vis));
}

void AddEdge(int u, int v) {
	edges[ecnt] = Edge(v, head[u]);
	head[u] = ecnt++;
}

int tot, ans[maxn];
priority_queue<int> Q;

void bfs(int u) {
	memset(vis, 0, sizeof(vis));
	for(int i = 1; i <= n; i++) if(!vis[i]) {
		Q.push(i);
		vector<int> t;
		while(!Q.empty()) {
			int u = Q.top(); Q.pop();
			vis[u] = 1;
			t.push_back(u);
			
		}
	}
}

int n, m;

int main()
{
	int T; scanf("%d", &T);
	while(T--) {
		memset(vis, 0, sizeof(vis));
		scanf("%d%d", &n, &m);
		for(int i = 1; i <= n; i++) child[i].clear();
		while(m--) {
			int a, b; scanf("%d%d", &a, &b);
			child[a].push_back(b);
		}
		for(int i = 1; i <= n; i++) sort(child[i].begin(), child[i].end());
		tot = n;
		for(int i = 1; i <= n; i++) if(!vis[i])
			dfs(i);

		long long score = 0;
		int Min = n;
		for(int i = 1; i <= n; i++) {
			Min = min(Min, ans[i]);
			score += Min;
		}

		printf("%lld\n", score);
	}

	return 0;
}
