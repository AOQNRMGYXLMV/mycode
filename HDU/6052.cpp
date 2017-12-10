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

const int maxn = 105;

int l[maxn], r[maxn];
int row[maxn * maxn][maxn];

int main() {
	int T; scanf("%d", &T);
	while(T--) {
		memset(row, 0, sizeof(row));
		int n, m; scanf("%d%d", &n, &m);
		LL ans = 0;
		REP(i, 1, n + 1) REP(j, 1, m + 1) {
			int x; scanf("%d", &x);
			int L = 0, R = m + 1;
			REP(k, 1, i+1) { l[k] = 0; r[k] = m+1; }
			REP(k, 1, j) l[row[x][k]] = k;
			PER(k, j + 1, m + 1) r[row[x][k]] = k;
			PER(k, row[x][j]+1, i + 1) {
				L = max(L, l[k]);
				R = min(R, r[k]);
				ans += (j-L) * (R-j) * (n-i+1);
			}
			row[x][j] = i;
		}
		int tot = (n * (n+1) * m * (m+1)) >> 2;
		printf("%.9f\n", (double)ans / (double)tot);
	}

	return 0;
}

