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

int pcnt, prime[50000], mu[maxn];
bool vis[maxn];

int n, q;
int a[maxn], cnt[maxn];
bool in[maxn];
vector<int> divisors[maxn];

int main() {
	mu[1] = 1;
	REP(i, 2, maxn) {
		if(!vis[i]) { prime[pcnt++] = i; mu[i] = -1; }
		REP(j, 0, pcnt) {
			LL mul = i * prime[j];
			if(mul >= maxn) break;
			vis[mul] = true;
			if(i % prime[j] == 0) { mu[mul] = 0; break; }
			mu[mul] = -mu[i];
		}
	}

	scanf("%d%d", &n, &q);
	int maxa = 1;
	memset(vis, false, sizeof(vis));
	REP(i, 1, n + 1) {
		scanf("%d", a + i);
		if(maxa < a[i]) maxa = a[i];
		vis[a[i]] = true;
	}
	REP(i, 1, maxa + 1) for(int j = i; j <= maxa; j += i) {
		if(vis[j]) divisors[j].PB(i);
	}

	LL ans = 0;
	while(q--) {
		int x; scanf("%d", &x);
		if(in[x]) {
			for(int d : divisors[a[x]]) {
				cnt[d]--;
				ans -= cnt[d] * mu[d];
			}
			in[x] = false;
		} else {
			for(int d : divisors[a[x]]) {
				ans += cnt[d] * mu[d];
				cnt[d]++;
			}
			in[x] = true;
		}
		printf("%lld\n", ans);
	}

	return 0;
}

