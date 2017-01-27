#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n, m, p[10];
bool rule[10][10];

bool G[10][10];
int left[10], vis[10];

int match(int x) {
	for(int y = 1; y <= n; y++) {
		if(G[x][y] && !vis[y]) {
			vis[y] = true;
			if(!left[y] || match(left[y])) {
				left[y] = x;
				return true;
			}
		}
	}
	return false;
}

int solve() {
	int ans = 0;
	memset(left, 0, sizeof(left));
	for(int i = 1; i <= n; i++) {
		memset(vis, false, sizeof(vis));
		if(match(i)) ans++;
	}
	return ans;
}

int main()
{
	while(scanf("%d%d", &n, &m) == 2) {
		if(n == 0) { printf("0\n"); continue; }
		memset(rule, false, sizeof(rule));
		for(int i = 0; i < m; i++) {
			int x, y; scanf("%d%d", &x, &y);
			rule[x][y] = true;
		}
		if(n == 1) { printf("%d\n", m); continue; }

		for(int i = 0; i < n; i++) p[i] = i + 1;
		p[n] = p[0];
		int fac = 1;
		for(int i = 1; i < n; i++) fac *= i;

		int ans = 0;
		for(int k = 0; k < fac; k++) {
			//build graph
			memset(G, false, sizeof(G));
			for(int i = 1; i <= n; i++) {
				for(int j = 1; j <= n; j++) {
					if(!rule[i][p[j-1]] && !rule[i][p[j]])
						G[i][j] = true;
				}
			}
			ans = max(ans, solve());
			next_permutation(p, p + n);
			p[n] = p[0];
		}
		printf("%d\n", n - ans);
	}

	return 0;
}
