#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 15;

char s[maxn][maxn];
int n, m, t;

int main()
{
	scanf("%d%d%d", &n, &m, &t);
	for(int i = 0; i < n; i++) scanf("%s", s[i]);
	int ans = 0;
	for(int i = 0; i < n; i++) {
		int num = 0;
		for(int j = 0; j < m; j++) if(s[i][j] == 'Y') num++;
		if(num >= t) ans++;
	}

	printf("%d\n", ans);

	return 0;
}
