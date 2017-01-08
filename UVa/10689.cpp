#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MOD[] = { 1, 10, 100, 1000, 10000 };

int a, b, n, m;

int mul_mod(int a,int b) { return a * b % MOD[m]; }

void add_mod(int& a, int b) { a += b; if(a >= MOD[m]) a -= MOD[m]; }

struct Matrix
{
	int a[2][2];

	Matrix() { memset(a, 0, sizeof(a)); }

	Matrix operator * (const Matrix& t) const {
		Matrix ans;
		for(int i = 0; i < 2; i++)
			for(int j = 0; j < 2; j++)
				for(int k = 0; k < 2; k++)
					add_mod(ans.a[i][k], mul_mod(a[i][j], t.a[j][k]));
		return ans;
	}
};

Matrix pow_mod(Matrix a, int p) {
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
	Matrix M0;
	M0.a[0][1] = M0.a[1][0] = M0.a[1][1] = 1;

	int T; scanf("%d", &T);
	while(T--) {
		scanf("%d%d%d%d", &a, &b, &n, &m);
		a %= MOD[m]; b %= MOD[m];
		if(!n) { printf("%d\n", a); continue; }

		Matrix M = pow_mod(M0, n);
		int ans = 0;
		add_mod(ans, mul_mod(M.a[0][0], a));
		add_mod(ans, mul_mod(M.a[0][1], b));
		printf("%d\n", ans);
	}

	return 0;
}
