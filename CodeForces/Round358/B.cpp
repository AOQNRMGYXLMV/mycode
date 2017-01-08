#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 100000 + 10;

int a[maxn];

int main()
{
	int n; scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", a + i);
	sort(a + 1, a + 1 + n);

	int ans = 1;
	for(int i = 1; i <= n; i++) if(a[i] >= ans) {
		ans++;
	}

	printf("%d\n", ans);

	return 0;
}
