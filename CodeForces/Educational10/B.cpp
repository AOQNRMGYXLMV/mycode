#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 1000 + 10;

int n;
int a[maxn], b[maxn];

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", a + i);
	sort(a + 1, a + 1 + n);
	for(int i = 1; i <= (n + 1) / 2; i++)
		b[i * 2 - 1] = a[i];
	int j = 2, mid = (n + 1) / 2;
	for(int i = mid + 1; i <= n; i++, j += 2)
		b[j] = a[i];
	for(int i = 1; i <= n; i++) printf("%d ", b[i]);
	printf("\n");

	return 0;
}
