#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long LL;
const int maxn = 50000 + 10;
const int maxn2 = maxn * 2;
const int maxnode = maxn2 * 4;
int W, H, n, m;

struct Rect
{
	int x1, y1, x2, y2;

	void read() { scanf("%d%d%d%d", &x1, &y1, &x2, &y2); }
};

Rect rects[maxn];

struct Segment
{
	int l, r, y, f;
	Segment() {}
	Segment(int l, int r, int y, int f): l(l), r(r), y(y), f(f) {}
	bool operator < (const Segment& t) const {
		return y < t.y;
	}
};

Segment seg[maxn2];

int tot, lft[maxn], rgh[maxn], x[maxn2];
LL ans, area;
int add[maxnode], len[maxnode];

void pushup(int o, int L, int R) {
	if(add[o]) len[o] = x[R] - x[L - 1];
	else if(L == R) len[o] = 0;
	else len[o] = len[o<<1] + len[o<<1|1];
}

void update(int o, int L, int R, int qL, int qR, int v) {
	if(qL <= L && R <= qR) {
		add[o] += v;
		if(add[o]) len[o] = x[R] - x[L - 1];
		else if(L == R) len[o] = 0;
		else len[o] = len[o<<1] + len[o<<1|1];
		return;
	}
	int M = (L + R) / 2;
	if(qL <= M) update(o<<1, L, M, qL, qR, v);
	if(qR > M) update(o<<1|1, M+1, R, qL, qR, v);
	if(!add[o]) len[o] = len[o<<1] + len[o<<1|1];
}

void solve() {
	memset(add, 0, sizeof(add));
	memset(len, 0, sizeof(len));

	sort(seg, seg + n * 2);

	area = 0;
	for(int i = 0, j; i < n * 2; i = j) {
		if(i > 0) area += (LL)(seg[i].y - seg[i-1].y) * len[1];
		for(j = i; j < n * 2 && seg[i].y == seg[j].y; j++)
			update(1, 1, tot - 1, seg[j].l + 1, seg[j].r, seg[j].f);
	}
}

int main()
{
	while(scanf("%d%d%d%d", &W, &H, &n, &m) == 4) {
		for(int i = 0; i < n; i++) rects[i].read();
		ans = 0;
		if(W >= m) {
			int Rmax = W - m + 1;
			tot = 0;
			for(int i = 0; i < n; i++) {
				lft[i] = max(rects[i].x1 - m, 0);
				rgh[i] = min(rects[i].x2, Rmax);
				x[tot++] = lft[i];
				x[tot++] = rgh[i];
			}

			sort(x, x + tot);
			tot = unique(x, x + tot) - x;
			for(int i = 0; i < n; i++) {
				int l = lower_bound(x, x + tot, lft[i]) - x;
				int r = lower_bound(x, x + tot, rgh[i]) - x;
				seg[i * 2] = Segment(l, r, rects[i].y1 - 1, 1);
				seg[i*2+1] = Segment(l, r, rects[i].y2, -1);
			}
			solve();
			ans += (LL)(W - m + 1) * H - area;
		}
		if(H >= m && m > 1) {
			int Rmax = H - m + 1;
			tot = 0;
			for(int i = 0; i < n; i++) {
				lft[i] = max(rects[i].y1 - m ,0);
				rgh[i] = min(rects[i].y2, Rmax);
				x[tot++] = lft[i];
				x[tot++] = rgh[i];
			}

			sort(x, x + tot);
			tot = unique(x, x + tot) - x;
			for(int i = 0; i < n; i++) {
				int l = lower_bound(x, x + tot, lft[i]) - x;
				int r = lower_bound(x, x + tot, rgh[i]) - x;
				seg[i * 2] = Segment(l, r, rects[i].x1 - 1, 1);
				seg[i*2+1] = Segment(l, r, rects[i].x2, -1);
			}
			solve();
			ans += (LL)(H - m + 1) * W - area;
		}
		printf("%lld\n", ans);
	}

	return 0;
}
