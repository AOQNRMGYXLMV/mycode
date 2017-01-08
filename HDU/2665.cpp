#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 100000 + 10;

struct Node
{
	int lch, rch, sum;
};

int sz;
Node T[maxn << 5];

int newnode() {
	T[sz].lch = T[sz].rch = T[sz].sum = 0;
	return sz++;
}

int build(int L, int R) {
	int rt = newnode();
	if(L < R) {
		int M = (L + R) / 2;
		T[rt].lch = build(L, M);
		T[rt].rch = build(M+1, R);
	}
	return rt;
}

int update(int pre, int L, int R, int p) {
	int rt = newnode();
	T[rt].lch = T[pre].lch;
	T[rt].rch = T[pre].rch;
	T[rt].sum = T[pre].sum + 1;
	if(L == R) return rt;

	int M = (L + R) / 2;
	if(p <= M) T[rt].lch = update(T[pre].lch, L, M, p);
	else T[rt].rch = update(T[pre].rch, M+1, R, p);
	return rt;
}

int query(int s, int t, int L, int R, int k) {
	if(L == R) return L;
	int cnt = T[T[t].lch].sum - T[T[s].lch].sum;
	int M = (L + R) / 2;
	if(cnt >= k) return query(T[s].lch, T[t].lch, L, M, k);
	else return query(T[s].rch, T[t].rch, M+1, R, k - cnt);
}

int n, m;
int a[maxn], b[maxn], tot, root[maxn];

int main()
{
	int _; scanf("%d", &_);
	while(_--) {
		scanf("%d%d", &n, &m);
		for(int i = 1; i <= n; i++) {
			scanf("%d", a + i);
			b[i] = a[i];
		}

		sort(b + 1, b + 1 + n);
		tot = unique(b + 1, b + 1 + n) - (b + 1);

		sz = 0;
		root[0] = build(1, tot);
		for(int i = 1; i <= n; i++) {
			int id = lower_bound(b + 1, b + 1 + tot, a[i]) - b;
			root[i] = update(root[i - 1], 1, tot, id);
		}
		while(m--) {
			int l, r, k; scanf("%d%d%d", &l, &r, &k);
			int ans = query(root[l-1], root[r], 1, tot, k);
			printf("%d\n", b[ans]);
		}
	}

	return 0;
}
