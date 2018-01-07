#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
using namespace std;
typedef long long LL;
typedef long double LD;
typedef pair<int, int> PII;
#define PB push_back
#define PII pair<int, int>
#define REP(i, a, b) for(int i = a; i < b; i++)
#define PER(i, a, b) for(int i = b - 1; i >= a; i--)
#define ALL(x) x.begin(), x.end()

const LD INF = 1e18;

int n;
vector<int> p[2];
vector<LL> Set[2];

LL cnt(LL x) {
	int pb = Set[1].size() - 1;
	LL ans = 0;
	for(int pa = 0; pa < Set[0].size() && Set[0][pa] <= x; pa++) {
		while(pb >= 0 && Set[1][pb] > (LD)x / Set[0][pa])
			pb--;
		ans += pb + 1;
	}
	return ans;
}

void dfs(int x, int t, LL cur) {
	if(t >= (int)p[x].size()) {
		Set[x].PB(cur);
		return;
	}
	while(cur <= INF) {
		dfs(x, t + 1, cur);
		if((LD)cur * p[x][t] > INF) break;
		else cur *= p[x][t];
	}
}

int main() {
	scanf("%d", &n);
	REP(i, 0, n) {
		int x; scanf("%d", &x);
		p[i&1].PB(x);
	}

	dfs(0, 0, 1LL);
	dfs(1, 0, 1LL);
	sort(ALL(Set[0]));
	sort(ALL(Set[1]));

	LL k; scanf("%lld", &k);
	LL L = 1, R = INF;
	while(L < R) {
		LL M = (L + R) / 2;
		if(cnt(M) < k) L = M + 1;
		else R = M;
	}

	printf("%lld\n", L);

	return 0;
}

