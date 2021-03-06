#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 40;
const int MOD = 10;

int mul(int a, int b) { return a * b % MOD; }

void add(int& a, int b) { a += b; if(a >= MOD) a -= MOD; }

int n, k, sz;
int a[maxn][maxn], b[maxn][maxn];

struct Matrix
{
	int a[maxn * 2][maxn * 2];

	Matrix() { memset(a, 0, sizeof(a)); }

	Matrix operator * (const Matrix& t) const {
		Matrix ans;
		for(int i = 0; i < sz; i++)
			for(int j = 0; j < sz; j++)
				for(int k = 0; k < sz; k++)
					add(ans.a[i][j], mul(a[i][k], t.a[k][j]));
		return ans;
	}

	void output() {
		for(int i = 0; i < sz; i++) {
			for(int j = 0; j < sz - 1; j++)
				printf("%d ", a[i][j]);
			printf("%d\n", a[i][sz - 1]);
		}
		printf("\n");
	}
};

Matrix pow_mod(Matrix a, int p) {
	Matrix ans;
	for(int i = 0; i < sz; i++) ans.a[i][i] = 1;
	while(p) {
		if(p & 1) ans = ans * a;
		a = a * a;
		p >>= 1;
	}
	return ans;
}

int main()
{
	while(scanf("%d%d", &n, &k) == 2 && n) {
		Matrix M;
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++) {
				scanf("%d", &a[i][j]);
				a[i][j] %= MOD;
				M.a[i][j] = a[i][j];
			}

		if(!k) {
			for(int i = 0; i < n; i++) {
				for(int j = 0; j < n - 1; j++)
					printf("%d ", i == j ? 1 : 0);
				printf("%d\n", i == n - 1 ? 1 : 0);
			}
			printf("\n");
			continue;
		}
		
		for(int i = n; i < n * 2; i++)
			M.a[i][i] = M.a[i][i - n] = 1;

		sz = n * 2;
		M = pow_mod(M, k);
		memset(b, 0, sizeof(b));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++) if(M.a[i + n][j])
				for(int k = 0; k < n; k++)
					add(b[i][k], mul(M.a[i + n][j], a[j][k]));

		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n - 1; j++)
				printf("%d ", b[i][j]);
			printf("%d\n", b[i][n - 1]);
		}
		printf("\n");
	}

	return 0;
}
