#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long LL;

const LL MOD = 1000000007;

void add(LL& a, LL b) { a += b; if(a >= MOD) a -= MOD; }

LL mul(LL a, LL b) { return a * b % MOD; }

struct Matrix
{
	LL a[2][2];

	Matrix() { memset(a, 0, sizeof(a)); }

	Matrix operator * (const Matrix& t) const {
		Matrix ans;
		for(int i = 0; i < 2; i++)
			for(int j = 0; j < 2; j++)
				for(int k = 0; k < 2; k++)
					add(ans.a[i][j], mul(a[i][k], t.a[k][j]));
		return ans;
	}
};

Matrix pow_mod(Matrix a, LL p) {
	Matrix ans;
	ans.a[0][0] = ans.a[1][1] = 1;
	while(p) {
		if(p & 1) ans = ans * a;
		a = a * a;
		p >>= 1;
	}
	return ans;
}

int main()
{
	LL A, B, n, x;
	scanf("%lld%lld%lld%lld", &A, &B, &n, &x);
	Matrix M;
	M.a[0][0] = A;
	M.a[0][1] = B;
	M.a[1][1] = 1;
	M = pow_mod(M, n);
	LL ans = 0;
	add(ans, mul(M.a[0][0], x));
	add(ans, M.a[0][1]);

	printf("%lld\n", ans);

	return 0;
}
