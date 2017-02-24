#include <cstdio>

typedef long long LL;

LL phi(LL n) {
	LL ans = n;
	for(LL i = 2; i * i <= n; i++) if(n % i == 0) {
		ans /= i;
		ans *= i - 1;
		while(n % i == 0) n /= i;
	}
	if(n > 1) { ans /= n; ans *= n - 1; }
	return ans;
}

const LL MOD = 1000000007;

int main()
{
	LL n, k; scanf("%lld%lld", &n, &k);
	k = (k + 1) >> 1;
	LL ans = phi(n);
	for(LL i = 1; i < k; i++) {
		if(ans == 1) break;
		ans = phi(ans);
	}
	printf("%lld\n", ans % MOD);

	return 0;
}
