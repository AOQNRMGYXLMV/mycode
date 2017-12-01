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

const int maxn = 71;
const LL MOD = 1000000007LL;
LL mul(LL a, LL b) { return a * b % MOD; }
void add(LL& a, LL b) { a += b; if(a >= MOD) a -= MOD; }

LL dp[2][1<<19];
int mask[maxn], cnt[maxn];
bool vis[maxn];
int ptot, prime[20];

LL pow_mod(LL a, LL p) {
	LL ans = 1;
	while(p) {
		if(p & 1) ans = mul(ans, a);
		a = mul(a, a);
		p >>= 1;
	}
	return ans;
}

int main() {
	REP(i, 2, maxn) {
		if(!vis[i]) prime[ptot++] = i;
		REP(j, 0, ptot) {
				if(prime[j] * i >= maxn) break;
			vis[prime[j] * i] = true;
			if(i % prime[j] == 0) break;
		}
	}

	REP(x, 2, maxn) {
		for(int j = 0; j < ptot && x; j++) if(x % prime[j] == 0) {
			int t = x;
			while(t % prime[j] == 0) {
				mask[x] ^= (1 << j);
				t /= prime[j];
			}
		}
	}

	int n; scanf("%d", &n);
	while(n--) {
		int x; scanf("%d", &x);
		cnt[x]++;
	}
	dp[0][0] = 1;
	int cur = 0;
	REP(i, 1, maxn) if(cnt[i]) {
		cur ^= 1;
		memcpy(dp[cur], dp[cur^1], sizeof(dp[0]));
		LL p = pow_mod(2, cnt[i]-1);
		REP(j, 0, 1<<19) {
			add(dp[cur][j], mul(dp[cur^1][j], p-1));
			add(dp[cur][j], mul(dp[cur^1][j^mask[i]], p));
		}
	}

	printf("%lld\n", (dp[cur][0] + MOD - 1) % MOD);

	return 0;
}

