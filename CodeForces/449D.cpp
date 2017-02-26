#include <cstdio>

const int maxn = 1 << 20;

typedef long long LL;

const LL MOD = 1000000007LL;

void add(LL& a, LL b) { a += b; if(a >= MOD) a -= MOD; }

LL d[21][maxn];

LL pow_mod(LL a, int p) {
	LL ans = 1;
	while(p) {
		if(p & 1) ans = ans * a % MOD;
		a = a * a % MOD;
		p >>= 1;
	}
	return ans;
}

int bitcount(int x) {
	int ans = 0;
	for(; x; x >>= 1) if(x & 1) ans++;
	return ans;
}

int main()
{
	int n; scanf("%d", &n);
	while(n--) {
		int x; scanf("%d", &x);
		d[0][x]++;
	}

	for(int k = 1; k <= 20; k++) {
		for(int x = 0; x < maxn; x++) {
			d[k][x] = d[k-1][x];
			if(!((x>>(k-1))&1)) add(d[k][x], d[k-1][x|(1<<(k-1))]);
		}
	}

	LL ans = 0;
	for(int x = 0; x < maxn; x++) if(d[20][x]) {
		if(bitcount(x) & 1) add(ans, MOD - (pow_mod(2, d[20][x]) - 1));
		else add(ans, pow_mod(2, d[20][x]) - 1);
	}

	printf("%lld\n", ans);

	return 0;
}
