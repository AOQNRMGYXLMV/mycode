#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <sstream>
using namespace std;

struct Edge
{
	int v, nxt;
	Edge() {}
	Edge(int v, int nxt): v(v), nxt(nxt) {}
};

const int maxn = 100 + 10;

int n;
int ecnt, head[maxn];
Edge edges[maxn * maxn];

void AddEdge(int u, int v) {
	edges[ecnt] = Edge(v, head[u]);
	head[u] = ecnt++;
}

bool iscut[maxn];
int dfs_clock, pre[maxn], low[maxn];

void dfs(int u, int fa) {
	pre[u] = low[u] = ++dfs_clock;
	int child = 0;
	for(int i = head[u]; ~i; i = edges[i].nxt) {
		int v = edges[i].v;
		if(v == fa) continue;
		if(!pre[v]) {
			child++;
			dfs(v, u);
			low[u] = min(low[u], low[v]);
			if(low[v] >= pre[u]) iscut[u] = true;
		} else low[u] = min(low[u], pre[v]);
	}
	if(!fa && child == 1) iscut[u] = false;
}

int main()
{
	while(scanf("%d", &n) == 1 && n) {
		getchar();
		ecnt = 0;
		memset(head, -1, sizeof(head));
		string s;
		while(getline(cin, s)) {
			stringstream ss(s);
			int u, v;
			ss >> u;
			if(!u) break;
			while(ss >> v) { AddEdge(u, v); AddEdge(v, u); }
		}
		memset(iscut, false, sizeof(iscut));
		dfs_clock = 0;
		memset(pre, 0, sizeof(pre));
		memset(low, 0, sizeof(low));
		dfs(1, 0);
		int ans = 0;
		for(int i = 1; i <= n; i++) if(iscut[i]) ans++;
		printf("%d\n", ans);
	}

	return 0;
}
