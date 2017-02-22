#include <cstdio>

int sg[61];

int main()
{
	for(int i = 1, p = 1; p <= 60; i++) {
		for(int j = 0; j < i + 1 && p <= 60; j++) {
			sg[p++] = i;
		}
	}

	int ans = 0;
	int n; scanf("%d", &n);
	while(n--) { int x; scanf("%d", &x); ans ^= sg[x]; }
	if(ans) printf("NO\n"); else printf("YES\n");

	return 0;
}
