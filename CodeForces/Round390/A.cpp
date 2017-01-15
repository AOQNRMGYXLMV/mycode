#include <cstdio>

int a[110];

int main()
{
	int n; scanf("%d", &n);
	int sum = 0;
	bool flag = false;
	for(int i = 0; i < n; i++) {
		scanf("%d", a + i);
		sum += a[i];
		if(!flag && a[i]) flag = true;
	}

	if(!flag) { printf("NO\n"); return 0; }

	printf("YES\n");
	if(sum) { printf("1\n1 %d\n", n); return 0; }

	for(int i = 0; i < n; i++) if(a[i]) {
		printf("2\n1 %d\n%d %d\n", i + 1, i + 2, n);
		return 0;
	}

	return 0;
}
