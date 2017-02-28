#include <cstdio>

int a[6], b[6];

int main()
{
	int n; scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		int x; scanf("%d", &x);
		a[x]++;
	}
	for(int i = 0; i < n; i++) {
		int x; scanf("%d", &x);
		b[x]++;
	}

	int ans = 0;
	for(int i = 1; i <= 5; i++) {
		int t = a[i] + b[i];
		if(t & 1) { printf("-1\n"); return 0; }
		if(a[i] > t / 2) ans += a[i] - t / 2;
	}

	printf("%d\n", ans);

	return 0;
}
