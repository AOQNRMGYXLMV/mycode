#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
#define PB push_back
#define PII pair<int, int>
#define REP(i, a, b) for(int i = a; i < b; i++)
#define PER(i, a, b) for(int i = b - 1; i >= a; i--)
#define ALL(x) x.begin(), x.end()

const int maxn = 10000 + 10;

vector<int> G[maxn];

int c[maxn];

int ans;
void dfs(int u, int col) {
	if(c[u] != col) ans++;
	for(int v : G[u]) {
		dfs(v, c[u]);
	}
}

int main() {
	int n; scanf("%d", &n);
	REP(i, 1, n) {
		int p; scanf("%d", &p);
		G[p].PB(i + 1);
	}
	REP(i, 1, n + 1) scanf("%d", c + i);

	dfs(1, 0);
	printf("%d\n", ans);

	return 0;
}

