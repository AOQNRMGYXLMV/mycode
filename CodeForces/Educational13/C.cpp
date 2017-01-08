#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long LL;

LL gcd(LL a, LL b) { return !b ? a : gcd(b, a%b); }

LL LCM(LL a, LL b) { return a / gcd(a, b) * b; }

int main()
{
	LL n, a, b, p, q;
	scanf("%lld%lld%lld%lld%lld", &n, &a, &b, &p, &q);
	if(p > q) { swap(a, b); swap(p, q); }
	LL lcm = LCM(a, b);
	LL ans = n / a * p;
	ans -= n / lcm * p;
	ans += n / b * q;
	printf("%lld\n", ans);

	return 0;
}
