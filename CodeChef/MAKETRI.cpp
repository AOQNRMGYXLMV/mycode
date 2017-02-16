#include <cstdio>
#include <cstring>
#include <algorithm>

typedef long long LL;

struct Segment
{
	LL l, r;

	bool operator < (const Segment& t) {
		return l < t.l || (l == t.l && r < t.r);
	}
};

const int maxn = 1000000 + 10;

LL a[maxn];

Segment s[maxn];

int main()
{
	int n;
	LL L, R;
	scanf("%d%lld%lld", &n, &L, &R);

	for(int i = 0; i < n; i++) scanf("%lld", a + i);
	std::sort(a, a + n);
	int tot = 0;
	for(int i = 1; i < n; i++) {
		LL left = std::max(L, a[i] - a[i-1] + 1);
		LL right = std::min(R, a[i] + a[i-1] - 1);
		if(left <= right) s[tot++] = { left, right };
	}
	std::sort(s, s + tot);
	
	LL ans = 0, left = 0, right = -1;
	for(int i = 0; i < tot; i++) {
		if(s[i].l <= right) right = std::max(right, s[i].r);
		else {
			ans += right - left + 1;
			left = s[i].l;
			right = s[i].r;
		}
	}
	ans += right - left + 1;

	printf("%lld\n", ans);

	return 0;
}
