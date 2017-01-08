#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
using namespace std;

const int maxn = 100 + 10;

int n;

struct Edge
{
	int v, nxt;
	Edge() {}
	Edge(int v, int nxt): v(v), nxt(nxt) {}
};

int ecnt, head[maxn];
Edge edges[maxn * maxn];

void AddEdge(int u, int v) {
	edges[ecnt] = Edge(v, head[u]);
	head[u] = ecnt++;
}

string names[maxn];
vector<string> ans;
map<string, int> Map;

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
			if(fa && low[v] >= pre[u]) iscut[u] = true;
			else if(!fa && child > 1) iscut[u] = true;
		} else low[u] = min(low[u], pre[v]);
	}
}

void find_cut() {
	dfs_clock = 0;
	memset(pre, 0, sizeof(pre));
	memset(iscut, false, sizeof(iscut));
	memset(low, 0, sizeof(low));
	for(int i = 1; i <= n; i++) if(!pre[i])
		dfs(i, 0);
}

int main()
{
	//freopen("in.txt", "r", stdin);
	int kase = 1;
	while(scanf("%d", &n) == 1 && n) {
		ans.clear();
		Map.clear();
		for(int i = 1; i <= n; i++) {
			cin >> names[i];
			Map[names[i]] = i;
		}

		memset(head, -1, sizeof(head));
		ecnt = 0;
		int m; scanf("%d", &m);
		while(m--) {
			string s1, s2; cin >> s1 >> s2;
			int u = Map[s1], v = Map[s2];
			AddEdge(u, v); AddEdge(v, u);
		}

		find_cut();
		if(kase > 1) printf("\n");
		for(int i = 1; i <= n; i++) if(iscut[i])
			ans.push_back(names[i]);
		int sz = ans.size();
		sort(ans.begin(), ans.end());
		printf("City map #%d: %d camera(s) found\n", kase++, sz);
		for(string s : ans) cout << s << endl;
	}

	return 0;
}
