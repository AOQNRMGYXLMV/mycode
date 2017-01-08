#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long LL;

struct Matrix
{
	LL a[2][2];

	Matrix() { memset(a, 0, sizeof(a)); }

	Matrix operator * (const Matrix& t) const {
		Matrix ans;
		for(int i = 0; i < 2; i++)
			for(int j = 0; j < 2; j++)
				for(int k = 0; k < 2; k++)
					ans.a[i][j] += a[i][k] * t.a[k][j];
		return ans;
	}
};

Matrix Pow(Matrix a, LL p) {
	Matrix ans;
	ans.a[0][0] = ans.a[1][1] = 1;
	while(p) {
		if(p & 1) ans = ans * a;
		a = a * a;
		p >>= 1;
	}
	return ans;
}

LL p, q, n;

int main()
{
	while(scanf("%lld%lld", &p, &q) == 2) {
		if(p == 0 && q == 0) break;
		scanf("%lld", &n);
		if(n == 0) { printf("2\n"); continue; }
		Matrix M;
		M.a[0][1] = 1;
		M.a[1][0] = -q;
		M.a[1][1] = p;
		M = Pow(M, n - 1);
		LL ans = M.a[1][0] * 2 + M.a[1][1] * p;
		printf("%lld\n", ans);
	}

	return 0;
}
