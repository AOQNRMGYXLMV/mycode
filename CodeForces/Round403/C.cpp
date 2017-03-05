#include <cstdio>
#include <vector>
using namespace std;

const int maxn = 200000 + 10;

int n, color[maxn];
vector<int> G[maxn];

void dfs(int u, int fa) {
	int cur = 0;
	for(int v : G[u]) if(v != fa) {
		cur++;
		while(cur == color[u] || cur == color[fa]) cur++;
		color[v] = cur;
		dfs(v, u);
	}
}

int main()
{
	scanf("%d", &n);
	for(int i = 1; i < n; i++) {
		int u, v; scanf("%d%d", &u, &v);
		G[u].push_back(v);
		G[v].push_back(u);
	}

	color[1] = 1;
	dfs(1, 0);
	int Max = 0;
	for(int i = 1; i <= n; i++) if(color[i] > Max) Max = color[i];
	printf("%d\n", Max);
	for(int i = 1; i < n; i++) printf("%d ", color[i]);
	printf("%d\n", color[n]);

	return 0;
}
