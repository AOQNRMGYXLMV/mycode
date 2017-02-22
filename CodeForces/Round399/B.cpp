#include <cstdio>

typedef long long LL;

LL len(LL x) {
	if(x <= 1) return 1;
	return len(x >> 1) << 1 | 1;
}

LL solve(LL x, LL n, LL l) {
	if(!n || !x) return 0;
	if(x == 1) return 1;
	if(n <= l) return solve(x >> 1, n, l >> 1);
	if(n == l + 1) return (x >> 1) + (x & 1);
	return (x >> 1) + (x & 1) + solve(x >> 1, n - l - 1, l >> 1);
}

LL solve(LL x, LL n) { return solve(x, n, len(x >> 1)); }

int main()
{
	LL n, l, r;
	scanf("%lld%lld%lld", &n, &l, &r);
	printf("%lld\n", solve(n, r) - solve(n, l - 1));

	return 0;
}
