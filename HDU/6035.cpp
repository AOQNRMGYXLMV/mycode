#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <set>
#include <vector>
#include <iostream>
#include <string>
using namespace std;
#define REP(i, a, b) for(int i = a; i < b; i++)
#define PER(i, a, b) for(int i = b - 1; i >= a; i--)
#define SZ(a) ((int)a.size())
#define MP make_pair
#define PB push_back
#define EB emplace_back
#define ALL(a) a.begin(), a.end()
typedef long long LL;
typedef pair<int, int> PII;

const int maxn = 200000 + 10;

int n;
vector<int> G[maxn];
int c[maxn], cut[maxn], sz[maxn];
LL ans;

void dfs(int u, int p = 0) {
	sz[u] = 1;
	int sum = 0;
	for(int v : G[u]) if(v != p) {
		int t = cut[c[u]];
		dfs(v, u);
		int d = sz[v] - (cut[c[u]] - t);
		sum += d;
		ans -= (LL)d * (d - 1) / 2;
		sz[u] += sz[v];
	}
	cut[c[u]] += sum + 1;
}

int main() {
	int _ = 1;
	while(scanf("%d", &n) == 1) {
		printf("Case #%d: ", _++);
		ans = (LL)n * n * (n - 1) / 2;
		memset(cut, 0, sizeof(cut));
		REP(i, 1, n + 1) {
			G[i].clear();
			scanf("%d", c + i);
		}
		REP(i, 1, n) {
			int u, v; scanf("%d%d", &u, &v);
			G[u].push_back(v);
			G[v].push_back(u);
		}

		dfs(1);
		REP(i, 1, n + 1) ans -= (LL)(n - cut[i]) * (n - cut[i] - 1) / 2;
		printf("%I64d\n", ans);
	}

	return 0;
}


