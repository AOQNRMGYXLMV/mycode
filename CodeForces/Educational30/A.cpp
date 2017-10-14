#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 110;

int a[maxn];

int main() {
	int n, k, x; scanf("%d%d%d", &n, &k, &x);
	int tot = 0;
	for(int i = 0; i < n; i++) {
		scanf("%d", a + i);
		tot += a[i];
	}

	for(int i = n - 1; i >= n - k; i--) {
		if(a[i] > x) tot -= a[i] - x;
		else break;
	}

	printf("%d\n", tot);

	return 0;
}
