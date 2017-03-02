#include <cstdio>
#include <vector>
using std::vector;

typedef long long LL;
const int maxn = 500 + 1;

LL a[maxn][maxn];

vector<LL> b;

int main()
{
	int n; scanf("%d", &n);

	if(n == 1) { printf("1\n"); return 0; }

	LL s1 = 0, s2 = 0;
	int x, y;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			scanf("%lld", &a[i][j]);
			a[i][n] += a[i][j];
			a[n][j] += a[i][j];
			if(i == j) s1 += a[i][j];
			if(i + j == n - 1) s2 += a[i][j];
			if(!a[i][j]) { x = i; y = j; }
		}
	}

	int p = 0;
	if(p == x) p++;
	LL t = a[p][n] - a[x][n];
	if(t <= 0) { printf("-1\n"); return 0; }
	a[x][n] += t; a[n][y] += t;
	if(x == y) s1 += t;
	if(x + y == n - 1) s2 += t;

	b.push_back(s1);
	b.push_back(s2);
	for(int i = 0; i < n; i++) { b.push_back(a[i][n]); b.push_back(a[n][i]); }
	for(int i = 1; i < n * 2 + 2; i++) if(b[i] != b[0]) { t = -1; break; }
	printf("%lld\n", t);

	return 0;
}
