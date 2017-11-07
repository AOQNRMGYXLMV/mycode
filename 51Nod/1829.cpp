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

const LL MOD = 1000000007LL;
const int maxn = 1000000 + 10;

int n, m;

LL mul(LL a, LL b) { return a * b % MOD; }
void add(LL& a, LL b) { a += b; if(a >= MOD) a-= MOD; }
void sub(LL& a, LL b) { if(b) add(a, MOD - b); }

LL pow_mod(LL a, int p) {
	LL ans = 1;
	while(p) {
		if(p & 1) ans = ans * a % MOD;
		a = a * a % MOD;
		p >>= 1;
	}
	return ans;
}

LL fac[maxn], inv[maxn];

LL C(int n, int k) {
	return mul(mul(fac[n], inv[k]), inv[n-k]);
}

int main() {
	scanf("%d%d", &n, &m);
	if(n < m) { printf("0\n"); return 0; }

	fac[0] = 1;
	REP(i, 1, m + 1) fac[i] = mul(fac[i-1], i);
	inv[m] = pow_mod(fac[m], MOD - 2);
	PER(i, 0, m) inv[i] = mul(inv[i+1], i+1);

	LL ans = 0;
	REP(i, 0, m + 1) {
		LL t = mul(C(m, i), pow_mod(m - i, n));
		if(i & 1) sub(ans, t);
		else add(ans, t);
	}

	printf("%lld\n", ans);

	return 0;
}

