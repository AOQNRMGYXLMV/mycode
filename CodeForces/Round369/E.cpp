#include <cstdio>

typedef long long LL;

LL MOD = 1000000 + 3;

LL pow_mod(LL a, LL p) {
	LL ans = 1;
	while(p) {
		if(p & 1) ans = ans * a % MOD;
		a = a * a % MOD;
		p >>= 1;
	}
	return ans;
}

LL inverse(LL a) { return pow_mod(a, MOD - 2); }

LL add(LL a, LL b) { a += b; if(a >= MOD) a -= MOD; return a; }

int main()
{
	LL n, k; scanf("%lld%lld", &n, &k);

	if(n <= 60) {
		if(k > (1LL << n)) { printf("1 1\n"); return 0; }
	}

	LL n_2 = pow_mod(2, n);
	LL A = 1, B = pow_mod(n_2, k - 1);
	LL cnt = 0;
	for(LL t = k - 1; t; t >>= 1) cnt += t >> 1;
	for(LL i = 1; i < k && A; i++) A = A * add(n_2, MOD - i) % MOD;

	LL inv = inverse(pow_mod(2, cnt));
	A = A * inv % MOD;
	B = B * inv % MOD;
	A = (B - A + MOD) % MOD;

	printf("%lld %lld\n", A, B);

	return 0;
}
