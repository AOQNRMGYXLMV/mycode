#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <iostream>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
#define PB push_back
#define PII pair<int, int>
#define REP(i, a, b) for(int i = a; i < b; i++)
#define PER(i, a, b) for(int i = b - 1; i >= a; i--)
#define ALL(x) x.begin(), x.end()

template <class TH> void _dbg(const char *sdbg, TH h){cerr << sdbg << "=" << h << "\n";}
template <class TH, class ...TA> void _dbg(const char *sdbg, TH h, TA... a){
			while (*sdbg != ',') cerr << *sdbg++; cerr << "=" << h << ","; _dbg(sdbg + 1, a...);
}
#define eput(...) _dbg(#__VA_ARGS__, __VA_ARGS__)

const int maxn = 100000 + 10;
const int maxnode = maxn * 40;
const int INF = 0x3f3f3f3f;

int n, r;
int tot, root[maxn];
int lch[maxnode], rch[maxnode], minv[maxnode];
int a[maxn];

int maxd;
vector<int> G[maxn], d[maxn];
int dfs_time;
int in[maxn], out[maxn], dep[maxn], pos[maxn];

void update(int& rt, int pre, int L, int R, int p, int v) {
	rt = ++tot;
	if(L == R) { minv[rt] = v; return; }
	int M = (L + R) / 2;
	if(p <= M) { rch[rt] = rch[pre]; update(lch[rt], lch[pre], L, M, p, v); }
	else { lch[rt] = lch[pre]; update(rch[rt], rch[pre], M+1, R, p, v); }
	minv[rt] = min(minv[lch[rt]], minv[rch[rt]]);
}

int qL, qR;
int query(int rt, int L, int R) {
	if(qL <= L && R <= qR) return minv[rt];
	int ans = INF;
	int M = (L + R) / 2;
	if(qL <= M) ans = min(ans, query(lch[rt], L, M));
	if(qR > M) ans = min(ans, query(rch[rt], M+1, R));
	return ans;
}

void dfs(int u, int p = 0) {
	in[u] = ++dfs_time;
	dep[u] = dep[p] + 1;
	d[dep[u]].PB(u);
	maxd = max(maxd, dep[u]);
	for(int v : G[u]) if(v != p)
		dfs(v, u);
	out[u] = dfs_time;
}

int main() {
	scanf("%d%d", &n, &r);
	REP(i, 1, n + 1) scanf("%d", a + i);
	REP(i, 1, n) {
		int u, v; scanf("%d%d", &u, &v);
		G[u].PB(v);
		G[v].PB(u);
	}

	dfs(r);
	minv[0] = INF;
	int cur = 0;
	REP(i, 1, maxd + 1) {
		for(int u : d[i]) {
			cur++;
			update(root[cur], root[cur-1], 1, n, in[u], a[u]);
			pos[i] = cur;
		}
	}

	int m; scanf("%d", &m);
	int last = 0;
	while(m--) {
		int p, q; scanf("%d%d", &p, &q);
		int x = ((p + last) % n) + 1;
		int k = (q + last) % n;
		int rt = root[pos[min(maxd, dep[x]+k)]];
		qL = in[x], qR = out[x];
		last = query(rt, 1, n);
		printf("%d\n", last);
	}

	return 0;
}

