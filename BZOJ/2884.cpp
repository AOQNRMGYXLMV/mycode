#include <cstdio>

int phi(int x) {
	int ans = x;
	for(int i = 2; i * i <= x; i++) if(x % i == 0) {
		ans /= i;
		ans *= (i - 1);
		while(x % i == 0) x /= i;
	}
	if(x > 1) { ans /= x; ans *= (x - 1); }
	return ans;
}

int pow_mod(long long a, int p, int m) {
	long long ans = 1;
	while(p) {
		if(p & 1) ans = ans * a % m;
		a = a * a % m;
		p >>= 1;
	}
	return ans % m;
}

int solve(int p) {
	if(p == 1) return 0;
	int k = 0;
	while(~p & 1) { p >>= 1; k++; }
	int ph = phi(p);
	int ans = solve(ph);
	ans += ((-k % ph) + ph) % ph;
	ans %= ph;
	ans = pow_mod(2, ans, p);
	return (ans << k);
}

int main()
{
	int T; scanf("%d", &T);
	while(T--) {
		int p; scanf("%d", &p);
		printf("%d\n", solve(p));
	}

	return 0;
}
