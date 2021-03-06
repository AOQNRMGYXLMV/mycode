#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long LL;
const int maxn = 100000 + 10;
const int INF = 0x3f3f3f3f;
const int maxnode = maxn << 5;

struct Event
{
	int pos, sum, type;
	bool operator < (const Event& t) const {
		return pos < t.pos || (pos == t.pos && type < t.type);
	}
};

struct Segment
{
	int l, r, d;
};

Event events[maxn * 2];
Segment a[maxn];
int y[maxn], tot;

int n, m, X;
LL P;

int sz;
int cnt[maxnode], lch[maxnode], rch[maxnode];
LL sum[maxnode];
int root[maxn * 2];

int update(int pre, int L, int R, int pos, LL val, int type) {
	int rt = ++sz;
	lch[rt] = lch[pre];
	rch[rt] = rch[pre];
	cnt[rt] = cnt[pre] + type;
	sum[rt] = sum[pre] + val;
	if(L < R) {
		int M = (L + R) / 2;
		if(pos <= M) lch[rt] = update(lch[pre], L, M, pos, val, type);
		else rch[rt] = update(rch[pre], M+1, R, pos, val, type);
	}
	return rt;
}

LL query(int rt, int L, int R, int k) {
	if(L == R) {
		if(cnt[rt] > k) return sum[rt] / cnt[rt] * k;
		else return sum[rt];
	}
	int M = (L + R) / 2;
	int num = cnt[lch[rt]];
	if(num >= k) return query(lch[rt], L, M, k);
	else return sum[lch[rt]] + query(rch[rt], M+1, R, k - num);
}

int main()
{
	while(scanf("%d%d%d%lld", &n, &m, &X, &P) == 4) {
		for(int i = 0; i < n; i++) {
			scanf("%d%d%d", &a[i].l, &a[i].r, &a[i].d);
			events[i * 2] = (Event){ a[i].l, a[i].d, 1 };
			events[i*2+1] = (Event){ a[i].r + 1, a[i].d, -1 };
			y[i] = a[i].d;
		}
		sort(events, events + n * 2);
		sort(y, y + n);
		tot = unique(y, y + n) - y;

		sz = 0;
		for(int i = 0; i < n * 2; i++) {
			Event& e = events[i];
			int pos = lower_bound(y, y + tot, e.sum) - y + 1;
			root[i + 1] = update(root[i], 1, tot, pos, e.sum * e.type, e.type);
		}

		LL pre = 1;
		while(m--) {
			int x; LL a, b, c;
			scanf("%d%lld%lld%lld", &x, &a, &b, &c);
			int K = (a * pre + b) % c;
			if(!K) { printf("0\n"); pre = 0; continue; }
			Event t;
			t = (Event){ x, 0, 2 };
			int rt = lower_bound(events, events + n * 2, t) - events;
			LL ans;
			if(K >= cnt[root[rt]]) ans = sum[root[rt]];
			else ans = query(root[rt], 1, tot, K);
			if(pre > P) ans <<= 1;
			pre = ans;
			printf("%lld\n", ans);
		}
	}

	return 0;
}
