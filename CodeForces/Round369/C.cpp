#include <cstdio>
#include <cstring>
#include <algorithm>

typedef long long LL;
const int maxn = 100 + 5;
int n, m, K;

int color[maxn];
LL p[maxn][maxn], d[maxn][maxn][maxn];

void update(LL& a, LL b) {
	if(a == -1) a = b;
	else a = std::min(a, b);
}

int main()
{
	scanf("%d%d%d", &n, &m, &K);
	for(int i = 1; i <= n; i++) scanf("%d", color + i);
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++) scanf("%lld", &p[i][j]);
	
	memset(d, -1, sizeof(d));
	if(color[1]) d[1][1][color[1]] = 0;
	else {
		for(int k = 1; k <= m; k++) d[1][1][k] = p[1][k];
	}
	for(int i = 1; i < n; i++) {
		for(int j = 1; j <= i && j <= K; j++) {
			for(int k = 1; k <= m; k++) if(d[i][j][k] != -1) {
				LL& t = d[i][j][k];
				int& c = color[i + 1];
				if(c) update(d[i+1][j+(c!=k)][c], t);
				else {
					for(int l = 1; l <= m; l++)
						update(d[i+1][j+(l!=k)][l], t + p[i+1][l]);
				}
			}
		}
	}

	LL ans = -1;
	for(int i = 1; i <= m; i++) if(d[n][K][i] != -1) update(ans, d[n][K][i]);
	printf("%lld\n", ans);

	return 0;
}
