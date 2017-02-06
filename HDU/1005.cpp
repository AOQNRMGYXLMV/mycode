#include <cstdio>
#include <cstring>

const int MOD = 7;

void add(int& a, int b) { a += b; if(a >= MOD) a -= MOD; }

int mul(int a, int b) { return a * b % MOD; }

struct Matrix
{
	int a[2][2];
	Matrix() { memset(a, 0, sizeof(a)); }
	Matrix operator * (const Matrix& t) {
		Matrix ans;
		for(int i = 0; i < 2; i++)
			for(int j = 0; j < 2; j++)
				for(int k = 0; k < 2; k++)
					add(ans.a[i][j], mul(a[i][k], t.a[k][j]));
		return ans;
	}
};

Matrix pow_matrix(Matrix A, int p) {
	Matrix ans;
	ans.a[0][0] = ans.a[1][1] = 1;
	while(p) {
		if(p & 1) ans = ans * A;
		A = A * A;
		p >>= 1;
	}
	return ans;
}

int main()
{
	int A, B, n;
	while(scanf("%d%d%d", &A, &B, &n) && n) {
		A %= MOD; B %= MOD;
		Matrix M;
		M.a[0][1] = 1;
		M.a[1][0] = B;
		M.a[1][1] = A;
		M = pow_matrix(M, n - 1);
		printf("%d\n", (M.a[0][0] + M.a[0][1]) % MOD);
	}

	return 0;
}
