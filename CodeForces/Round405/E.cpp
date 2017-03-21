#include <cstdio>
#include <cstring>

const int maxn = 76;
const int INF = 0x3f3f3f3f;

int n;
char s[maxn];
int d[maxn][maxn][maxn][2];
int pos[3][maxn], cnt[3], used[3]; // V, K, X

void upd(int& a, int b) { if(b < a) a = b; }

int cost(int limit) {
	int ans = 0;
	for(int i = 0; i < 3; i++) {
		for(int j = used[i] + 1; j <= cnt[i] && pos[i][j] < limit; j++)
			ans++;
	}
	return ans;
}

int main()
{
	scanf("%d\n%s", &n, s);
	
	for(int i = 0; i < n; i++) {
		if(s[i] == 'V') pos[0][++cnt[0]] = i;
		else if(s[i] == 'K') pos[1][++cnt[1]] = i;
		else pos[2][++cnt[2]] = i;
	}

	memset(d, 0x3f, sizeof(d));
	d[0][0][0][0] = 0;
	int tot = 0;
	int &v = used[0], &k = used[1], &x = used[2];
	for(v = 0; v <= cnt[0]; v++) {
		for(k = 0; k <= cnt[1]; k++) {
			for(x = 0; x <= cnt[2]; x++) {
				for(int t = 0; t <= 1; t++) {
					int& cur = d[v][k][x][t];
					if(cur == INF) continue;
					if(v < cnt[0]) upd(d[v+1][k][x][1], cur+cost(pos[0][v+1]));
					if(k < cnt[1] && t == 0) upd(d[v][k+1][x][0], cur+cost(pos[1][k+1]));
					if(x < cnt[2]) upd(d[v][k][x+1][0], cur+cost(pos[2][x+1]));
				}
			}
		}
	}

	int ans = INF;
	for(int t = 0; t < 2; t++) upd(ans, d[cnt[0]][cnt[1]][cnt[2]][t]);
	printf("%d\n", ans);

	return 0;
}
