#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <stack>
#include <map>
using std::pair;
using std::vector;
using std::stack;
const int maxn = 200000 + 10;
const int MOD = 1000000007;
typedef pair<int, int> Edge;
typedef long long LL;

LL mul(LL a, LL b) { return a * b % MOD; }

void add(LL& a, LL b) { a += b; if(a >= MOD) a -= MOD; }

LL sub(LL a, LL b) { b = MOD - b; a += b; if(a >= MOD) a -= MOD; return a; }

LL pow_mod(LL a, int p) {
	LL ans = 1;
	while(p) {
		if(p & 1) ans = mul(ans, a);
		a = mul(a, a);
		p >>= 1;
	}
	return ans;
}

LL div(LL a, LL b) { return mul(a, pow_mod(b, MOD - 2)); }

int n, m, cc_cnt;

int w[maxn * 2];
bool vis[maxn * 2];
vector<int> G[maxn * 2], bcc[maxn], single;

int dfs_clock, bcc_cnt;
int pre[maxn], bccno[maxn];
stack<Edge> S;

int dfs(int u, int fa) {
	int lowu = pre[u] = ++dfs_clock;
	int child = 0;
	for(int v : G[u]) {
		Edge e(u, v);
		if(!pre[v]) {
			S.push(e);
			child++;
			int lowv = dfs(v, u);
			lowu = std::min(lowu, lowv);
			if(lowv >= pre[u]) {
				bcc_cnt++; bcc[bcc_cnt].clear();
				for(;;) {
					Edge t = S.top(); S.pop();
					int &x = t.first, &y = t.second;
					if(bccno[x] != bcc_cnt) { bcc[bcc_cnt].push_back(x); bccno[x] = bcc_cnt; }
					if(bccno[y] != bcc_cnt) { bcc[bcc_cnt].push_back(y); bccno[y] = bcc_cnt; }
					if(x == u && y == v) break;
				}
			}
		} else if(pre[v] < pre[u] && v != fa) {
			S.push(e);
			lowu = std::min(lowu, pre[v]);
		}
	}
	if(fa < 0 && !child) single.push_back(u);
	return lowu;
}

void find_bcc() {
	memset(pre, 0, sizeof(pre));
	memset(bccno, 0, sizeof(bccno));
	single.clear();
	dfs_clock = bcc_cnt = 0;
	for(int i = 0; i < n; i++) if(!pre[i]) {
		dfs(i, -1);
		cc_cnt++;
	}
}

void rebuild() {
	for(int i = 0; i < n + bcc_cnt; i++) G[i].clear();
	for(int i = 0; i < bcc_cnt; i++) {
		int u = n + i; G[u].clear();
		w[u] = 1;
		for(int v : bcc[i + 1]) {
			G[u].push_back(v);
			G[v].push_back(u);
		}
	}
}

vector<int> root;
LL d[maxn * 2];

void dp(int u) {
	d[u] = w[u];
	vis[u] = true;
	for(int v : G[u]) if(!vis[v]) {
		dp(v);
		d[u] = mul(d[u], d[v]);
	}
}

LL ans[maxn], sum;

void solve(int u, int fa, LL prod) {
	ans[u] = 0;
	for(int v : G[u]) if(v != fa) {
		solve(v, u, prod);
		if(u < n) add(ans[u], d[v]);
	}
	if(u < n) add(ans[u], div(prod, d[u]));
	add(ans[u], sub(sum, prod));
}

int main()
{
	int T; scanf("%d", &T);
	while(T--) {
		scanf("%d%d", &n, &m);
		for(int i = 0; i < n; i++) {
			scanf("%d", w + i);
			G[i].clear();
		}
		while(m--) {
			int u, v; scanf("%d%d", &u, &v);
			u--; v--;
			G[u].push_back(v);
			G[v].push_back(u);
		}
		find_bcc();
		rebuild();
		
		memset(vis, false, sizeof(vis));
		root.clear();
		sum = 0;
		for(int u : single) add(sum, w[u]);
		for(int i = 0; i < bcc_cnt; i++) {
			int r = n + i; if(!vis[r]) {
				root.push_back(r);
				dp(r);
				add(sum, d[r]);
			}
		}

		memset(ans, 0, sizeof(ans));
		for(int r : root) solve(r, -1, d[r]);
		
		LL res = 0;
		for(int u : single)
			ans[u] = sub(sum, w[u]);
		for(int i = 0; i < n; i++) add(res, mul(ans[i], i + 1));
		printf("%lld\n", res);
	}

	return 0;
}
