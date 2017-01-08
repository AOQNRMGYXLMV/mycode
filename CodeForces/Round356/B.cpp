#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 100 + 10;

int n, a, t[maxn], c[maxn];

int main()
{
	scanf("%d%d", &n, &a);
	for(int i = 1; i <= n; i++) {
		scanf("%d", t + i);
		if(t[i]) c[abs(i - a)]++;
	}

	int r = min(a - 1, n - a);
	int R = max(a - 1, n - a);
	int ans = c[0];
	for(int i = 1; i <= r; i++) if(c[i] == 2) ans += 2;
	for(int i = r + 1; i <= R; i++) if(c[i]) ans++;

	printf("%d\n", ans);

	return 0;
}
