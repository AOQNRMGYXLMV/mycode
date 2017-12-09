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

const int maxn = 200 + 10;
const int maxm = 50000 + 10;
const LL INF = 1LL << 62;

int u[maxm], v[maxm], g[maxm], s[maxm], r[maxm];

int n, m;
LL G, S;
int pa[maxn], cc;
void init() { REP(i, 1, n + 1) pa[i] = i; cc = n; }
int findset(int x) { return x == pa[x] ? x : pa[x] = findset(pa[x]); }

int a[maxn], cnt;

int main() {
	scanf("%d%d%lld%lld", &n, &m, &G, &S);
	REP(i, 0, m) {
		scanf("%d%d%d%d", u + i, v + i, g + i, s + i);
		r[i] = i;
	}
	sort(r, r + m, [](const int& i, const int& j){ return g[i] < g[j]; });

	LL ans = INF;
	REP(i, 0, m) {
		a[cnt++] = r[i];
		PER(j, 0, cnt - 1) if(s[a[j]] > s[a[j+1]]) swap(a[j], a[j+1]);
		int t = 0;
		init();
		REP(j, 0, cnt) {
			int x = findset(u[a[j]]), y = findset(v[a[j]]);
			if(x != y) {
				pa[y] = x;
				cc--;
				a[t++] = a[j];
			}
			if(cc == 1) break;
		}
		cnt = t;
		if(cc == 1) ans = min(ans, G * g[r[i]] + S * s[a[cnt-1]]);
	}
	printf("%lld\n", ans == INF ? -1 : ans);

	return 0;
}

