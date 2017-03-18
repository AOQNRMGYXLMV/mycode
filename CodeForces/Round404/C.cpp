#include <cstdio>
#include <cstring>
using namespace std;

typedef long long LL;

LL n, m;

bool ok(LL x) {
	x -= m;
	LL t = n - m;

	t <<= 1;
	t /= x;
	t /= x + 1;

	if(t > 1) return false;
	if(!t) return true;
	return n - m == x * (x + 1) / 2;
}

int main()
{
	scanf("%lld%lld", &n, &m);
	if(n <= m) {
		printf("%lld\n", n);
		return 0;
	}

	LL L = m + 1, R = n;
	while(L < R) {
		LL M = (L + R) / 2;
		if(ok(M)) R = M;
		else L = M + 1;
	}

	printf("%lld\n", L);

	return 0;
}
