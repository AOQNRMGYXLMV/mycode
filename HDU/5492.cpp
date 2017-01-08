#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 30;
const int maxs = 1800;
const int INF = 0x3f3f3f3f;

int n, m;
int a[maxn][maxn];
int d[maxn][maxn][maxs];

int main()
{
    int T; scanf("%d", &T);
    for(int kase = 1; kase <= T; kase++) {
        scanf("%d%d", &n, &m);
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++) scanf("%d", &a[i][j]);
        memset(d, 0x3f, sizeof(d));
        d[0][0][a[0][0]] = a[0][0] * a[0][0];
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
				for(int k = 0; k <= (i+j+1)*30; k++) if(d[i][j][k] < INF) {
					if(i < n - 1) {
						int& v = a[i + 1][j];
						int& ans = d[i + 1][j][k + v];
						ans = min(ans, d[i][j][k] + v * v);
					}
					if(j < m - 1) {
						int& v = a[i][j + 1];
						int& ans = d[i][j + 1][k + v];
						ans = min(ans, d[i][j][k] + v * v);
					}
				}
            }
        }

        int ans = INF;
        for(int s = 0; s < 1800; s++) if(d[n-1][m-1][s] < INF)
            ans = min(ans, d[n-1][m-1][s] * (n+m-1) - s*s);
        printf("Case #%d: %d\n", kase, ans);
    }

    return 0;
}
