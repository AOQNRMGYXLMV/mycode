#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
#define REP(i, a, b) for(int i = a; i < b; i++)
#define PER(i, a, b) for(int i = b - 1; i >= a; i--)
#define ALL(x) x.begin(), x.end()

const LL MOD = 1000000007LL;

int main() {
	LL n, m; int k;
	scanf("%lld%lld%d", &n, &m, &k);

	if(k == -1 && ((n ^ m) & 1)) { printf("0\n"); return 0; }

	LL ans = 1, a = 2;
	n--; m--;
	LL p = (n % (MOD - 1)) * (m % (MOD - 1)) % (MOD - 1);
	while(p) {
		if(p & 1) ans = ans * a % MOD;
		a = a * a % MOD;
		p >>= 1;
	}

	printf("%lld\n", ans);

	return 0;
}

