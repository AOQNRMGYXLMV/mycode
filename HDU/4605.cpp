#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 100000 + 10;
const int maxnode = maxn << 5;

struct Node
{
	int lcnt, rcnt;
	Node(int l = 0, int r = 0): lcnt(l), rcnt(r) {}
	Node operator + (const Node& t) const {
		return Node(lcnt + t.lcnt, rcnt + t.rcnt);
	}
};

int sz;
Node T[maxnode];
int lch[maxnode], rch[maxnode];
int root[maxn];

int update(int pre, int L, int R, int pos, Node t) {
	int rt = ++sz;
	T[rt] = T[pre] + t;
	lch[rt] = lch[pre];
	rch[rt] = rch[pre];
	if(L < R) {
		int M = (L + R) / 2;
		if(pos <= M) lch[rt] = update(lch[pre], L, M, pos, t);
		else rch[rt] = update(rch[pre], M+1, R, pos, t);
	}
	return rt;
}

int n, m, Q;
int a[maxn], b[maxn * 2], tot;
int v[maxn], x[maxn];
int ch[maxn][2];
int dep[maxn];

void dfs(int u) {
	if(!ch[u][0]) return;
	root[ch[u][0]] = update(root[u], 1, tot, a[u], Node(1, 0));
	root[ch[u][1]] = update(root[u], 1, tot, a[u], Node(0, 1));
	dep[ch[u][0]] = dep[ch[u][1]] = dep[u] + 1;
	dfs(ch[u][0]);
	dfs(ch[u][1]);
}

bool queryequal(int rt, int L, int R, int pos) {
	if(L == R) { return T[rt].lcnt + T[rt].rcnt != 0; }
	int M = (L + R) / 2;
	if(pos <= M) return queryequal(lch[rt], L, M, pos);
	else return queryequal(rch[rt], M+1, R, pos);
}

Node queryless(int rt, int L, int R, int pos) {
	if(R <= pos) return T[rt];
	int M = (L + R) / 2;
	if(pos <= M) return queryless(lch[rt], L, M, pos);
	else return T[lch[rt]] + queryless(rch[rt], M+1, R, pos);
}

int main()
{
	int _; scanf("%d", &_);
	while(_--) {
		int n; scanf("%d", &n);
		for(int i = 1; i <= n; i++) {
			scanf("%d", a + i);
			b[i - 1] = a[i];
		}
		scanf("%d", &m);
		memset(ch, 0, sizeof(ch));
		while(m--) {
			int u; scanf("%d", &u);
			scanf("%d%d", &ch[u][0], &ch[u][1]);
		}
		scanf("%d", &Q);
		tot = n;
		for(int i = 1; i <= Q; i++) {
			scanf("%d%d", v + i, x + i);
			b[tot++] = x[i];
		}

		sort(b, b + tot);
		tot = unique(b, b + tot) - b;
		for(int i = 1; i <= n; i++)
			a[i] = lower_bound(b, b + tot, a[i]) - b + 1;
		for(int i = 1; i <= Q; i++)
			x[i] = lower_bound(b, b + tot, x[i]) - b + 1;

		sz = 0;
		dfs(1);

		for(int i = 1; i <= Q; i++) {
			if(queryequal(root[v[i]], 1, tot, x[i])) {
				printf("0\n"); continue;
			}
			Node ans;
			if(x[i] > 1) ans = queryless(root[v[i]], 1, tot, x[i] - 1);
			int sons = dep[v[i]];
			int ans2 = sons * 3;
			ans2 -= (sons - ans.lcnt - ans.rcnt) * 2;
			int ans7 = ans.rcnt;
			printf("%d %d\n", ans7, ans2);
		}
	}

	return 0;
}
