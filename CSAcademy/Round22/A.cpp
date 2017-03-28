#include <cstdio>
#include <algorithm>

const int maxn = 100 + 10;

int a[maxn];

int main() {
	int n; scanf("%d", &n);
	for(int i = 0; i < n; i++) scanf("%d", a + i);
	std::sort(a, a + n);

	int ans = 0;
	for(int i = 0; i < n; i++) {
		for(int j = i + 1; j < n; j++) {
			for(int k = j + 1; k < n; k++) {
				if(a[i] + a[j] > a[k]) ans++;
			}
		}
	}

	printf("%d\n", ans);

	return 0;
}
