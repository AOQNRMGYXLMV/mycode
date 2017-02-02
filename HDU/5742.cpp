#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 100 + 10;

int n, m, a[maxn];

int gcd(int a, int b) { return !b ? a : gcd(b, a%b); }

int main()
{
	int T; scanf("%d", &T);
	while(T--) {
		memset(a, -1, sizeof(a));
		scanf("%d%d", &n, &m);
		while(m--) {
			int x, y; scanf("%d%d", &x, &y);
			a[x] = y;
		}
		int sum = 0;
		if(a[1] == -1) a[1] = 100;
		if(a[2] == -1) a[2] = a[1];
		a[n + 1] = 0;
		for(int i = n + 1, j; i > 2; i = j) {
			for(j = i - 1; j > 2 && a[j] == -1; j--) a[j] = a[i];
		}
		for(int i = 1; i <= n; i++) sum += a[i];

		int x = a[1] + a[2];
		int g = gcd(x, sum);
		printf("%d/%d\n", x / g, sum / g);
	}

	return 0;
}
