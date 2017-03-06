#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long LL;

int n, m, k;
int r[10], c[10];

int main()
{
	scanf("%d%d%d", &n, &m, &k);

	LL ans = 0;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			ans += (LL)(n + 1 - i) * (m + 1 - j);
	for(int i = 0; i < k; i++)
		scanf("%d%d", r + i, c + i);
	for(int S = 1; S < (1 << k); S++) {
		int lft = m + 1, top = n + 1;
		int down = 0, rgh = 0;
		int cnt = 0;
		for(int i = 0; i < k; i++) if((S >> i) & 1) {
			cnt++;
			lft = min(lft, c[i]);
			top = min(top, r[i]);
			rgh = max(rgh, c[i]);
			down = max(down, r[i]);
		}
		int sign = (cnt & 1) ? -1 : 1;
		ans += (LL)sign * lft * (m + 1 - rgh) * top * (n + 1 - down);
	}

	printf("%lld\n", ans);

	return 0;
}
