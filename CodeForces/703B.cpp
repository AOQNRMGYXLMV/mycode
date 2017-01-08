#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 100000 + 10;
typedef long long LL;

int c[maxn];
int a[maxn], sum[maxn];
bool flag[maxn];

int main()
{
	int n, k; scanf("%d%d", &n, &k);
	LL sumc = 0, ans = 0;
	for(int i = 1; i <= n; i++) {
		scanf("%d", c + i);
		sumc += c[i];
	}

	for(int i = 1, id; i <= k; i++) {
		scanf("%d", &id);
		ans += (sumc - c[id]) * c[id];
		a[i] = c[id];
		sum[i] = sum[i - 1] + a[i];
		flag[id - 1] = flag[id] = true;
		if(id == 1) flag[n] = true;
	}

	for(int i = 2; i <= k; i++) ans -= (LL)a[i] * sum[i - 1];
	
	c[n + 1] = c[1];
	for(int i = 1; i <= n; i++) if(!flag[i]) ans += c[i] * c[i + 1];

	printf("%lld\n", ans);

	return 0;
}
