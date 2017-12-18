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

const LL MOD = 1000000007LL;
LL mul(LL a, LL b) { return a * b % MOD; }
LL add(LL a, LL b) {
	LL ans = a + b;
	if(ans >= MOD) ans -= MOD;
	return ans;
}

int n;
char s[maxn];

LL suf[maxn], inv[maxn];

LL pow_mod(LL a, LL p) {
	LL ans = 1;
	while(p) {
		if(p & 1) ans = ans * a % MOD;
		a = a * a % MOD;
		p >>= 1;
	}
	return ans;
}

LL hash(int l, int r) {
	r = l + r - 1;
	LL ans = suf[l] - suf[r + 1];
	if(ans < 0) ans += MOD;
	return mul(ans, inv[n - r]);
}

bool check(int l, int len) {
	if((len < 1) || (len > 1 && s[l] == '0')) return false;
	return true;
}

void print(int l1, int l2) {
	REP(i, 1, l1 + 1) putchar(s[i]);
	putchar('+');
	REP(i, l1 + 1, l1 + l2 + 1) putchar(s[i]);
	putchar('=');
	REP(i, l1 + l2 + 1, n + 1) putchar(s[i]);
	putchar('\n');
}

int main() {
	scanf("%s", s + 1);
	n = strlen(s + 1);
	inv[0] = 1;
	LL inv_ten = pow_mod(10LL, MOD - 2);
	LL p = 1;
	PER(i, 1, n + 1) {
		suf[i] = add(suf[i+1], mul((LL)(s[i]-'0'), p));
		p = mul(p, 10LL);
	}
	REP(i, 1, n + 1) inv[i] = mul(inv[i-1], inv_ten);
	
	REP(l3, 1, n / 2 + 1) {
		if(!check(n-l3+1, l3)) continue;
		int l1, l2;
		for(l1 = l3 - 1; l1 <= l3; l1++) {
			l2 = n - l3 - l1;
			if(l2 > l3) continue;
			if(!check(1, l1) || !check(l1+1, l2)) continue;
			if(add(hash(1, l1), hash(l1+1, l2)) == hash(n-l3+1, l3)) {
				print(l1, l2);
				return 0;
			}
		}
		for(l2 = l3 - 1; l2 <= l3; l2++) {
			l1 = n - l3 - l2;
			if(l1 > l3) continue;
			if(!check(1, l1) || !check(l1+1, l2)) continue;
			if(add(hash(1, l1), hash(l1+1, l2)) == hash(n-l3+1, l3)) {
				print(l1, l2);
				return 0;
			}
		}
	}

	puts("Not find!");

	return 0;
}

