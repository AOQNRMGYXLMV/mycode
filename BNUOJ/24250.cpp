#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 50000 + 10;

int n;
int a[maxn];
int d[3][maxn];
double ans[3], sum[3];

int main()
{
	int T; scanf("%d", &T);
	for(int kase = 1; kase <= T; kase++) {
		scanf("%d", &n);
		for(int i = 1; i <= n; i++) scanf("%d", a + i);
		memset(ans, 0, sizeof(ans));
		double tot = (double)n * (n + 1) / 2.0;
		int pow = 1;
		for(int j = 0; j < 30; j++) {
			memset(sum, 0, sizeof(sum));
			for(int i = 1; i <= n; i++) {
				if(a[i] & pow) {
					d[0][i] = d[0][i - 1] + 1;
					d[1][i] = i;
					d[2][i] = i - d[2][i - 1];
				} else {
					d[0][i] = 0;
					d[1][i] = d[1][i - 1];
					d[2][i] = d[2][i - 1];
				}
				for(int k = 0; k < 3; k++)
					sum[k] += d[k][i];
			}
			for(int i = 0; i < 3; i++) ans[i] += pow * sum[i] / tot;
			pow <<= 1;
		}

		printf("Case #%d:", kase);
		for(int i = 0; i < 3; i++) printf(" %.6f", ans[i]);
		printf("\n");
	}

	return 0;
}
