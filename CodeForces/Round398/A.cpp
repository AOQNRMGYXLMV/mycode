#include <cstdio>

const int maxn = 100000 + 10;

bool arrive[maxn];

int main()
{
	int n; scanf("%d", &n);
	int p = n;
	for(int i = 0; i < n; i++) {
		int x; scanf("%d", &x);
		arrive[x] = true;
		while(p && arrive[p]) {
			printf("%d ", p--);
		}
		printf("\n");
	}

	return 0;
}
