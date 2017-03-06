#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long LL;

int prime[] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43 };

LL n;
LL ans, k;

void dfs(int i, LL now, LL cnt, int last) {
	if(cnt > ans || (cnt == ans && now < k)) ans = cnt, k = now;
	now *= prime[i];
	for(int j = 1; j <= last && now <= n; j++) {
		dfs(i + 1, now, cnt * (j + 1), j);
		now *= prime[i];
	}
}

int main()
{
	scanf("%lld", &n);
	dfs(0, 1, 1, 100);
	printf("%lld\n", k);

	return 0;
}
