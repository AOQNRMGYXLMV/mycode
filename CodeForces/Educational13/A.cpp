#include <cstdio>
#include <cstring>

int main()
{
	int n, k; scanf("%d%d", &n, &k);
	n -= (n % k);
	n += k;
	printf("%d\n", n);

	return 0;
}
