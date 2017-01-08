#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long LL;
const LL MOD = 1000000007LL;
const int maxn = 1000 + 10;

LL mul(LL a, LL b) { return a * b % MOD; }

void add(LL& a, LL b) { a += b; if(a >= MOD) a -= MOD; }

LL pow_mod(LL a, int p) {
	LL ans = 1;
	while(p) {
		if(p & 1) ans = mul(ans, a);
		a = mul(a, a);
		p >>= 1;
	}
	return ans;
}

LL fac[maxn], inv[maxn];

void preprocess() {
	fac[0] = 1;
	for(int i = 1; i < maxn; i++) fac[i] = mul(fac[i - 1], i);
	inv[maxn - 1] = pow_mod(fac[maxn - 1], MOD - 2);
	for(int i = maxn - 2; i >= 0; i--)
		inv[i] = mul(inv[i + 1], i + 1);
}

LL C(int n, int k) { return mul(mul(fac[n], inv[k]), inv[n - k]); }

int n, cnt[26];
char s[maxn];

int main()
{
	preprocess();

	int T; scanf("%d", &T);
	while(T--) {
		scanf("%s", s);
		n = strlen(s);
		memset(cnt, 0, sizeof(cnt));
		for(int i = 0; i < n; i++) cnt[s[i] - 'a']++;
		int odd_num = 0;
		for(int i = 0; i < 26; i++)
			if(cnt[i] & 1) odd_num++;
		if(odd_num > 1) { puts("0"); continue; }
		int tot = 0;
		for(int i = 0; i < 26; i++) { cnt[i] >>= 1; tot += cnt[i]; }
		LL ans = fac[tot];
		for(int i = 0; i < 26; i++) if(cnt[i]) ans = mul(ans, inv[cnt[i]]);
		
		printf("%lld\n", ans);
	}

	return 0;
}
