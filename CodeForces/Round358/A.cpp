#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int a[5], b[5];

int main()
{
	int n, m; scanf("%d%d", &n, &m);
	a[0] = n / 5;
	for(int i = 1; i < 5; i++) a[i] = a[0];
	for(int i = 1; i <= n % 5; i++) a[i]++;
	b[0] = m / 5;
	for(int i = 1; i < 5; i++) b[i] = b[0];
	for(int i = 1; i <= m % 5; i++) b[i]++;

	long long ans = (long long)a[0] * b[0];
	for(int i = 1; i < 5; i++)
		ans += (long long)a[i] * b[5 - i];
	printf("%lld\n", ans);

	return 0;
}
