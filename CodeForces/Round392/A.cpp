#include <cstdio>

int a[100];

int main()
{
	int n; scanf("%d", &n);
	int max = 0;
	for(int i = 0; i < n; i++) {
		scanf("%d", a + i);
		if(a[i] > max) max = a[i];
	}

	int ans = 0;
	for(int i = 0; i < n; i++)
		ans += max - a[i];

	printf("%d\n", ans);

	return 0;
}
