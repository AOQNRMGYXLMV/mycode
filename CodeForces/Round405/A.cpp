#include <cstdio>



int main()
{
	long long a, b; scanf("%lld%lld", &a, &b);

	int ans = 0;
	while(a <= b) {
		a *= 3;
		b <<= 1;
		ans++;
	}

	printf("%d\n", ans);

	return 0;
}
