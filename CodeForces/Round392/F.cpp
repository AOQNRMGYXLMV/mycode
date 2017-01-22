#include <cstdio>

typedef long long LL;

int gcd(int a, int b) { return !b ? a : gcd(b, a % b); }

LL pow(LL a, int p) {
	LL ans = 1;
	while(p) {
		if(p & 1) ans *= a;
		a *= a;
		p >>= 1;
	}
	return ans;
}

int main()
{
	int n, l, r; scanf("%d%d%d", &n, &l, &r);
	if(n == 1) { printf("%d\n", r - l + 1); return 0; }
	if(n == 2) {
		printf("%lld\n", (LL)(r - l + 1) * (r - l));
		return 0;
	}
	if(n > 30) { printf("0\n"); return 0; }

	n--;
	int M = 1;
	while(pow(M + 1, n) <= r) M++;
	LL ans = 0;
	for(int y = 1; y <= M; y++) {
		for(int x = y + 1; x <= M; x++) if(gcd(x, y) == 1) {
			int py = pow(y, n), px = pow(x, n);
			int L = 1, R = l / py + 1;
			int RR = r / px;
			while(L < R) {
				int M = (L + R) / 2;
				if(M * py < l) L = M + 1;
				else R = M;
			}
			if(L <= RR) ans += RR - L + 1;
		}
	}

	printf("%lld\n", ans << 1);

	return 0;
}
