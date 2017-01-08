#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int a[10], cnt[110];

int main()
{
	int sum = 0;
	for(int i = 0; i < 5; i++) {
		scanf("%d", a + i);
		cnt[a[i]]++;
		sum += a[i];
	}

	int ans = sum;
	sort(a, a + 5);
	int tot = unique(a, a + 5) - a;
	for(int i = 0; i < tot; i++) if(cnt[a[i]] >= 2) {
		ans = min(ans, sum - a[i] * 2);
		if(cnt[a[i]] >= 3) ans = min(ans, sum - a[i] * 3);
	}

	printf("%d\n", ans);

	return 0;
}
