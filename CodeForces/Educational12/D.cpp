#include <cstdio>
#include <cstring>
#include <algorithm>

const int maxn = 2000000;

bool vis[maxn + 10];

void pre() {
	memset(vis, false, sizeof(vis));
	for(long long i = 2; i <= maxn; i++) if(!vis[i])
		for(long long j = i * i; j <= maxn; j += i) vis[j] = true;
}

int a[1010];

int main()
{
	pre();
	
	int n; scanf("%d", &n);
	int cnt = 0;
	for(int i = 0; i < n; i++) {
		scanf("%d", a + i);
		if(a[i] == 1) cnt++;
	}

	//not choose 1
	int ans1 = 1, x = a[0], y;
	bool flag = true;
	for(int i = 0; i < n && flag; i++) {
		for(int j = i + 1; j < n; j++) {
			if(!vis[a[i] + a[j]]) {
				ans1 = 2; x = a[i]; y = a[j]; flag = false;
				break;
			}
		}
	}

	//choose 1
	int ans2 = cnt, z;
	if(cnt) {
		for(int i = 0; i < n; i++) if(a[i] != 1 && !vis[a[i] + 1]) {
			z = a[i];
			ans2++;
			break;
		}
	}

	if(ans1 > ans2) {
		if(ans1 == 1) printf("1\n%d\n", x);
		else printf("2\n%d %d\n", x, y);
	} else {
		printf("%d\n", ans2);
		printf("1");
		for(int i = 1; i < cnt; i++) printf(" 1");
		if(ans2 > cnt) printf(" %d", z);
		printf("\n");
	}

	return 0;
}
