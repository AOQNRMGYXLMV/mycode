#include <cstdio>
#include <algorithm>
using std::swap;
typedef long long LL;
const int maxn = 0;

int a[3];

int main()
{
	LL n; int x;
	scanf("%lld%d", &n, &x);
	n %= 6;
	a[x] = 1;
	for(int i = n - 1; i >= 0; i--) {
		if(i & 1) { swap(a[1], a[2]); }
		else swap(a[0], a[1]);
	}

	for(int i = 0; i < 3; i++) {
		if(a[i]) {
			printf("%d\n", i);
			break;
		}
	}

	return 0;
}
