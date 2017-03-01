#include <cstdio>

int n, m;

int phi(int x) {
	int ans = x;
	for(int i = 2; i * i <= x; i++) if(x % i == 0) {
		ans /= i;
		ans *= i - 1;
		while(x % i == 0) x /= i;
	}
	if(x > 1) { ans /= x; ans *= x - 1; }
	return ans;
}

int pow_mod(int a, int p, int mod) {
	int ans = 1;
	for(int i = 0; i < p; i++) {
		ans *= a;
		if(ans >= mod) break;
		if(i + 1 == p) return ans;
	}
	ans = 1;
	while(p) {
		if(p & 1) ans = ans * a % mod;
		a = a * a % mod;
		p >>= 1;
	}
	return ans + mod;
}

int a[15];

int f(int d, int mod) {
	if(d == n) return a[d] < mod ? a[d] : (a[d] % mod) + mod;
	return pow_mod(a[d], f(d + 1, phi(mod)), mod);
}

int main()
{
	int kase = 1;
	while(scanf("%d%d", &m, &n) == 2) {
		printf("Case #%d: ", kase++);
		for(int i = 1; i <= n; i++) scanf("%d", a + i);
		printf("%d\n", f(1, m) % m);
	}
	return 0;
}
