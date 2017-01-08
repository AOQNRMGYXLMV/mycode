#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#define MP make_pair
using namespace std;

typedef long long LL;
typedef pair<LL, LL> PII;
PII ans;

LL inline pow3(LL x) { return x * x * x; }

void rec(LL m, LL d, LL sum) {
	if(m <= 7) {
		ans = max(ans, MP(d + m, sum + m));
		return;
	}
	LL x = 1;
	while(pow3(x + 1) <= m) x++;
	rec(m - pow3(x), d + 1, sum + pow3(x));
	if(x > 1)
		rec(pow3(x) - 1 - pow3(x - 1), d + 1, sum + pow3(x - 1));
}

int main()
{
	LL m; scanf("%lld", &m);
	rec(m, 0, 0);
	printf("%lld %lld\n", ans.first, ans.second);

	return 0;
}
