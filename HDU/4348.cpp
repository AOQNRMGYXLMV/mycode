#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 100000 + 10;
typedef long long LL;

struct Node
{
	int lch, rch, add;
};

int sz;
Node T[maxn << 5];

int n, m, root[maxn];
LL S[maxn];
char op[5];

int update(int pre, int L, int R, int qL, int qR, int v) {
	int rt = ++sz;
	T[rt].lch = T[pre].lch;
	T[rt].rch = T[pre].rch;
	T[rt].add = T[pre].add;
	if(qL <= L && R <= qR) { T[rt].add += v; return rt; }
	int M = (L + R) / 2;
	if(qL <= M) T[rt].lch = update(T[pre].lch, L, M, qL, qR, v);
	if(qR > M) T[rt].rch = update(T[pre].rch, M+1, R, qL, qR, v);
	return rt;
}

LL query(int rt, int L, int R, int qL, int qR) {
	LL ans = (LL)(R-L+1) * T[rt].add;
	if(qL <= L && R <= qR) return ans;
	int M = (L + R) / 2;
	if(qL <= M) ans += query(T[rt].lch, L, M, qL, qR);
	if(qR > M) ans += query(T[rt].rch, M+1, R, qL, qR);
	return ans;
}

int main()
{
	freopen("in.txt", "r", stdin);
	bool flag = false;
	while(scanf("%d%d", &n, &m) == 2) {
		if(flag) puts(""); flag = true;
		for(int i = 1; i <= n; i++) {
			scanf("%lld", S + i);
			S[i] += S[i -1];
		}
		int time = 0;
		while(m--) {
			scanf("%s", op);
			int l, r, d; scanf("%d", &l);
			if(op[0] == 'C') {
				scanf("%d%d", &r, &d);
				time++;
				root[time] = update(root[time-1], 1, n, l, r, d);
			} else if(op[0] == 'Q') {
				scanf("%d", &r);
				LL ans = S[r] - S[l - 1];
				ans += query(root[time], 1, n, l, r);
				printf("%lld\n", ans);
			} else if(op[0] == 'H') {
				scanf("%d%d", &r, &d);
				LL ans = S[r] - S[l - 1];
				ans += query(root[d], 1, n, l, r);
				printf("%lld\n", ans);
			} else {
				time = l;
			}
		}
	}

	return 0;
}
