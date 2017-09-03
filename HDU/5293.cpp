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

int n, m;
vector<int> G[maxn], Q[maxn];
int u[maxn], v[maxn], w[maxn];
int l[maxn], r[maxn], dfs_clock;
int dp[maxn], sum[maxn];

int dep[maxn];
int anc[maxn][20];

void dfs(int u, int fa) {
	l[u] = ++dfs_clock;
	anc[u][0] = fa;
	for(int i = 0; anc[u][i]; i++)
		anc[u][i+1] = anc[anc[u][i]][i];
	dep[u] = dep[fa] + 1;
	for(int v : G[u]) if(v != fa) {
		dfs(v, u);
	}
	r[u] = ++dfs_clock;
}

int LCA(int u, int v) {
	if(dep[u] < dep[v]) swap(u, v);
	PER(i, 0, 20)
		if(dep[anc[u][i]] >= dep[v]) u = anc[u][i];
	if(u == v) return u;
	PER(i, 0, 20) if(anc[u][i] != anc[v][i])
		u = anc[u][i], v = anc[v][i];
	return anc[u][0];
}

int C[maxn << 1];
#define lowbit(x) (x&(-x))
void add(int x, int v) {
	while(x <= n * 2) {
		C[x] += v;
		x += lowbit(x);
	}
}
int query(int x) {
	int ans = 0;
	while(x) {
		ans += C[x];
		x -= lowbit(x);
	}
	return ans;
}

void init() {
	REP(i, 1, n + 1) G[i].clear(), Q[i].clear();
	memset(anc, 0, sizeof(anc));
	dfs_clock = 0;
	memset(C, 0, sizeof(C));
	memset(dp, 0, sizeof(dp));
	memset(sum, 0, sizeof(sum));
}

void upd(int& a, int b) { if(a < b) a = b; }

void solve(int x) {
	for(int y : G[x]) if(y != anc[x][0]) {
		solve(y);
		sum[x] += dp[y];
	}
	dp[x] = sum[x];
	for(int q : Q[x]) {
		upd(dp[x], sum[x] + query(l[u[q]]) + query(l[v[q]]) + w[q]);
	}
	add(l[x], sum[x] - dp[x]);
	add(r[x], dp[x] - sum[x]);
}

int main() {
	int T; scanf("%d", &T);
	while(T--) {
		scanf("%d%d", &n, &m);
		init();
		REP(i, 1, n) {
			int u, v; scanf("%d%d", &u, &v);
			G[u].PB(v);
			G[v].PB(u);
		}
		dfs(1, 0);
		REP(i, 0, m) {
			scanf("%d%d%d", u + i, v + i, w + i);
			int lca = LCA(u[i], v[i]);
			Q[lca].PB(i);
		}
		solve(1);
		printf("%d\n", dp[1]);
	}

	return 0;
}


