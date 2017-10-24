#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
#define MP make_pair
#define PB push_back
#define REP(i, a, b) for(int i = a; i < b; i++)
#define PER(i, a, b) for(int i = b - 1; i >= a; i--)

const int maxn = 200000 + 10;

int n;
vector<int> G[maxn];

int a[maxn] ,l[maxn], r[maxn], p[maxn];
int sum[maxn << 2];
bool tag[maxn << 2];

int dfs_clock;
void dfs(int u = 1) {
	l[u] = ++dfs_clock;
	p[l[u]] = u;
	for(int v : G[u]) {
		dfs(v);
	}
	r[u] = dfs_clock;
}

char cmd[10];

void build(int o = 1, int L = 1, int R = n) {
	if(L == R) { sum[o] = a[p[L]]; return; }
	int M = (L + R ) / 2;
	build(o<<1, L, M);
	build(o<<1|1, M+1, R);
	sum[o] = sum[o<<1] + sum[o<<1|1];
}

void pushdown(int o, int L, int R) {
	if(tag[o]) {
		tag[o] = false;
		int M = (L + R) / 2;
		tag[o<<1] ^= 1;
		sum[o<<1] = M-L+1 - sum[o<<1];
		tag[o<<1|1] ^= 1;
		sum[o<<1|1] = R-M - sum[o<<1|1];
	}
}

int qL, qR;
void update(int o = 1, int L = 1, int R = n) {
	if(qL <= L && R <= qR) { tag[o] ^= 1; sum[o] = R-L+1-sum[o]; return; }
	pushdown(o, L, R);
	int M = (L + R) / 2;
	if(qL <= M) update(o<<1, L, M);
	if(qR > M) update(o<<1|1, M+1, R);
	sum[o] = sum[o<<1] + sum[o<<1|1];
}

int query(int o = 1, int L = 1, int R = n, int cnt = 0) {
	if(qL <= L && R <= qR) { return (cnt & 1) ? R-L+1-sum[o] : sum[o]; }
	pushdown(o, L, R);
	int M = (L + R) / 2;
	int ans = 0;
	if(qL <= M) ans += query(o<<1, L, M, cnt ^ tag[o]);
	if(qR > M) ans += query(o<<1|1, M+1, R, cnt ^ tag[o]);
	return ans;
}

int main() {
	scanf("%d", &n);
	REP(i, 2, n + 1) {
		int p; scanf("%d", &p);
		G[p].PB(i);
	}
	REP(i, 1, n + 1) scanf("%d", a + i);
	dfs();
	build();
	int q; scanf("%d", &q);
	while(q--) {
		int x;
		scanf("%s%d", cmd, &x);
		qL = l[x], qR = r[x];
		if(cmd[0] == 'g') {
			printf("%d\n", query());
		} else {
			update();
		}
	}

	return 0;
}