#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 40;
const int MOD = 10;

int mul(int a, int b) { return a * b % MOD; }

void add(int& a, int b) { a += b; if(a >= MOD) a -= MOD; }

int n, k;

struct Matrix
{
	int a[maxn][maxn];

	Matrix() { memset(a, 0, sizeof(a)); }
	
	void E() {
		memset(a, 0, sizeof(a));
		for(int i = 0; i < maxn; i++) a[i][i] = 1;
	}
	
	Matrix operator + (const Matrix& t) const {
		Matrix ans;
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++) {
				add(ans.a[i][j], a[i][j]);
				add(ans.a[i][j], t.a[i][j]);
			}
		return ans;
	}
	
	Matrix operator * (const Matrix& t) const {
		Matrix ans;
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++) if(a[i][j])
				for(int k = 0; k < n; k++)
					add(ans.a[i][k], mul(a[i][j], t.a[j][k]));
		return ans;
	}

	void output() {
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n - 1; j++)
				printf("%d ", a[i][j]);
			printf("%d\n", a[i][n - 1]);
		}
		printf("\n");
	}
};

Matrix pow_mod(Matrix a, int p) {
	Matrix ans;
	ans.E();
	while(p) {
		if(p & 1) ans = ans * a;
		a = a * a;
		p >>= 1;
	}
	return ans;
}

Matrix E;

Matrix sum(Matrix a, int p) {
	if(p == 1) return a;
	Matrix ans;
	ans = (E + pow_mod(a, p / 2)) * sum(a, p / 2);
	if(p & 1) ans = ans + pow_mod(a, p);
	return ans;
}

int main()
{
	E.E();
	while(scanf("%d%d", &n, &k) == 2) {
		if(n == 0 && k == 0) break;
		Matrix a;
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++) {
				scanf("%d", &a.a[i][j]);
				a.a[i][j] %= 10;
			}

		if(k == 0) {
			E.output();
			continue;
		}

		a = sum(a, k);
		a.output();
	}

	return 0;
}
