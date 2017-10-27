#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define REP(i, a, b) for(int i = a; i < b; i++)
#define PER(i, a, b) for(int i = b - 1; i >= a; i--)
const int maxn = 400;

char s[maxn][50];

int main() {
	int n; scanf("%d", &n);
	int ans = 0;
	REP(i, 0, n) {
		scanf("%s", s[i]);
		for(int j = 0; s[i][j]; j++) {
			if(s[i][j] == 'h') {
				int t;
				for(t = j - 1; t >= 0 && s[i][t] == 'k'; t--);
				t++;
				int tmp = t;
				if(t < j) {
					int p = j;
					while(s[i][p]) {
						s[i][t] = s[i][p];
						t++; p++;
					}
					s[i][t] = 0;
				}
				j = tmp;
			} else if(s[i][j] == 'u') {
				int l = strlen(s[i]);
				PER(k, j + 2, l + 1) s[i][k] = s[i][k-1];
				s[i][j] = s[i][j+1] = 'o';
				s[i][l+1] = 0;
				j++;
			}
		}
		int flag = 1;
		REP(j, 0, i) if(!strcmp(s[i], s[j])) { flag = 0; break; }
//		printf("%d: %s\n", i, s[i]);
		ans += flag;
	}
	printf("%d\n", ans);

	return 0;
}
