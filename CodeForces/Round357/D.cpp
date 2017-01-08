#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int maxn = 100000 + 10;

int n, m, a[maxn], c[maxn];
vector<int> b, ans, g[maxn];
bool rec[maxn], vis[maxn];

void topo(int u) {
	if(vis[u]) return;
	vis[u] = true;
	for(int v : g[u]) topo(v);
	b.push_back(u);
}

void dfs(int u, int color) {
	if(c[u]) return;
	c[u] = color;
	for(int v : g[u]) dfs(v, color);
}

int main()
{
	scanf("%d%d", &n, &m);
	while(m--) {
		int a, b; scanf("%d%d", &a, &b);
		g[a].push_back(b);
	}
	for(int i = 1; i <= n; i++) {
		scanf("%d", a + i);
		rec[a[i]] = true;
	}
	for(int i = 1; i <= n; i++) if(!vis[i]) topo(i);

	for(int i = 0; i < n; i++) if(rec[b[i]]) {
		dfs(b[i], b[i]);
		ans.push_back(b[i]);
	}

	for(int i = 1; i <= n; i++) if(a[i] != c[i]) {
		printf("-1\n");
		return 0;
	}

	printf("%d\n", ans.size());
	for(int i : ans) printf("%d\n", i);

	return 0;
}
