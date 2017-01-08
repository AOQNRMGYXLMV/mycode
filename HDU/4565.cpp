#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int a, b, n, m;

int mul(int a, int b) { return a * b % m; }

void add(int& a, int b) { a += b; if(a >= m) a -= m; }

struct Matrix
{
	int a[2][2];

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

Matrix pow_mod(Matrix a, int p) {
	Matrix ans;
	for(int i = 0; i < 2; i++) ans.a[i][i] = 1;
	while(p) {
		if(p & 1) ans = ans * a;
		a = a * a;
		p >>= 1;
	}
	return ans;
}

int main()
{
	while(scanf("%d%d%d%d", &a, &b, &n, &m) == 4) {
		a %= m; b %= m;
		Matrix M;
		M.a[0][0] = a; M.a[0][1] = b;
		M.a[1][0] = 1; M.a[1][1] = a;
		M = pow_mod(M, n - 1);
		int ans = 0;
		add(ans, mul(M.a[0][0], a));
		add(ans, M.a[0][1]);
		ans = mul(ans, 2);
		printf("%d\n", ans);
	}

	return 0;
}
