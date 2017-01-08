#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 100 + 10;
int a[maxn];

int Operation(int x) {
	int pos;
	for(pos = 0; ; pos++) if(a[pos] == x) break;
	for(int i = pos - 1; i >= 0; i--) a[i + 1] = a[i];
	a[0] = x;
	return pos + 1;
}

int main()
{
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 0; i < k; i++) scanf("%d", a + i);

	int ans = 0;
	for(int i = 0; i < n * m; i++) {
		int x; scanf("%d", &x);
		ans += Operation(x);
	}

	printf("%d\n", ans);

	return 0;
}
