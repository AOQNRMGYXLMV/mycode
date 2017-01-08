#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long LL;

LL dfs(int n, LL x, int flag) {
	if(!x) return 0;
	if(n == 1) return 1 - flag;
	LL t = (1LL << (n - 1)) - 1;
	if(x < t) return dfs(n - 1, x, 0);
	if(x == t) return (1LL << (n - 2));
	if(x == t + 1) return (1LL << (n - 2)) + 1 - flag;
	return (1LL << (n - 2)) + 1 - flag + dfs(n - 1, x - t - 1, 1);
}

int main()
{
	int T; scanf("%d", &T);
	while(T--) {
		LL l, r;
		scanf("%lld%lld", &l, &r);
		printf("%lld\n", dfs(63, r, 0) - dfs(63, l-1, 0));
	}

	return 0;
}
