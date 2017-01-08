#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 12;

double a[maxn][maxn];

int main()
{
	int n, t; scanf("%d%d", &n, &t);
	a[1][1] = t;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= i; j++) if(a[i][j] > 1.0) {
			double t = (a[i][j] - 1.0) / 2.0;
			a[i + 1][j] += t;
			a[i + 1][j + 1] += t;
		}
	}

	int ans = 0;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= i; j++) if(a[i][j] >= 1.0)
			ans++;

	printf("%d\n", ans);

	return 0;
}
