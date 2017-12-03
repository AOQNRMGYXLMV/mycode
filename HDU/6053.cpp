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

//#define LOCAL

const int maxn = 100000 + 10;
const LL MOD = 1000000007LL;

int n, pre[maxn << 1];

LL mul(LL a, LL b) { return a * b % MOD; }
void add(LL& a, LL b) { a += b; if(a >= MOD) a -= MOD; }
LL pow_mod(LL a, LL p) {
	LL ans = 1;
	while(p) {
		if(p & 1) ans = ans * a % MOD;
		a = a * a % MOD;
		p >>= 1;
	}
	return ans;
}

bool vis[maxn];
int u[maxn], prime[maxn], pcnt;
void preprocess() {
	u[1] = 1;
	REP(i, 2, maxn) {
		if(!vis[i]) { prime[pcnt++] = i; u[i] = -1; }
		REP(j, 0, pcnt) {
			int mul = i * prime[j];
			if(mul >= maxn) break;
			vis[mul] = true;
			if(i % prime[j] == 0) {
				u[mul] = 0;
				break;
			}
			u[mul] = -u[i];
		}
	}

#ifdef LOCAL
	REP(i, 1, 11) printf("u[%d] = %d\n", i, u[i]);
#endif
}

int main() {
	preprocess();
	int T; scanf("%d", &T);
	REP(_, 1, T + 1) {
		printf("Case #%d: ", _);
		memset(pre, 0, sizeof(pre));
		scanf("%d", &n);
		int mina = maxn, maxa = 1;
		REP(i, 0, n) {
			int x;
			scanf("%d", &x);
			if(x > maxa) maxa = x;
			if(x < mina) mina = x;
			pre[x]++;
		}
		REP(i, 1, maxn*2) pre[i] += pre[i - 1];

		LL ans = 0;
		REP(d, 2, mina + 1) {
			if(!u[d]) continue;
			LL prod = 1;
			for(int i = 1; i * d <= maxa; i++) {
				int s = i * d;
				int cnt = pre[s + d - 1] - pre[s - 1];
				prod = mul(prod, pow_mod(i, cnt));
			}
			if(u[d] == -1) add(ans, prod);
			else {
				if(prod) prod = MOD - prod;
				add(ans, prod);
			}
		}

		printf("%lld\n", ans);
	}

	return 0;
}

