#include <cstdio>
#include <cstring>
#include <algorithm>
using std::sort;
using std::max;
using std::min;
const int maxn = 100000 + 10;

int a[maxn];

int main()
{
	int n; scanf("%d", &n);
	int Max = 0, Min = 1000000007;
	for(int i = 0; i < n; i++) {
		scanf("%d", a + i);
		Max = max(Max, a[i]);
		Min = min(Min, a[i]);
	}

	int ans = 0;
	for(int i = 0; i < n; i++)
		if((a[i] != Max) && (a[i] != Min)) ans++;

	printf("%d\n", ans);

	return 0;
}
