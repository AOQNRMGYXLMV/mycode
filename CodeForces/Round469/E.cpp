#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <set>
#include <vector>
#include <iostream>
#include <string>
#include <stack>
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

const int maxn = 100000 + 10;

int n, m, h;

int x[maxn];
vector<int> G[maxn], G2[maxn];

int pre[maxn], scc_size[maxn], sccno[maxn];
stack<int> S;

int dfs_clock, scc_cnt;

int dfs(int u) {
	pre[u] = ++dfs_clock;
	int low = pre[u];
	S.push(u);
	for(int i = 0; i < (int)G[u].size(); i++) {
		int v = G[u][i];
		if(!pre[v]) {
			int lowv = dfs(v);
			low = min(low, lowv);
		} else if(!sccno[v]) low = min(low, pre[v]);
	}

	if(low == pre[u]) {
		++scc_cnt;
		for(;;) {
			int x = S.top(); S.pop();
			sccno[x] = scc_cnt;
			scc_size[scc_cnt]++;
			if(x == u) break;
		}
	}

	return low;
}

int dp[maxn], ans, choose;

void dfs2(int u) {
	if(pre[u]) return;
	pre[u] = 1;
	if(!G2[u].size()) {
		if(scc_size[u] < ans) {
			ans = scc_size[u];
			choose = u;
		}
		return;
	}
	for(int v : G2[u]) if(!pre[v])
		dfs2(v);
}

int main() {
	scanf("%d%d%d", &n, &m, &h);
	REP(i, 0, n) scanf("%d", x + i);
	while(m--) {
		int u, v; scanf("%d%d", &u, &v);
		u--; v--;
		if(x[v] == ((x[u] + 1) % h)) {
			G[u].push_back(v);
		}
		if(x[u] == ((x[v] + 1) % h)) {
			G[v].push_back(u);
		}
	}

	REP(i, 0, n) if(!pre[i]) {
		dfs(i);
	}

	REP(u, 0, n) REP(i, 0, (int)G[u].size()) {
		int v = G[u][i];
		if(sccno[u] == sccno[v]) continue;
		G2[sccno[u]].push_back(sccno[v]);
	}

	memset(pre, 0, sizeof(pre));
	ans = n + 1;
	REP(i, 1, scc_cnt + 1) if(!pre[i]) {
		dfs2(i);
	}

	printf("%d\n", ans);
	REP(i, 0, n) if(sccno[i] == choose) printf("%d ", i + 1);
	printf("\n");

	return 0;
}



