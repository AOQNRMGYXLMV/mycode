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

const int maxn = 300 + 10;
const LL MOD = 1000000007LL;
int n, a[maxn];
int g, sz[maxn], id[maxn];
LL d[maxn][maxn];

LL mul(LL a, LL b) { return a * b % MOD; }
void add(LL& a, LL b) { a += b; if(a >= MOD) a -= MOD; }

bool check(int a, int b) {
	LL mul = (LL)a * b;
	LL L = 1, R = 1000000000;
	while(L < R) {
		LL M = (R + L + 1) / 2;
		if(M * M <= mul) L = M;
		else R = M - 1;
	}
	return L * L == mul;
}

LL C[maxn][maxn], fac[maxn];
LL init() {
	C[0][0] = 1;
	REP(i, 1, maxn) C[i][0] = C[i][i] = 1;
	REP(i, 2, maxn) REP(j, 1, i) {
		C[i][j] = C[i-1][j] + C[i-1][j-1];
		if(C[i][j] >= MOD) C[i][j] -= MOD;
	}
	fac[0] = 1;
	REP(i, 1, maxn) fac[i] = mul(fac[i - 1], i);
}

int main() {
	init();

	check(2, 2);
	scanf("%d", &n);
	REP(i, 0, n) scanf("%d", a + i);
	memset(id, -1, sizeof(id));
	g = 1; id[0] = 1; sz[1] = 1;
	REP(i, 1, n) {
		REP(j, 0, i) if(check(a[i], a[j])) {
			id[i] = id[j];
			sz[id[j]]++;
			break;
		}
		if(id[i] == -1) { sz[++g] = 1; id[i] = g; }
	}

	d[1][sz[1] - 1] = 1;
	int tot = 0;
	REP(i, 1, g) {
		tot += sz[i];
		REP(j, 0, tot) {
			LL& cur = d[i][j];
			int& size = sz[i + 1];
			REP(S, 1, min(size, tot + 1) + 1) {
				REP(D, 0, min(j, S) + 1) {
					add(d[i+1][j-D+size-S], mul(cur, mul(C[size-1][S-1], mul(C[j][D], C[tot+1-j][S-D]))));
				}
			}
		}
	}

	LL& ans = d[g][0];
	REP(i, 1, g + 1) ans = mul(ans, fac[sz[i]]);
	printf("%lld\n", ans);

	return 0;
}

