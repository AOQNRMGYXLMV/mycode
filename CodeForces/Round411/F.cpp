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

const int maxn = 100000 + 10;

int n, m, q;
vector<int> G[maxn], dis[maxn];
vector<LL> pre[maxn];
int f[maxn], d[maxn], cnt;
map<PII, LL> ans;

int pa[maxn], sz[maxn];
int findset(int x) { return x == pa[x] ? x : pa[x] = findset(pa[x]); }
void Union(int x, int y) {
	int px = findset(x), py = findset(y);
	if(px != py) {
		pa[px] = py;
		sz[py] += sz[px];
	}
}

int id, depth, root, flag;
void dfs(int u, int fa = -1, int h = 0) {
	if(h > depth) { depth = h; id = u; }
	if(f[u] < h) f[u] = h;
	if(flag) dis[root].PB(f[u]);
	for(int v : G[u]) if(v != fa) dfs(v, u, h + 1);

}

int main() {
	scanf("%d%d%d", &n, &m, &q);
	REP(i, 0, n) pa[i] = i, sz[i] = 1;
	while(m--) {
		int u, v; scanf("%d%d", &u, &v);
		u--; v--;
		Union(u, v);
		G[u].push_back(v);
		G[v].push_back(u);
	}

	REP(i, 0, n) if(i == pa[i]) {
		flag = false; root = i;
		depth = 0; id = i; dfs(i);
		depth = 0; dfs(id); d[i] = depth;
		flag = true; dfs(id);
		sort(ALL(dis[i]));
		pre[i].resize(sz[i] + 1);
		pre[i][0] = 0;
		REP(j, 0, SZ(dis[i])) pre[i][j + 1] = pre[i][j] + dis[i][j];
	}

	while(q--) {
		int u, v; scanf("%d%d", &u, &v);
		u--; v--;
		u = findset(u), v = findset(v);
		if(u == v) { printf("-1\n"); continue; }
		if(sz[u] > sz[v] || (sz[u] == sz[v] && u > v)) swap(u, v);
		if(ans.count(MP(u, v))) { printf("%.10f\n", (double)ans[MP(u, v)] / sz[u] / sz[v]); continue; }
		int maxd = max(d[u], d[v]);
		int p = sz[v] - 1;
		LL t = 0;
		for(int x : dis[u]) {
			while(p >= 0 && x + dis[v][p] + 1 > maxd) p--;
			t += (LL)maxd * (p+1) + (LL)(x+1)*(sz[v]-1-p) + pre[v].back()-pre[v][p+1];
		}
		ans[MP(u, v)] = t;
		printf("%.10f\n", (double)t / sz[u] / sz[v]);
	}

	return 0;
}


