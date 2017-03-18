#include <cstdio>
#include <cstring>
typedef long long LL;

const LL MOD = 1000000007LL;
const int maxn = 200000 + 10;

void add(LL& a, LL b) { a += b; if(a >= MOD) a -= MOD; }

int n;
char s[maxn];
int l[maxn], r[maxn];

LL fac[maxn * 2], inv[maxn * 2];

LL pow_mod(LL a, int p) {
	LL ans = 1;
	while(p) {
		if(p & 1) ans = ans * a % MOD;
		a = a * a % MOD;
		p >>= 1;
	}
	return ans;
}

LL C(int n, int k) {
	return (fac[n] * inv[k] % MOD) * inv[n - k] % MOD;
}

int main()
{
	fac[0] = 1;
	for(int i = 1; i < maxn * 2; i++) fac[i] = fac[i - 1] * i % MOD;
	inv[maxn * 2 - 1] = pow_mod(fac[maxn * 2 - 1], MOD - 2);
	for(int i = (maxn - 1) * 2; i >= 0; i--) inv[i] = inv[i + 1] * (i + 1) % MOD;

	scanf("%s", s + 1);
	n = strlen(s + 1);
	for(int i = 1; i <= n; i++) l[i] = l[i - 1] + (s[i] == '(');
	for(int i = n; i > 0; i--) r[i] = r[i + 1] + (s[i] == ')');

	LL ans = 0;
	for(int i = 1; i <= n; i++) if(s[i] == '(') {
		add(ans, C((((l[i] + r[i]) % MOD) + MOD - 1) % MOD, l[i]));
	}

	printf("%lld\n", ans);

	return 0;
}
