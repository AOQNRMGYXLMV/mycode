#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

typedef long long LL;
const LL MOD = 1000000007;

LL mul_mod(LL a, LL b) { return a * b % MOD; }

LL add_mod(LL& a, LL b) { a += b; if(a >= MOD) a -= MOD; }

struct Matrix
{
	LL a[2][2];
	
	Matrix() { memset(a, 0, sizeof(a)); }

	Matrix operator * (const Matrix& t) const {
		Matrix ans;
		for(int i = 0; i < 2; i++)
			for(int j = 0; j < 2; j++)
				for(int k = 0; k < 2; k++)
					add_mod(ans.a[i][j], mul_mod(a[i][k], t.a[k][j]));
		return ans;
	}
};

Matrix pow_mod(Matrix a, LL n) {
	Matrix ans;
	ans.a[0][0] = ans.a[1][1] = 1;
	while(n) {
		if(n & 1) ans = ans * a;
		a = a * a;
		n >>= 1;
	}
	return ans;
}

int main()
{
	LL x, y, n;
	cin >> x >> y >> n;
	x = ((x % MOD) + MOD) % MOD;
	y = ((y % MOD) + MOD) % MOD;

	Matrix a;
	a.a[0][0] = 0;
	a.a[0][1] = a.a[1][1] = 1;
	a.a[1][0] = MOD - 1;
	a = pow_mod(a, n - 1);

	LL ans = mul_mod(a.a[0][0], x);
	add_mod(ans, mul_mod(a.a[0][1], y));

	cout << ans << endl;

	return 0;
}
