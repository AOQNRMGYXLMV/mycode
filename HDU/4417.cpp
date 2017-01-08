#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 100000 + 10;

struct Node
{
	int lch, rch, sum;
};

int sz, root[maxn];
Node T[maxn << 5];

int n, m;
int a[maxn], b[maxn * 2], tot;
int l[maxn], r[maxn], h[maxn];

int newnode() {
	++sz;
	T[sz].lch = T[sz].rch = T[sz].sum = 0;
	return sz;
}

int insert(int pre, int L, int R, int pos) {
	int rt = newnode();
	T[rt].lch = T[pre].lch;
	T[rt].rch = T[pre].rch;
	T[rt].sum = T[pre].sum + 1;
	if(L < R) {
		int M = (L + R) / 2;
		if(pos <= M) T[rt].lch = insert(T[pre].lch, L, M, pos);
		else T[rt].rch = insert(T[pre].rch, M+1, R, pos);
	}
	return rt;
}

int query(int s, int t, int L, int R, int v) {
	if(v >= R) return T[t].sum - T[s].sum;
	int M = (L + R) / 2;
	if(v <= M) return query(T[s].lch, T[t].lch, L, M, v);
	return T[T[t].lch].sum - T[T[s].lch].sum + query(T[s].rch, T[t].rch, M+1, R, v);
}

int main()
{
	int _; scanf("%d", &_);
	for(int kase = 1; kase <= _; kase++) {
		printf("Case %d:\n", kase);
		scanf("%d%d", &n, &m);
		for(int i = 1; i <= n; i++) {
			scanf("%d", a + i);
			b[i - 1] = a[i];
		}
		tot = n;
		for(int i = 1; i <= m; i++) {
			scanf("%d%d%d", l + i, r + i, h + i);
			b[tot++] = h[i];
		}
		sort(b, b + tot);
		tot = unique(b, b + tot) - b;
		for(int i = 1; i <= n; i++)
			a[i] = lower_bound(b, b + tot, a[i]) - b + 1;
		for(int i = 1; i <= m; i++)
			h[i] = lower_bound(b, b + tot, h[i]) - b + 1;

		sz = 0;
		for(int i = 1; i <= n; i++)
			root[i] = insert(root[i - 1], 1, tot, a[i]);
		for(int i = 1; i <= m; i++) {
			r[i]++;
			printf("%d\n", query(root[l[i]], root[r[i]], 1, tot, h[i]));
		}
	}

	return 0;
}
