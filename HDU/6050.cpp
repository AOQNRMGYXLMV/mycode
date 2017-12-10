#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
#define PB push_back
#define PII pair<int, int>
#define REP(i, a, b) for(int i = a; i < b; i++)
#define PER(i, a, b) for(int i = b - 1; i >= a; i--)
#define ALL(x) x.begin(), x.end()

const LL MOD = 1000000007LL;

LL mul(LL a, LL b) { return a * b % MOD; }
void add(LL& a, LL b) { a += b; if(a >= MOD) a -= MOD; }

struct Matrix {
	LL a[2][2];
	Matrix() { memset(a, 0, sizeof(a)); }
	Matrix operator * (const Matrix& t) const {
		Matrix ans;
		REP(i, 0, 2) REP(j, 0, 2) REP(k, 0, 2)
			add(ans.a[i][j], mul(a[i][k], t.a[k][j]));
		return ans;
	}
	Matrix operator + (const Matrix& t) const {
		Matrix ans = *this;
		REP(i, 0, 2) REP(j, 0, 2)
			add(ans.a[i][j], t.a[i][j]);
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

int main() {
	int _; scanf("%d", &_);
	while(_--) {
		LL n, m; scanf("%lld%lld", &n, &m);
		if(n == 1) { printf("1\n"); continue; }
		Matrix A, B, C;
		A.a[0][1] = A.a[1][1] = 1;
		A.a[1][0] = 2;
		if(n & 1) {
			B.a[0][0] = 1;
			B.a[0][1] = MOD - 1;
			B.a[1][0] = MOD - 2;
		} else {
			B.a[0][0] = MOD - 1;
			B.a[1][1] = MOD - 1;
		}
		C = pow_mod(A, n) + B;
		C = pow_mod(C, m-1);
		LL ans = C.a[0][0];
		add(ans, C.a[0][1]);
		printf("%lld\n", ans);
	}

	return 0;
}

