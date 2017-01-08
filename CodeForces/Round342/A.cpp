#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long LL;

int main()
{
	LL n, a, b, c;
	scanf("%lld%lld%lld%lld", &n, &a, &b, &c);
	if(a <= b - c) printf("%lld\n", n / a);
	else {
		LL ans = 0;
		if(n >= b) ans = (n - c) / (b - c);
		n -= ans * (b - c);
		ans += n / a;
		printf("%lld\n", ans);
	}

	return 0;
}