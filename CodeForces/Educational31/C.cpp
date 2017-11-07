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

const int maxn = 100000 + 10;

int n, p[maxn];
bool vis[maxn];

int main() {
	scanf("%d", &n);
	REP(i, 1, n + 1) scanf("%d", p + i);
	int max1 = 0, max2 = 0;
	LL ans = 0;
	REP(i, 1, n + 1) if(!vis[i]) {
		int len = 0;
		int x = i;
		while(!vis[x]) {
			vis[x] = true;
			x = p[x];
			len++;
		}
		if(len > max1) {
			max2 = max1;
			max1 = len;
		} else if(len > max2) max2 = len;
		ans += (LL)len * len;
	}

	ans -= (LL)max1 * max1;
	ans -= (LL)max2 * max2;
	LL l = max1 + max2;
	ans += l * l;
	printf("%lld\n", ans);

	return 0;
}

