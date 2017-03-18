#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long LL;

struct Segment
{
	int l, r;
	void read() { scanf("%d%d", &l, &r); }
	bool operator < (const Segment& t) const {
		return r < t.r || (r == t.r && l < t.l);
	}
};

bool cmp(const Segment& A, const Segment& B) {
	return A.l < B.l || (A.l == B.l && A.r < B.r);
}

const int maxn = 200000 + 10;

Segment a[2][maxn];

void update(LL& a, LL b) {
	if(b > a) a = b;
}

int main()
{
	int n, m; scanf("%d", &n);
	for(int i = 0; i < n; i++) a[0][i].read();
	scanf("%d", &m);
	for(int i = 0; i < m; i++) a[1][i].read();

	sort(a[0], a[0] + n);
	sort(a[1], a[1] + m, cmp);
	LL ans = 0;
	update(ans, (LL)a[1][m-1].l - a[0][0].r);

	sort(a[0], a[0] + n, cmp);
	sort(a[1], a[1] + m);
	update(ans, (LL)a[0][n-1].l - a[1][0].r);

	printf("%lld\n", ans);

	return 0;
}
