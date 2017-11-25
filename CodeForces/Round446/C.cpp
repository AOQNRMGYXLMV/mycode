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

int gcd(int a, int b) { return !b ? a : gcd(b, a%b); }

const int maxn = 2005;

int a[maxn], g[maxn];

int main() {
	int n; scanf("%d", &n);
	int minl = -1;
	REP(i, 0, n) scanf("%d", a + i);

	REP(l, 1, n + 1) {
		REP(i, 0, n - l + 1) {
			g[i] = gcd(g[i], a[i+l-1]);
			if(g[i] == 1) { minl = l; break; }
		}
		if(~minl) break;
	}
	if(~minl) {
		if(minl == 1) {
			int ans = n;
			REP(i, 0, n) if(a[i] == 1) ans--;
			printf("%d\n", ans);
		} else {
			printf("%d\n", minl + n - 2);
		}
	} else printf("-1\n");

	return 0;
}

