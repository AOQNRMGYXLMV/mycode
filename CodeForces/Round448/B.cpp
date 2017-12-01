#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <iostream>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
#define PB push_back
#define PII pair<int, int>
#define REP(i, a, b) for(int i = a; i < b; i++)
#define PER(i, a, b) for(int i = b - 1; i >= a; i--)
#define ALL(x) x.begin(), x.end()

template <class TH>
void _dbg(const char *sdbg, TH h){
	cerr << sdbg << "=" << h << "\n";
}
template <class TH, class ...TA>
void _dbg(const char *sdbg, TH h, TA... a) {
	while (*sdbg != ',') cerr << *sdbg++;
	cerr << "=" << h << ",";
	_dbg(sdbg + 1, a...);
}
#define eput(...) _dbg(#__VA_ARGS__, __VA_ARGS__)

const int maxn = 100000 + 10;

int n, k, x;
LL a[maxn];

LL calc(int i, int j) {
	return (a[j] / x) - ((a[i]-1) / x);
}

int main() {
	scanf("%d%d%d", &n, &x, &k);
	REP(i, 0, n) scanf("%lld", a + i);
	sort(a, a + n);
	
	int lr = 0, rr = 0;
	LL ans = 0;
	REP(l, 0, n) {
		while(lr < n && a[lr] < a[l]) lr++;
		while(rr < n && a[rr] < a[l]) rr++;
		while(lr < n && calc(l, lr) < k) lr++;
		while(rr < n && calc(l, rr) <= k) rr++;
		ans += rr - lr;
	}
	printf("%lld\n", ans);

	return 0;
}

