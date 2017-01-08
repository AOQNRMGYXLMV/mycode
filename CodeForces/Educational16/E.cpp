#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 10000000 + 10;
typedef long long LL;

LL d[maxn];

int main()
{
	int n, a, b;
	scanf("%d%d%d", &n, &a, &b);
	d[1] = a;
	for(int i = 2; i <= n; i++) {
		if(i & 1) {
			d[i] = min(d[i-1]+a, min(d[i/2]+a+b, d[i/2+1]+a+b));
		} else {
			d[i] = min(d[i-1]+a, d[i/2]+b);
		}
	}

	printf("%lld\n", d[n]);

	return 0;
}
