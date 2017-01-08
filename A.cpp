#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long LL;

int x, c, k;
LL m;

int mul(int a, int b) { return a * b % k; }
void add(int& a, int b) { a += b; if(a >= k) a -= k; }

struct Matrix
{
	int a[2][2];
	Matrix() { memset(a, 0, sizeof(a)); }
	Matrix operator * (const Matrix& t) const {
		Matrix ans;
		for(int i = 0; i < 2; i++) {
			for(int j = 0; j < 2; j++) {
				for(int k = 0; k < 2; k++) {
					add(ans.a[i][j], mul(a[i][k], t.a[k][j]));
				}
			}
		}
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
	int T; scanf("%d", &T);
	for(int kase = 1; kase <= T; kase++) {
		scanf("%d%lld%d%d", &x, &m, &k, &c);
		x %= k;
		Matrix t;
		t.a[0][0] = 10 % k;
		t.a[0][1] = x;
		t.a[1][1] = 1 % k;
		t = pow_mod(t, m - 1);
		int ans = 0;
		add(ans, mul(t.a[0][0], x));
		add(ans, t.a[0][1]);
		printf("Case #%d:\n%s\n", kase, ans == c ? "Yes" : "No");
	}

	return 0;
}
