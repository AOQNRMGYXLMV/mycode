#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 50;
const int MOD = 1000;

int n, r;

int mul_mod(int a, int b) { return a * b % MOD; }

void add_mod(int& a, int b) { a += b; if(a >= MOD) a-= MOD; }

struct Matrix
{
	int a[maxn][maxn];

	Matrix() { memset(a, 0, sizeof(a)); }

	Matrix operator * (const Matrix& t) const {
		Matrix ans;
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++) if(a[i][j])
				for(int k = 0; k < n; k++)
					add_mod(ans.a[i][k], mul_mod(a[i][j], t.a[j][k]));
		return ans;
	}
};

Matrix pow_mod(Matrix a, int p) {
	Matrix ans;
	for(int i = 0; i < n; i++) ans.a[i][i] = 1;
	while(p) {
		if(p & 1) ans = ans * a;
		a = a * a;
		p >>= 1;
	}
	return ans;
}

int a[maxn], b[maxn];

int main()
{
	int T; scanf("%d", &T);
	while(T--) {
		scanf("%d%d", &n, &r);
		for(int i = 0; i < n; i++) {
			scanf("%d", a + i);
			a[i] %= MOD;
		}

		Matrix M;
		for(int i = 0; i < n; i++) {
			int t; scanf("%d", &t);
			while(t--) {
				int x; scanf("%d", &x);
				M.a[i][x]++;
			}
		}

		M = pow_mod(M, r);

		memset(b, 0, sizeof(b));
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++)
				add_mod(b[i], mul_mod(M.a[i][j], a[j]));
		}

		for(int i = 0; i < n - 1; i++) printf("%d ", b[i]);
		printf("%d\n", b[n - 1]);
	}

	return 0;
}
