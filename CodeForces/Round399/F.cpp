#include <cstdio>

typedef long long LL;

const LL MOD = 1000000007LL;
const int maxn = 100000 + 10;

LL mul_mod(LL a, LL b) { return a * b % MOD; }

void add(LL& a, LL b) { a += b; if(a >= MOD) a -= MOD; }

LL pow_mod(LL a, int p) {
	LL ans = 1;
	while(p) {
		if(p & 1) ans = mul_mod(ans, a);
		a = mul_mod(a, a);
		p >>= 1;
	}
	return ans;
}

LL inverse(LL a) { return pow_mod(a, MOD - 2); }

LL fac[maxn], inv[maxn];

LL C(LL n, LL k) {
	if(k > n) return 0;
	return mul_mod(mul_mod(fac[n], inv[k]), inv[n - k]);
}

int main()
{
	//printf("1 / 2 = %lld\n", mul_mod(1, inverse(2)));
	//printf("2 / 4 : %lld\n", mul_mod(2, inverse(4)));
	fac[0] = 1;
	for(int i = 1; i < maxn; i++) fac[i] = mul_mod(fac[i - 1], i);
	inv[maxn - 1] = inverse(fac[maxn - 1]);
	for(int i = maxn - 2; i >= 0; i--) inv[i] = mul_mod(inv[i + 1], i + 1);
	LL f, w, h;
	scanf("%lld%lld%lld", &f, &w, &h);
	if(!w) { printf("1\n"); return 0; }
	LL sum = 0, ok = 0;;
	for(LL u = 1; u <= f + 1 && u <= w; u++) {
		LL t = C(f + 1, u);
		add(sum, mul_mod(t, C(w - 1, u - 1)));
		if(w >= (h + 1) * u) add(ok, mul_mod(t, C(w - u * h - 1, u - 1)));
	}

	printf("%lld\n", mul_mod(ok, inverse(sum)));

	return 0;
}
