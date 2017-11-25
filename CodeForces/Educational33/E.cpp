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

const int maxn = 1000000 + 30;
const LL MOD = 1000000007LL;
bool vis[maxn];
int pcnt, prime[80000];

LL mul(LL a, LL b) { return a * b % MOD; }
LL fac[maxn], inv[maxn];

LL pow_mod(LL a, int p) {
	LL ans = 1;
	while(p) {
		if(p & 1) ans = mul(ans, a);
		a = mul(a, a);
		p >>= 1;
	}
	return ans;
}

LL C(int n, int k) {
	return mul(mul(fac[n], inv[k]), inv[n-k]);
}

void preprocess() {
	fac[0] = 1;
	REP(i, 1, maxn) fac[i] = mul(fac[i-1], i);
	inv[maxn-1] = pow_mod(fac[maxn-1], MOD-2);
	PER(i, 1, maxn) inv[i-1] = mul(inv[i], i);

	REP(i, 2, maxn) {
		if(!vis[i]) prime[pcnt++] = i;
		REP(j, 0, pcnt) {
			if((LL)i * prime[j] >= maxn) break;
			vis[i * prime[j]] = true;
			if(i % prime[j] == 0) break;
		}
	}
}

int main() {
	preprocess();
	int q; scanf("%d", &q);
	while(q--) {
		int x, y; scanf("%d%d", &x, &y);
		LL ans = pow_mod(2, y - 1);
		for(int i = 0; prime[i] * prime[i] <= x; i++) if(x % prime[i] == 0) {
			int cnt;
			for(cnt = 0; x % prime[i] == 0; cnt++, x /= prime[i]);
			ans = mul(ans, C(y+cnt-1, cnt));
		}
		if(x > 1) ans = mul(ans, C(y, 1));
		printf("%lld\n", ans);
	}

	return 0;
}

