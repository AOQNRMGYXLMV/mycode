#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
#define PB push_back
#define PII pair<int, int>
#define REP(i, a, b) for(int i = a; i < b; i++)
#define PER(i, a, b) for(int i = b - 1; i >= a; i--)
#define ALL(x) x.begin(), x.end()

int main() {
	LL n, k;
	scanf("%lld%lld", &n, &k);

	if(k == 1) { printf("%lld\n", n); return 0; }

	int cnt = 0;
	LL ans = 1LL;
	while(n) {
		n >>= 1;
		cnt++;
		ans <<= 1;
	}

	printf("%lld\n", ans - 1);

	return 0;
}

