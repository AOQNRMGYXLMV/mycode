#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 300000 + 10;
int a[maxn];

int main()
{
	int n; scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", a + i);
	sort(a + 1, a + 1 + n);
	printf("%d\n", a[(n + 1) >> 1]);

	return 0;
}
