#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long LL;
const int maxn = 15;
const LL MOD = 10000007;

LL mul_mod(LL a, LL b) { return a * b % MOD; }

LL add_mod(LL& a, LL b) { a += b; if(a >= MOD) a -= MOD; }

int n, m, sz;
int a[maxn], b[maxn];

struct Matrix
{
	LL a[15][15];
	Matrix() { memset(a, 0, sizeof(a)); }
	Matrix operator * (const Matrix& t) const {
		Matrix ans;
		for(int i = 0; i < sz; i++)
			for(int j = 0; j < sz; j++)
				for(int k = 0; k < sz; k++)
					add_mod(ans.a[i][j], mul_mod(a[i][k], t.a[k][j]));
		return ans;
	}
};

Matrix pow_mod(Matrix a, int n) {
	Matrix ans;
	for(int i = 0; i < sz; i++) ans.a[i][i] = 1;
	while(n) {
		if(n & 1) ans = ans * a;
		a = a * a;
		n >>= 1;
	}
	return ans;
}

int main()
{
	while(scanf("%d%d", &n, &m) == 2) {
		for(int i = 1; i <= n; i++) {
			scanf("%d", a + i);
			a[i] %= MOD;
		}

		if(m == 0) { printf("%d\n", a[n]); continue; }

		sz = n + 2;
		b[0] = 233;
		for(int i = 1; i <= n; i++) b[i] = (b[i-1] + a[i]) % MOD;
		b[n + 1] = 3;

		Matrix M;
		for(int i = 0; i < sz - 1; i++) M.a[i][0] = 10;
		for(int i = 0; i < sz; i++) M.a[i][sz-1] = 1;
		for(int i = 1; i < sz - 1; i++)
			for(int j = 1; j <= i; j++) M.a[i][j] = 1;
		M = pow_mod(M, m - 1);

		LL ans = 0;
		for(int i = 0; i < sz; i++)
			add_mod(ans, mul_mod(M.a[sz-2][i], b[i]));
		printf("%lld\n", ans);
	}

	return 0;
}
