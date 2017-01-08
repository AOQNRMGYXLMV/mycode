#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long LL;
const int maxn = 100000 + 10;

int n;
int a[maxn], b[maxn];

int count(int x) {
	int ans = 0;
	for(; x; x /= 10) ans++;
	return ans;
}

int main()
{
	while(scanf("%d", &n) == 1) {
		int maxL = 0;
		for(int i = 0; i < n; i++) {
			scanf("%d", a + i);
			maxL = max(maxL, count(a[i]));
		}
		LL ans = 0;
		for(int k = 0, pow = 1; k < maxL; k++) {
			pow *= 10;
			for(int i = 0; i < n; i++) b[i] = a[i] % pow;
			sort(b, b + n);
			int j = n;
			for(int i = 0; i < n; i++) {
				while(j && b[i] + b[j - 1] >= pow) j--;
				ans += n - j;
				if(j <= i) ans--;
			}
		}

		ans >>= 1;
		printf("%lld\n", ans);
	}

	return 0;
}
