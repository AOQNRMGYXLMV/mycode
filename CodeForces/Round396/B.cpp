#include <cstdio>
#include <algorithm>

const int maxn = 100000 + 10;

int a[maxn];

int main()
{
	int n; scanf("%d", &n);
	for(int i = 0; i < n; i++) scanf("%d", a + i);
	std::sort(a, a + n);

	bool ok = false;
	for(int i = 0; i + 2 < n; i++) {
		if(a[i] > a[i + 2] - a[i + 1]) {
			ok = true;
			break;
		}
	}

	if(ok) printf("YES\n");
	else printf("NO\n");

	return 0;
}
