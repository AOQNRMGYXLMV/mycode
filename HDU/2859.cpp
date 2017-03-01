#include <cstdio>
#include <algorithm>

const int maxn = 1001;

char s[maxn][maxn];
int d[maxn][maxn];

int main()
{

	int n;
	while(scanf("%d", &n) == 1 && n) {
		for(int i = 0; i < n; i++) scanf("%s", s[i]);
		for(int i = 0; i < n; i++) d[0][i] = d[i][n-1] = 1;

		int ans = 1;
		for(int i = 1; i < n; i++) {
			for(int j = n - 2; j >= 0; j--) {
				int t = 1;
				while(i-t>=0 && j+t<n && s[i-t][j] == s[i][j+t]) t++;
				if(t > d[i-1][j+1]) d[i][j] = d[i-1][j+1] + 1;
				else d[i][j] = t;
				ans = std::max(ans, d[i][j]);
			}
		}

		printf("%d\n", ans);
	}
	return 0;
}
