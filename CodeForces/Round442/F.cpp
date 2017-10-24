#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
#define MP make_pair
#define PB push_back
#define REP(i, a, b) for(int i = a; i < b; i++)
#define PER(i, a, b) for(int i = b - 1; i >= a; i--)

const int maxn = 100000 + 10;
int block;

struct Query {
	int l, r, id;
	Query(int l = 0, int r = 0, int id = 0): l(l), r(r), id(id) {}
	bool operator < (const Query& t) const {
		return (l-1)/block < (t.l-1)/block || ((l-1)/block == (t.l-1)/block && r < t.r);
	}
};

Query q[maxn];

int n, k;
LL a[maxn], cnt[maxn * 3], x[maxn * 3], ans[maxn];
int t[maxn], v[maxn], l[maxn], r[maxn];

int main() {
	scanf("%d%d", &n, &k);
	block = (int)floor(sqrt(n) + 0.5);
	REP(i, 1, n + 1) scanf("%d", t + i);
	REP(i, 1, n + 1) {
		scanf("%I64d", a + i);
		if(t[i] == 2) a[i] = -a[i];
		a[i] += a[i - 1];
	}

	int tot = 1;
	REP(i, 0, n + 1) {
		x[tot++] = a[i];
		x[tot++] = a[i] + k;
		x[tot++] = a[i] - k;
	}
	sort(x, x + tot);
	tot = unique(x, x + tot) - x;
	REP(i, 0, n + 1) {
		v[i] = lower_bound(x, x + tot, a[i]) - x;
		l[i] = lower_bound(x, x + tot, a[i] - k) - x;
		r[i] = lower_bound(x, x + tot, a[i] + k) - x;
	}
	int Q; scanf("%d", &Q);
	REP(i, 0, Q) {
		int a, b; scanf("%d%d", &a, &b); a--;
		q[i] = Query(a, b, i);
	}
	sort(q, q + Q);

	int L = q[0].l, R = q[0].l - 1;
	LL cur = 0;
	REP(i, 0, Q) {
		while(R < q[i].r) { R++; cur += cnt[l[R]]; cnt[v[R]]++; }
		while(R > q[i].r) { cnt[v[R]]--; cur -= cnt[l[R]]; R--; }
		while(L > q[i].l) { L--; cur += cnt[r[L]]; cnt[v[L]]++; }
		while(L < q[i].l) { cnt[v[L]]--; cur -= cnt[r[L]]; L++; }
		ans[q[i].id] = cur;
	}

	REP(i, 0, Q) printf("%I64d\n", ans[i]);

	return 0;
}