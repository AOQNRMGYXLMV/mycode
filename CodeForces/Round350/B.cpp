#include <cstdio>

typedef long long LL;

const int maxn = 100000 + 10;

int a[maxn];

int main()
{
	int n; LL k;
	scanf("%d%lld", &n, &k);
	for(int i = 1; i <= n; i++) scanf("%d", a + i);

	LL x;
	for(x = 1; x * (x + 1) / 2 < k; x++);
	printf("%d\n", a[k - x * (x - 1) / 2]);

	return 0;
}
