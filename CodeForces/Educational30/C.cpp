#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define REP(i, a, b) for(int i = a; i < b; i++)
#define PER(i, a, b) for(int i = b - 1; i >= a; i--)

const int maxn = 100 + 10;

int n, m, k;
int a[maxn][maxn], s[maxn][maxn];

int main() {
	scanf("%d%d%d", &n, &m, &k);
	REP(i, 0, n) REP(j, 0, m) scanf("%d", &a[i][j]);
	PER(i, 0, n) REP(j, 0, m) s[i][j] = s[i+1][j] + a[i][j];

	int cnt = 0, point = 0;
	REP(j, 0, m) {
		int x = 0, p = 0, c = 0;
		REP(i, 0, n) if(a[i][j]) {
			int d = min(i + k, n + 1);
			int t = s[i][j] - s[d][j];
			if(t > p) { p = t; x = c; }
			c++;
		}
		point += p; cnt += x;
	}

	printf("%d %d\n", point, cnt);

	return 0;
}