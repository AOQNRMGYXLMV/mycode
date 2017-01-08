#include <cstdio>

typedef long long LL;

LL calc(LL x) {
	LL t = x * (x + 1) / 2;
	return t * t;
}

int main()
{
	int T; scanf("%d", &T);
	for(int kase = 1; kase <= T; kase++) {
		LL l, r; scanf("%lld%lld", &l, &r);
		printf("Case #%d: %lld\n", kase, calc(r) - calc(l - 1));
	}

	return 0;
}
