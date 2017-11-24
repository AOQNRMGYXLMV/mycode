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

const int maxn = 100000 + 10;

int pa[maxn], minv[maxn];
int findset(int x) { return x == pa[x] ? x : pa[x] = findset(pa[x]);  }
void Union(int x, int y) {
	int px = findset(x), py = findset(y);
	if(px != py) {
		pa[py] = px;
		minv[px] = min(minv[px], minv[py]);
	}
}

int main() {
	int n, m; scanf("%d%d", &n, &m);
	REP(i, 1, n + 1) {
		pa[i] = i;
		scanf("%d", minv + i);
	}
	
	while(m--) {
		int u, v; scanf("%d%d", &u, &v);
		Union(u, v);
	}

	LL ans = 0;
	REP(i, 1, n + 1) if(findset(i) == i) ans += minv[i];
	printf("%lld\n", ans);

	return 0;
}

