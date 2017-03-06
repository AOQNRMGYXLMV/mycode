#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

const int maxn = 200000 + 10;

vector<int> G[maxn];
bool vis[maxn];
int Q[maxn << 1], cnt;

void dfs(int u) {
	Q[++cnt] = u;
	vis[u] = true;
	for(int v : G[u]) if(!vis[v]) {
		dfs(v);
		Q[++cnt] = u;
	}
}

int main()
{
	int n, m, k; scanf("%d%d%d", &n, &m, &k);
	while(m--) {
		int u, v; scanf("%d%d", &u, &v);
		G[u].push_back(v);
		G[v].push_back(u);
	}

	dfs(1);
	int sz = cnt / k, r = cnt % k, p = 0;
	for(int i = 0; i < k; i++) {
		int t = sz;
		if(i < r) t++;
		printf("%d", t);
		for(int i = 0; i < t; i++) printf(" %d", Q[++p]);
		printf("\n");
	}

	return 0;
}
