#include <cstdio>
#include <cstring>
#include <algorithm>
#include <stack>
#include <vector>
using namespace std;

const int maxn = 10000 + 10;

int n, m;
vector<int> G[maxn];

stack<int> S;
int dfs_clock, pre[maxn], low[maxn];
int scc_cnt, sccno[maxn];

void dfs(int u) {
	pre[u] = low[u] = ++dfs_clock;
	S.push(u);
	for(int v : G[u]) {
		if(!pre[v]) {
			dfs(v);
			low[u] = min(low[u], low[v]);
		} else if(!sccno[v]) low[u] = min(low[u], pre[v]);
	}
	if(low[u] == pre[u]) {
		scc_cnt++;
		for(;;) {
			int x = S.top(); S.pop();
			sccno[x] = scc_cnt;
			if(x == u) break;
		}
	}
}

void find_scc() {
	dfs_clock = scc_cnt = 0;
	memset(pre, 0, sizeof(pre));
	memset(sccno, 0, sizeof(sccno));
	for(int i = 0; i < n; i++) if(!pre[i])
		dfs(i);
}

int color[maxn];

bool dfs2(int u, int minBack) {
	color[u] = 1;
	int backs = 0;
	for(int v : G[u]) if(color[v] == 1) {
		backs++;
		if(backs > 1) return false;
		if(pre[v] < minBack) return false;
	}
	if(backs) minBack = pre[u];
	for(int v : G[u]) {
		if(color[v] == 2) return false;
		if(color[v] == 0)
			if(!dfs2(v, minBack)) return false;;
	}
	color[u] = 2;
	return true;
}

int main()
{
	int T; scanf("%d", &T);
	while(T--) {
		scanf("%d%d", &n, &m);
		for(int i = 0; i < n; i++) G[i].clear();
		while(m--) {
			int u, v; scanf("%d%d", &u, &v);
			G[u].push_back(v);
		}
		
		find_scc();
		if(scc_cnt > 1) { puts("NO"); continue; }

		memset(color, 0, sizeof(color));
		if(!dfs2(0, 0)) puts("NO");
		else puts("YES");
	}

	return 0;
}
