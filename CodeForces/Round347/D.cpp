#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int maxn = 100000 + 10;
const int INF = 10000000;

int n, m;

int head[maxn];

struct Edge
{
	int v, c, nxt;
	Edge() {}
	Edge(int v, int c, int nxt) : v(v), c(c), nxt(nxt) {}
};

int ecnt;
Edge edges[maxn * 2];

void AddEdge(int u, int v, int c) {
	edges[ecnt] = Edge(v, c, head[u]);
	head[u] = ecnt++;
	edges[ecnt] = Edge(u, c, head[v]);
	head[v] = ecnt++;
}

vector<int> ans[2], t1, t2, cc;

bool vis[maxn], choose[maxn];

void find_cc(int u) {
	cc.push_back(u);
	vis[u] = true;
	for(int i = head[u]; ~i; i = edges[i].nxt) {
		int v = edges[i].v;
		if(!vis[v]) find_cc(v);
	}
}

bool dfs(int u, int c, vector<int>& t) {
	vis[u] = true;
	if(choose[u]) t.push_back(u);
	for(int i = head[u]; ~i; i = edges[i].nxt) {
		int v = edges[i].v;
		if(vis[v] && (edges[i].c ^ choose[u] ^ choose[v] ^ c))
			return false;
		else if(!vis[v]) {
			choose[v] = edges[i].c ^ c ^ choose[u];
			if(!dfs(v, c, t)) return false;
		}
	}
	return true;
}

int solve(int c, vector<int>& ans) {
	memset(vis, false, sizeof(vis));
	int cnt = 0;
	for(int i = 1; i <= n; i++) if(!vis[i]) {
		cc.clear();
		find_cc(i);
		for(int j = 0; j < cc.size(); j++) vis[cc[j]] = false;

		t1.clear();
		choose[i] = false;
		bool ok1 = dfs(i, c, t1);
		for(int j = 0; j < cc.size(); j++) vis[cc[j]] = false;

		t2.clear();
		choose[i] = true;
		bool ok2 = dfs(i, c, t2);
		for(int j = 0; j < cc.size(); j++) vis[cc[j]] = true;

		if(!ok1 && !ok2) return INF;
		vector<int>* t;
		if(!ok1) t = &t2;
		else if(!ok2) t = &t1;
		else {
			if(t1.size() < t2.size()) t = &t1;
			else t = &t2;
		}
		ans.insert(ans.end(), (*t).begin(), (*t).end());
		cnt += (*t).size();
	}
	return cnt;
}

void output(vector<int>& ans) {
	for(int i = 0; i < ans.size(); i++) printf("%d ", ans[i]);
	printf("\n");
}

int main()
{
	ecnt = 0;
	memset(head, -1, sizeof(head));

	scanf("%d%d", &n, &m);
	for(int i = 0; i < m; i++) {
		int u, v;
		char color;
		scanf("%d %d %c", &u, &v, &color);
		AddEdge(u, v, color == 'R');
	}

	int a = solve(0, ans[0]);
	int b = solve(1, ans[1]);

	if(a == b && a == INF) { printf("-1\n"); return 0; }

	printf("%d\n", min(a, b));
	if(a < b) output(ans[0]);
	else output(ans[1]);

	return 0;
}
