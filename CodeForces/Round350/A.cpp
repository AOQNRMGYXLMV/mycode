#include <cstdio>
#include <algorithm>

int main()
{
	int n; scanf("%d", &n);
	int d = n / 7, r = n % 7;
	printf("%d %d\n", d * 2 + (r == 6), d * 2 + std::min(r, 2));

	return 0;
}
