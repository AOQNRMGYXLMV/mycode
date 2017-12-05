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

const int maxn = 500000 + 10;

int n, q;
int a[maxn], cnt[maxn];
bool in[maxn];
vector<int> p[maxn];

bool vis[maxn];
int pcnt, prime[maxn];

void fac(int t) {
	int x = t;
	REP(i, 0, pcnt) {
		if(prime[i] * prime[i] > x) break;
		if(x % prime[i] == 0) {
			p[t].PB(prime[i]);
			while(x % prime[i] == 0) x /= prime[i];
		}
	}
	if(x > 1) p[t].PB(x);
}

LL upd(int x, int v) {
	int sz = p[x].size();
	LL ans = 0;
	REP(S, 0, (1<<sz)) {
		int sign = 1, mul = 1;
		REP(i, 0, sz) if((S>>i)&1) {
			sign = -sign;
			mul *= p[x][i];
		}
		if(v == 1) {
			ans += cnt[mul] * sign;
			cnt[mul]++;
		} else {
			cnt[mul]--;
			ans += cnt[mul] * sign;
		}
	}
	return ans;
}

int main() {
	REP(i, 2, maxn) {
		if(!vis[i]) prime[pcnt++] = i;
		REP(j, 0, pcnt) {
			if((LL)i * prime[j] >= maxn) break;
			vis[i * prime[j]] = true;
			if(i % prime[j] == 0) break;
		}
	}

	scanf("%d%d", &n, &q);
	REP(i, 1, n + 1) scanf("%d", a + i);
	memset(vis, false, sizeof(vis));
	LL ans = 0;
	while(q--) {
		int x; scanf("%d", &x);
		if(!vis[a[x]]) { fac(a[x]); vis[a[x]] = true; }
		if(in[x]) { ans -= upd(a[x], -1); in[x] = false; }
		else { ans += upd(a[x], 1); in[x] = true; }
		printf("%lld\n", ans);
	}

	return 0;
}

