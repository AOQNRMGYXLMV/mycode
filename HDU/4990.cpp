#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long LL;

LL n, MOD;

LL mul_mod(LL a, LL b) { return a * b % MOD; }

LL add_mod(LL& a, LL b) { a += b; if(a >= MOD) a -= MOD; }

struct Matrix
{
	LL a[3][3];
	Matrix() { memset(a, 0, sizeof(a)); }
	Matrix operator * (const Matrix& t) const {
		Matrix ans;
		for(int i = 0; i < 3; i++)
			for(int j = 0; j < 3; j++)
				for(int k = 0; k < 3; k++)
					add_mod(ans.a[i][j], mul_mod(a[i][k], t.a[k][j]));
		return ans;
	}
};

Matrix pow_mod(Matrix a, LL n) {
	Matrix ans;
	for(int i = 0; i < 3; i++) ans.a[i][i] = 1;
	while(n) {
		if(n & 1) ans = ans * a;
		a = a * a;
		n >>= 1;
	}
	return ans;
}

int main()
{
	LL a0[3], a[3];
	a0[0] = a0[2] = 1; a0[1] = 2;
	Matrix M0;
	M0.a[0][1] = 2; M0.a[1][1] = 4;
	M0.a[0][2] = 1; M0.a[2][2] = 1;
	M0.a[1][2] = 2;

	while(scanf("%lld%lld", &n, &MOD) == 2) {
		Matrix M;
		for(int i = 0; i < 3; i++)
			for(int j = 0; j < 3; j++)
				M.a[i][j] = M0.a[i][j] % MOD;
		for(int i = 0; i < 3; i++)
			a[i] = a0[i] % MOD;

		M = pow_mod(M, (n - 1) / 2);
		int x = ((n & 1) ^ 1);
		LL ans = 0;
		for(int i = 0; i < 3; i++)
			add_mod(ans, mul_mod(M.a[x][i], a[i]));
		printf("%lld\n", ans);
	}

	return 0;
}
