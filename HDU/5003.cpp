#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int a[55];

int main()
{
	int T; scanf("%d", &T);
	while(T--) {
		int n; scanf("%d", &n);
		for(int i = 0; i < n; i++) scanf("%d", a + i);
		sort(a, a + n);
		double ans = 0, pow = 1;
		for(int i = n - 1; i >= 0; i--) {
			ans += pow * a[i];
			pow *= 0.95;
		}
		printf("%.10f\n", ans);
	}

	return 0;
}
