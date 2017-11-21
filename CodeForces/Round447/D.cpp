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
#define PB push_back

const int maxn = 1000000 + 10;

int n, m;
vector<int> dist[maxn];
vector<LL> pre[maxn];
int L[maxn], sz[maxn];

int main() {
	scanf("%d%d", &n, &m);
	REP(i, 1, n) scanf("%d", L + i + 1);
	PER(i, 1, n + 1) {
		sz[i] = 1;
		dist[i].PB(0);
		int lch = i << 1, rch = i<<1|1;
		if((lch) <= n) sz[i] += sz[lch]; else continue;
		if((rch) <= n) {
			sz[i] += sz[rch];
		}
		else {
			REP(p, 0, sz[lch]) dist[i].PB(dist[lch][p] + L[lch]);
			continue;
		}
		int p = 0, q = 0, t = 0;
		while(p < sz[lch] && q < sz[rch]) {
			int dl = dist[lch][p] + L[lch], dr = dist[rch][q] + L[rch];
			if(dl < dr) { dist[i].PB(dl); p++; }
			else { dist[i].PB(dr); q++; }
		}
		while(p < sz[lch]) dist[i].PB(dist[lch][p++] + L[lch]);
		while(q < sz[rch]) dist[i].PB(dist[rch][q++] + L[rch]);
	}

	REP(i, 1, n + 1) {
		pre[i].push_back(dist[i][0]);
		REP(j, 1, sz[i]) pre[i].PB(pre[i][j-1] + dist[i][j]);
	}

	while(m--) {
		int u, h; scanf("%d%d", &u, &h);
		LL ans = 0;
		int cnt = upper_bound(ALL(dist[u]), h) - dist[u].begin();
		if(cnt) ans += (LL)h * cnt - pre[u][cnt-1];
		int sum = 0;
		while(u != 1) {
			sum += L[u];
			if(sum >= h) break;
			else ans += h - sum;
			int cnt = upper_bound(ALL(dist[u^1]), h-sum-L[u^1]) - dist[u^1].begin();
			if(cnt) ans += (LL)(h-sum-L[u^1])*cnt - pre[u^1][cnt-1];
			u >>= 1;
		}
		printf("%lld\n", ans);
	}

	return 0;
}

