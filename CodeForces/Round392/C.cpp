#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long LL;

int main()
{
	int n, m, x, y;
	LL k;
	scanf("%d%d%lld%d%d", &n, &m, &k, &x, &y);

	if(n == 1) {
		LL t = k / m;
		int r = k % m;
		LL Min = t, Max = t, ans = t;
		if(r) Max++;
		if(r >= y) ans++;
		printf("%lld %lld %lld\n", Max, Min, ans);
		return 0;
	}

	if(n == 2) {
		LL t = k / 2 / m;
		int r = k % (m * 2);
		LL Min = t, Max = t, ans = t;
		if(r) Max++;
		if(r >= (x - 1) * m + y) ans++;
		printf("%lld %lld %lld\n", Max, Min, ans);
		return 0;
	}

	int cnt = (n - 1) * 2 * m;
	LL t = k / cnt, r = k % cnt;
	LL min1 = t, max1 = t, min2 = t * 2, max2 = t * 2;
	if(r > n * m) {
		min1 = max1 = t + 1;
		min2++; max2 += 2;
	} else if(r > (n - 1) * m) {
		max1++; min2++; max2++;
		if(r == n * m) min1++;
	} else if(r > m) {
		max1++; max2++;
	} else if(r > 0) max1++;

	printf("%lld %lld ", max(max1, max2), min(min1, min2));

	k -= (x - 1) * m + y - 1;
	if(k <= 0) { printf("0\n"); return 0; }
	
	LL ans = k / cnt;
	if(x != 1 && x != n) ans <<= 1;
	r = k % cnt;
	if(r) ans++;
	if(x != 1 && x != n) {
		if(r > (n - x) * 2 * m) ans++;
	}

	printf("%lld\n", ans);

	return 0;
}
