#include <cstdio>
#include <cstring>
#include <map>
#include <cmath>
using namespace std;

typedef long long LL;

map<LL, LL> m;

const int maxn = 100000 + 10;
const LL Max = 100000000000000LL;

LL a[maxn], pre[maxn];
LL p[100];

int main()
{
	int n, k; scanf("%d%d", &n, &k);
	for(int i = 1; i <= n; i++) {
		scanf("%lld", a + i);
		pre[i] = a[i] + pre[i - 1];
	}
	p[0] = 1;
	int limit = 1;
	if(abs(k) != 1) {
		while(abs(p[limit - 1] * k) <= Max) {
			p[limit] = p[limit - 1] * k; limit++;
		}
	} else {
		p[1] = k;
	}

	if(k == 1) limit = 1;
	if(k == -1) limit = 2;

	LL ans = 0;
	m[0] = 1;
	for(int i = 1; i <= n; i++) {
		for(int j = 0; j < limit; j++) {
			if(m.count(pre[i] - p[j]))
				ans += m[pre[i] - p[j]];
		}
		m[pre[i]]++;
	}
	
	printf("%lld\n", ans);

	return 0;
}
