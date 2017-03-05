#include <cstdio>

const int maxn = 100000 + 10;

bool vis[maxn];

int main()
{
	int n; scanf("%d", &n);
	int cnt = 0;
	int ans = 0;
	for(int i = 0; i < n * 2; i++) {
		int x; scanf("%d", &x);
		if(!vis[x]) { cnt++; vis[x] = true; }
		else cnt--;
		if(cnt > ans) ans = cnt;
	}
	printf("%d\n", ans);

	return 0;
}
