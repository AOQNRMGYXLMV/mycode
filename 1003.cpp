#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

typedef long long LL;

LL n, m, k;

const LL MOD = 1000000007;

LL mul_mod(LL a, LL b) { return a * b % MOD; }

LL pow_mod(LL a, LL p) {
	LL ans = 1;
	while(p) {
		if(p & 1) ans = mul_mod(ans, a);
		a = mul_mod(a, a);
		p >>= 1;
	}
	return ans;
}

const int maxn = 1000000 + 10;

LL fac[maxn], inv_fac[maxn];

LL inverse(LL x) { return pow_mod(x, MOD - 2); }

LL C(LL n, LL k) {
	return mul_mod(mul_mod(fac[n], inv_fac[k]), inv_fac[n - k]);
}

int main()
{
	fac[0] = 1;
	for(int i = 1; i < maxn; i++) fac[i] = mul_mod(fac[i - 1], i);
	inv_fac[maxn - 1] = pow_mod(fac[maxn - 1], MOD - 2);
	for(int i = maxn - 2; i >= 0; i--) inv_fac[i] = mul_mod(inv_fac[i + 1], i + 1);

	int T; scanf("%d", &T);
	while(T--) {
		scanf("%lld%lld%lld", &m, &n, &k);
		if(n == 1) { printf("%d\n", m); continue; }
		if(m < n * (k + 1)) { printf("0\n"); continue; }
		LL ans = mul_mod(m, C(m - n * k - 1, n - 1));
		ans = mul_mod(ans, inverse(n));
		printf("%lld\n", ans);
	}

	return 0;
}
