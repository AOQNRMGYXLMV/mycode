#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef unsigned int LL;
const int maxn = 150;

int n, m, sz;

struct Matrix
{
	LL a[maxn][maxn];
	
	Matrix() {
		for(int i = 0; i < maxn; i++)
			for(int j = 0; j < maxn; j++) a[i][j] = 0;
	}
	
	Matrix operator * (const Matrix& t) const {
		Matrix ans;
		for(int i = 0; i < sz; i++)
			for(int j = 0; j < sz; j++) if(a[i][j])
				for(int k = 0; k < sz; k++)
					ans.a[i][k] += a[i][j] * t.a[j][k];
		return ans;
	}
};

Matrix pow_mod(Matrix a, int n) {
	Matrix ans;
	for(int i = 0; i < sz; i++) ans.a[i][i] = 1;
	while(n) {
		if(n & 1) ans = ans * a;
		a = a * a;
		n >>= 1;
	}
	return ans;
}

LL a[maxn], dp[25][6];

int main()
{
	int T; scanf("%d", &T);
	for(int kase = 1; kase <= T; kase++) {
		printf("Case %d: ", kase);
		scanf("%d%d", &n, &m);
		int N = (n - 1) * (n - 1) * n;

		//DP
		memset(dp, 0, sizeof(dp));
		for(int i = 1; i < n; i++) dp[0][i] = 1;
		for(int i = 0; i < (n - 1) * (n - 1); i++) {
			for(int j = 0; j < n; j++) {
				for(int k = 0; k < n; k++) {
					int d = (k - j) * (k - j);
					if(!d || i + d > N) continue;
					dp[i + d][k] += dp[i][j];
				}
			}
		}

		if(m < (n - 1) * (n - 1)) {
			LL ans = 0;
			for(int i = 0; i < n; i++) ans += dp[m][i];
			printf("%u\n", ans);
			continue;
		}

		sz = N;
		int s = (n - 1) * (n - 1);
		for(int i = 0; i < (n - 1) * (n - 1); i++)
			for(int j = 0; j < n; j++)
				a[i * n + j] = dp[i][j];
		Matrix M;
		
		for(int i = n; i < N; i++) M.a[i - n][i] = 1;
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++) if(j != i) {
				int d = (j - i) * (j - i);
				M.a[N - n + i][n * (s - d) + j] = 1;
			}
		M = pow_mod(M, m - (n - 1) * (n - 1) + 1);
		LL ans = 0;
		for(int i = N - n; i < N; i++)
			for(int j = 0; j < N; j++)
				ans += M.a[i][j] * a[j];
		printf("%u\n", ans);
	}

	return 0;
}
