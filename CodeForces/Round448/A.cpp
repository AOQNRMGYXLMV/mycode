#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <iostream>
#include <cmath>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
#define PB push_back
#define PII pair<int, int>
#define REP(i, a, b) for(int i = a; i < b; i++)
#define PER(i, a, b) for(int i = b - 1; i >= a; i--)
#define ALL(x) x.begin(), x.end()
template <class TH> void _dbg(const char *sdbg, TH h){cerr << sdbg << "=" << h << "\n";}
template <class TH, class ...TA> void _dbg(const char *sdbg, TH h, TA... a){
				while (*sdbg != ',') cerr << *sdbg++; cerr << "=" << h << ","; _dbg(sdbg + 1, a...);
}
#define eput(...) _dbg(#__VA_ARGS__, __VA_ARGS__)

const int maxn = 361;

int a[maxn];

int main() {
	int n; scanf("%d", &n);
	REP(i, 1, n + 1) scanf("%d", a + i);
	REP(i, 2, n + 1) a[i] += a[i-1];
	int ans = 360;
	REP(i, 1, n + 1) REP(j, i, n + 1) {
		ans = min(ans, abs(360-(a[j]-a[i-1])*2));
	}
	printf("%d\n", ans);

	return 0;
}
