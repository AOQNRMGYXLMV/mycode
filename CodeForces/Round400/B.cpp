#include <cstdio>
#include <cstring>
#include <algorithm>

const int maxn = 100000 + 10;

bool vis[maxn];

void pre() {
	for(int i = 2; i < maxn; i++) if(!vis[i]) {
		for(long long j = (long long)i * i; j < maxn; j += i)
			vis[j] = true;
	}
}

int main()
{
	pre();
	int n; scanf("%d", &n);
	printf("%d\n", n > 2 ? 2 : 1);
	for(int i = 2; i <= n + 1; i++) {
		if(!vis[i]) printf("1 ");
		else printf("2 ");
	}
	printf("\n");

	return 0;
}
