#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;

const int maxn = 100000 + 10;
typedef long long LL;

struct Tower
{
	int a, b;
	LL h;
	void read() { scanf("%d%d%lld", &a, &b, &h); }
	bool operator < (const Tower& t) const {
		return b < t.b || (b == t.b && a < t.a);
	}
};

Tower t[maxn];

int x[maxn << 1];
long long maxv[maxn << 3];

void update(int o, int L, int R, int p, LL v) {
	if(L == R) { maxv[o] = max(maxv[o], v); return; }
	int M = (L + R) / 2;
	if(p <= M) update(o<<1, L, M, p, v);
	else update(o<<1|1, M+1, R, p, v);
	maxv[o] = max(maxv[o<<1], maxv[o<<1|1]);
}

LL query(int o, int L, int R, int qL, int qR) {
	if(L > R) return 0;
	if(qL <= L && R <= qR) return maxv[o];
	int M = (L + R) / 2;
	LL ans = 0;
	if(qL <= M) ans = max(ans, query(o<<1, L, M, qL, qR));
	if(qR > M) ans = max(ans, query(o<<1|1, M+1, R, qL, qR));
	return ans;
}

int main()
{
	int n; scanf("%d", &n);

	int tot = 0;
	for(int i = 0; i < n; i++) {
		t[i].read();
		x[tot++] = t[i].a;
		x[tot++] = t[i].b;
	}
	sort(t, t + n);
	reverse(t, t + n);
	sort(x, x + tot);
	tot = unique(x, x + tot) - x;
	for(int i = 0; i < n; i++) {
		t[i].a = lower_bound(x, x + tot, t[i].a) - x + 1;
		t[i].b = lower_bound(x, x + tot, t[i].b) - x + 1;
	}

	long long ans = 0;
	for(int i = 0; i < n; i++) {
		LL d = query(1, 1, tot, 1, t[i].b - 1) + t[i].h;
		if(d > ans) ans = d;
		update(1, 1, tot, t[i].a, d);
	}

	printf("%lld\n", ans);

	return 0;
}
