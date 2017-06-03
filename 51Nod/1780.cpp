#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <set>
#include <vector>
#include <iostream>
#include <string>
using namespace std;
#define REP(i, a, b) for(int i = a; i < b; i++)
#define PER(i, a, b) for(int i = b - 1; i >= a; i--)
#define SZ(a) ((int)a.size())
#define MP make_pair
#define PB push_back
#define EB emplace_back
#define ALL(a) a.begin(), a.end()
typedef long long LL;
typedef pair<int, int> PII;

const LL MOD = 1000000007LL;
const int maxn = 30000 + 10;
vector<int> a;

LL d[maxn][100][2][2];

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

const int maxf = 300;
LL fac[maxf], inv[maxf];

void preprocess() {
	fac[0] = 1;
	REP(i, 1, maxf) fac[i] = mul(fac[i-1], (LL)i);
	inv[maxf-1] = pow_mod(fac[maxf-1], MOD-2);
	PER(i, 0, maxf-1) inv[i] = mul(inv[i+1], (LL)(i+1));
}

LL C(int n, int k) {
	if(k > n) return 0;
	return mul(mul(fac[n], inv[k]), inv[n-k]);
}

int main() {
	preprocess();
	int n; scanf("%d", &n);

	int pre = -1, cnt = 0;
	while(n--) {
		int x; scanf("%d", &x);
		if(x == pre) {
			cnt++;
		} else {
			if(pre >= 0) {
				if(x > pre + 1) { puts("0"); return 0; }
				a.push_back(cnt);
			}
			cnt = 1;
			pre = x;
		}
	}
	a.push_back(cnt);
	int sz = SZ(a);
	d[0][a[0]-1][1][1] = 1;
	REP(i, 0, sz - 1) {
		int m = a[i + 1];
		REP(j, 0, a[i]) REP(l, 0, 2) REP(r, 0, 2) {
			LL& t = d[i][j][l][r];
			if(!t) continue;
			REP(J, 0, j+1) {
				LL c = C(j, J);
				REP(L, 0, 2) REP(R, 0, 2) {
					if(!l && L) continue;
					if(!r && R) continue;
					int n = J + L + R;
					if(!n || n > m) continue;
					LL& ans = d[i+1][m-n][L][R];
					add(ans, mul(t, mul(C(m-1, n-1), c)));
				}
			}
		}
	}

	LL ans = 0;
	REP(j, 0, a[sz-1]) REP(l, 0, 2) REP(r, 0, 2)
		add(ans, d[sz-1][j][l][r]);

	printf("%lld\n", ans);

	return 0;
}


