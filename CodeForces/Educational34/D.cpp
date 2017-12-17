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

const int maxn = 200000 + 10;

LL n, a[maxn];

long double pre[maxn];
map<int, int> cnt;

int main() {
	scanf("%d", &n);
	REP(i, 1, n + 1) {
		scanf("%d", a + i);
		pre[i] = pre[i-1] + a[i];
	}
	long double ans = 0;
	REP(i, 1, n + 1) {
		ans += a[i]*(i-1) - pre[i-1];
		REP(d, -1, 2) {
			if(cnt.count(a[i]-d)) {
				ans -= d * cnt[a[i]-d];
			}
		}
		cnt[a[i]]++;
	}

	printf("%.0Lf\n", ans);

	return 0;
}

