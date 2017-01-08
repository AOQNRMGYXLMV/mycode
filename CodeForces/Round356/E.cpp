#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 500 + 10;

int n, k;

char s[maxn][maxn];

int dp[maxn][maxn];
void DP() {
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1];
			if(s[i][j] == '.') dp[i][j]++;
		}
	}
}

int cc_cnt;
int cc[maxn][maxn];
int sz[maxn * maxn];

bool inside(int x, int y) { return 1<=x && x<=n && 1<=y && y<=n; }

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };

void dfs(int x, int y, int& color) {
	cc[x][y] = color;
	sz[color]++;
	for(int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if(inside(nx, ny) && s[nx][ny] == '.' && !cc[nx][ny])
			dfs(nx, ny, color);
	}
}

int cc_sum, sum;
int has[maxn * maxn];

void add(int i, int j) {
	if(!inside(i, j)) return;
	if(s[i][j] != '.') return;
	int& color = cc[i][j];
	if(!has[color]) cc_sum += sz[color];
	has[color]++;
}

void sub(int i, int j) {
	if(!inside(i, j)) return;
	if(s[i][j] != '.') return;
	int& color = cc[i][j];
	has[color]--;
	if(!has[color]) cc_sum -= sz[color];
}

int twice(int i, int j) {
	return dp[i+k-1][j+k-1] - dp[i+k-1][j-1] - dp[i-1][j+k-1] + dp[i-1][j-1];
}

int main()
{
	scanf("%d%d", &n, &k);
	for(int i = 1; i <= n; i++) scanf("%s", s[i] + 1);
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			if(s[i][j] == '.' && !cc[i][j])
				dfs(i, j, ++cc_cnt);
	DP();
	int ans = 0, k2 = k * k;
	for(int x = 1; x + k - 1 <= n; x++) {
		cc_sum = 0;
		memset(has, 0, sizeof(has));
		for(int i = x; i < x + k; i++)
			for(int j = 1; j <= k; j++) add(i, j);
		for(int i = x; i < x + k; i++) add(i, k + 1);
		for(int j = 1; j <= k; j++) add(x - 1, j);
		for(int j = 1; j <= k; j++) add(x + k, j);
		ans = max(ans, cc_sum + k2 - twice(x, 1));
		for(int y = 2; y + k - 1 <= n; y++) {
			add(x - 1, y + k - 1);
			add(x + k, y + k - 1);
			sub(x - 1, y - 1);
			sub(x + k, y - 1);
			for(int i = x; i < x + k; i++) {
				add(i, y + k);
				sub(i, y - 2);
			}
			ans = max(ans, cc_sum + k2 - twice(x, y));
		}
	}

	printf("%d\n", ans);

	return 0;
}
