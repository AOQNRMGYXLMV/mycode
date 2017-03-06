#include <cstdio>

typedef long long LL;
const LL MOD = 1000000007LL;
LL mul(LL a, LL b) { return a * b % MOD; }
void add(LL& a, LL b) { a += b; if(a >= MOD) a -= MOD; }
const int maxn = 2000 + 10;

int a[maxn], sum[maxn];
LL d[maxn][maxn];

int main()
{
	int n; scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", a + i);
	for(int i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i];
	for(int i = 1; i <= n; i++) d[i][1] = a[i] ? 1 : 0;

	for(int len = 2; len <= n; len++) {
		for(int i = 1; i + len - 1 <= n; i++) {
			LL& t = d[i][len]; int r = i + len - 1;
			t = 0;
			for(int j = i; j < r; j++) if(sum[j]-sum[i-1])
					add(t, d[j+1][r-j]);
			if(sum[r] - sum[i-1]) t++;
		}
	}

	printf("%lld\n", d[1][n]);

	return 0;
}
