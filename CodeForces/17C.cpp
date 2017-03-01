#include <cstdio>
#include <cstring>
#include <algorithm>

const int MOD = 51123987;

int d[151][52][52][52];
int next[160][3];
char s[160];

void add(int& a, int b) { a += b; if(a >= MOD) a -= MOD; }

int main()
{
	int n; scanf("%d", &n);
	scanf("%s", s);

	memset(next, -1, sizeof(next));
	int tot = std::unique(s, s + n) - s;
	for(int i = 0; i < tot; i++) {
		for(int j = i; j < tot; j++) {
			if(next[i][s[j]-'a'] == -1)
				next[i][s[j]-'a'] = j;
		}
	}

	int m = (n + 2) / 3;
	d[0][0][0][0] = 1;
	for(int i = 0; i < tot; i++) {
		for(int a = 0; a <= m; a++) {
			for(int b = 0; b <= m; b++) {
				for(int c = 0; c <= m; c++) if(d[i][a][b][c]) {
					int& t = d[i][a][b][c];
					if(next[i][0] != -1) add(d[next[i][0]][a+1][b][c], t);
					if(next[i][1] != -1) add(d[next[i][1]][a][b+1][c], t);
					if(next[i][2] != -1) add(d[next[i][2]][a][b][c+1], t);
				}
			}
		}
	}

	int ans = 0;
	if(n % 3 == 0) {
		for(int i = 0; i < tot; i++) add(ans, d[i][m][m][m]);
	} else if(n % 3 == 1) {
		for(int i = 0; i < tot; i++) {
			add(ans, d[i][m-1][m-1][m]);
			add(ans, d[i][m][m-1][m-1]);
			add(ans, d[i][m-1][m][m-1]);
		}
	} else {
		for(int i = 0; i < tot; i++) {
			add(ans, d[i][m-1][m][m]);
			add(ans, d[i][m][m-1][m]);
			add(ans, d[i][m][m][m-1]);
		}
	}

	printf("%d\n", ans);

	return 0;
}
