#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 50000 + 10;
const int maxq = 10000 + 10;

struct Query
{
	int a, b, c;
	bool flag;
};

char op[10];

int n, m;
Query q[maxq];

int a[maxn], tot, b[maxn + maxq];
int root[maxn * 2];
int p[2], s[2][100];

struct Node
{
	int lch, rch, sum;
};

int sz;
Node T[maxn * 40];

int newnode() {
	sz++;
	T[sz].lch = T[sz].rch = T[sz].sum = 0;
	return sz;
}

int build(int pre, int L, int R, int pos) {
	int rt = newnode();
	T[rt].lch = T[pre].lch;
	T[rt].rch = T[pre].rch;
	T[rt].sum = T[pre].sum + 1;
	if(L < R) {
		int M = (L + R) / 2;
		if(pos <= M) T[rt].lch = build(T[pre].lch, L, M, pos);
		else T[rt].rch = build(T[pre].rch, M+1, R, pos);
	}
	return rt;
}

int lowbit(int x) { return x & (-x); }

void insert(int& rt, int L, int R, int pos, int val) {
	if(!rt) rt = newnode();
	T[rt].sum += val;
	if(L == R) return;
	int M = (L + R) / 2;
	if(pos <= M) insert(T[rt].lch, L, M, pos, val);
	else insert(T[rt].rch, M+1, R, pos, val);
}

int query(int L, int R, int k) {
	if(L == R) return L;
	int sum = 0;
	for(int i = 0; i < p[0]; i++)
		sum += T[T[s[0][i]].lch].sum;
	for(int i = 0; i < p[1]; i++)
		sum -= T[T[s[1][i]].lch].sum;
	int M = (L + R) / 2;
	if(sum >= k) {
		for(int i = 0; i < 2; i++)
			for(int j = 0; j < p[i]; j++)
				s[i][j] = T[s[i][j]].lch;
		return query(L, M, k);
	} else {
		for(int i = 0; i < 2; i++)
			for(int j = 0; j < p[i]; j++)
				s[i][j] = T[s[i][j]].rch;
		return query(M+1, R, k - sum);
	}

}

int main()
{
	freopen("in.txt", "r", stdin);
	int _; scanf("%d", &_);
	while(_--) {
		scanf("%d%d", &n, &m);
		for(int i = 1; i <= n; i++) {
			scanf("%d", a + i);
			b[i] = a[i];
		}
		tot = n + 1;
		for(int i = 1; i <= m; i++) {
			scanf("%s%d%d", op, &q[i].a, &q[i].b);
			if(op[0] == 'Q') {
				q[i].flag = true;
				scanf("%d", &q[i].c);
			} else {
				q[i].flag = false;
				b[tot++] = q[i].b;
			}
		}

		sort(b + 1, b + tot);
		tot = unique(b + 1, b + tot) - (b + 1);
		for(int i = 1; i <= n; i++)
			a[i] = lower_bound(b + 1, b + tot + 1, a[i]) - b;
		sz = 0;
		memset(root, 0, sizeof(root));
		for(int i = 1; i <= n; i++)
			root[n + i] = build(root[n + i - 1], 1, tot, a[i]);

		for(int i = 1; i <= m; i++) {
			if(q[i].flag) {
				p[0] = p[1] = 1;
				s[0][0] = root[q[i].b + n];
				if(q[i].a == 1) s[1][0] = 0;
				else s[1][0] = root[q[i].a - 1 + n];
				for(int j = q[i].b; j; j -= lowbit(j))
					s[0][p[0]++] = root[j];
				for(int j = q[i].a-1; j; j -= lowbit(j))
					s[1][p[1]++] = root[j];
				printf("%d\n", b[query(1, tot, q[i].c)]);
			} else {
				for(int j = q[i].a; j <= n; j++)
					insert(root[j], 1, tot, a[q[i].a], -1);
				a[q[i].a] = lower_bound(b + 1, b + 1 + tot, q[i].b) - b;
				for(int j = q[i].a; j <= n; j++)
					insert(root[j], 1, tot, a[q[i].a], 1);
			}
		}
	}

	return 0;
}
