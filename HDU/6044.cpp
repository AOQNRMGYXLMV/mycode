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

namespace IO {
	#define BUF_SIZE 500000

	bool inline nc(char& c) {
		static char buf[BUF_SIZE], *p = buf + BUF_SIZE, *pend = buf + BUF_SIZE;
		if(p == pend) {
			p = buf;
			pend = buf + fread(buf, 1, BUF_SIZE, stdin);
			if(pend == buf) { c = ' '; return false; }
		}
		c = *p++;
		return true;
	}

	bool read(int& x) {
		char c = ' ';
		x = 0;
		while(c < '0' || c > '9') if(!nc(c)) return false;
		while('0' <= c && c <= '9') { x = (x<<1)+(x<<3)+c-'0'; nc(c); }
		return true;
	}

	#undef BUF_SIZE
};

using namespace IO;

const int maxn = 1000000 + 10;
const LL MOD = 1000000007LL;
LL mul(LL a, LL b) { return a * b % MOD; }

LL fac[maxn], inv[maxn];
LL pow_mod(LL a, LL p) {
	LL ans = 1;
	while(p) {
		if(p & 1) ans = ans * a % MOD;
		a = a * a % MOD;
		p >>= 1;
	}
	return ans;
}

void preprocess() {
	fac[0] = 1;
	REP(i, 1, maxn) fac[i] = mul(fac[i - 1], (LL)i);
	inv[maxn-1] = pow_mod(fac[maxn-1], MOD - 2);
	PER(i, 0, maxn-1) inv[i] = mul(inv[i+1], (LL)(i+1));
}

LL C(LL n, LL k) {
	if(k > n) return 0;
	return mul(mul(fac[n], inv[k]), inv[n-k]);
}

int n, L[maxn], R[maxn], id[maxn];

bool cmp(int i, int j) {
	return L[i] < L[j] || (L[i] == L[j] && R[i] > R[j]);
}

int q;
bool ok;
LL dfs(int l, int r) {
	if(!ok) return 0;
	if(l > r) return 1;
	int i = id[++q];
	if(l != L[i] || r != R[i]) { ok = false; return 0; }
	LL ans = mul(C(R[i]-L[i], i-L[i]), dfs(L[i], i-1));
	return mul(ans, dfs(i+1, R[i]));
}

int main() {
	preprocess();

	int _ = 1;
	while(read(n)) {
		printf("Case #%d: ", _++);
		REP(i, 1, n + 1) read(L[i]);
		REP(i, 1, n + 1) { read(R[i]); id[i] = i; }
		sort(id + 1, id + 1 + n, cmp);
		ok = true;
		q = 0;
		printf("%lld\n", dfs(1, n));
	}

	return 0;
}

