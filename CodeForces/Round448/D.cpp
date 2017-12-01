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

const int maxn = 1000000 + 10;
const LL MOD = 1000000007;

LL mul(LL a, LL b) { return a * b % MOD; }
void add(LL& a, LL b) { a += b; if(a >= MOD) a -= MOD; }
LL sub(LL a, LL b) { a -= b; if(a < 0) a += MOD; return a; }

char s1[maxn], s2[maxn];
int n, cnt[26];
LL fac[maxn], ifac[maxn];

LL pow_mod(LL a, LL p) {
	LL ans = 1;
	while(p) {
		if(p & 1) ans = mul(ans, a);
		a = mul(a, a);
		p >>= 1;
	}
	return ans;
}

void preprocess() {
	fac[0] = ifac[0] = 1;
	REP(i, 1, maxn) fac[i] = mul(i, fac[i - 1]);
	ifac[maxn-1] = pow_mod(fac[maxn-1], MOD - 2);
	PER(i, 1, maxn) ifac[i-1] = mul(ifac[i], i);
}

LL C(int n, int k) {
	return mul(mul(fac[n], ifac[k]), ifac[n-k]);
}

LL calc(char* s) {
	int t[26];
	memcpy(t, cnt, sizeof(cnt));
	LL ans = 0;
	REP(i, 0, n) {
		int c = s[i] - 'a';
		LL prod = fac[n-i-1];
		REP(j, 0, 26) if(t[j]) prod = mul(prod, ifac[t[j]]);
		REP(j, 0, c) if(t[j]) {
			add(ans, mul(prod, t[j]));
		}
		if(t[c]) t[c]--;
		else return ans;
	}
	return ans;
}

int main() {
	preprocess();
	scanf("%s%s", s1, s2);
	n = strlen(s1);
	REP(i, 0, n) cnt[s1[i]-'a']++;
	LL ans = sub(calc(s2), calc(s1));
	add(ans, MOD - 1);
	printf("%lld\n", ans);

	return 0;
}

