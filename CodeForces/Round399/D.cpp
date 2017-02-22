#include <cstdio>
#include <algorithm>
using std::min;

double d[1005];
int ans[1005];

const double eps = 1e-7;

int main()
{
	int k, q, p = 1;
	scanf("%d%d", &k, &q);
	d[0] = 1;
	for(int i = 1; p <= 1000; i++) {
		for(int j = min(k, i); j; j--)
			d[j] = (d[j] * j + d[j - 1] * (k - j + 1)) / k;
		while(p <= 1000 && 2000 * d[k] >= (p - eps)) {
			ans[p] = i;
			p++;
		}
		d[0] = 0;
	}

	while(q--) {
		scanf("%d", &p);
		printf("%d\n", ans[p]);
	}

	return 0;
}
