#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

typedef long long LL;

const int maxn = 200000 + 10;

vector<int> G[maxn];

int n, k, sz[maxn][5];
LL d[maxn][5], ans;

void dfs(int u, int fa) {
	int tsz[5];
	LL td[5];
	for(int v : G[u]) if(v != fa) {
		dfs(v, u);
		memset(tsz, 0, sizeof(tsz));
		for(int i = 0; i < k; i++) tsz[(i+1)%k] += sz[v][i];

		memset(td, 0, sizeof(td));
		for(int i = 1; i < k; i++) td[(i+1)%k] += d[v][i];
		td[1%k] += d[v][0] + sz[v][0];

		for(int i = 0; i < k; i++) {
			for(int j = 0; j < k; j++) {
				int delta = (i+j+k-1)/k - (i>0) - (j>0);
				ans += d[u][i] * tsz[j] + td[j] * sz[u][i];
				if(delta) ans += (LL) delta * sz[u][i] * tsz[j];
			}
		}

		for(int i = 0; i < k; i++) { d[u][i] += td[i]; sz[u][i] += tsz[i]; }
	}
	for(int i = 0; i < k; i++) ans += d[u][i];
	sz[u][0]++;
}

int main()
{
	scanf("%d%d", &n, &k);
	for(int i = 1; i < n; i++) {
		int u, v; scanf("%d%d", &u, &v);
		G[u].push_back(v);
		G[v].push_back(u);
	}

	dfs(1, 0);

	printf("%lld\n", ans);

	return 0;
}
