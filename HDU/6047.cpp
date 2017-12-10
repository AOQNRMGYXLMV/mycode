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

const int maxn = 250000 + 10;
const LL MOD = 1000000007LL;
int a[maxn], b[maxn], suf[maxn];

int main() {
	int n;
	while(scanf("%d", &n) == 1) {
		REP(i, 0, n) {
			scanf("%d", a + i);
			a[i] -= i + 1;
		}
		REP(i, 0, n) scanf("%d", b + i);
		PER(i, 1, n) if(b[i] < b[i-1]) swap(b[i], b[i-1]);
		suf[n-1] = a[n-1];
		PER(i, 0, n-1) suf[i] = max(suf[i+1], a[i]);

		LL ans = suf[b[0]-1]; int t = suf[b[0]-1]-n-1;
		REP(i, 1, n) {
			ans += max(suf[b[i]-1], t);
			if(ans >= MOD) ans -= MOD;
		}
		printf("%lld\n", ans);

	}

	return 0;
}

