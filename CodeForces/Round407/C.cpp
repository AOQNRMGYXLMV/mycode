#include <cstdio>
#include <cstring>
#include <cmath>
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

const int maxn = 100000 + 10;

int n;
int a[maxn], b[maxn];
LL dp[maxn][2];

void upd(LL& a, LL b) { if(a < b) a = b; }

inline int sign(int x) { if(!x) return 1; return -1; }

const LL INF = 1LL << 60;

int main() {
	scanf("%d", &n);
	REP(i, 0, n) scanf("%d", b + i);
	REP(i, 1, n) a[i] = abs(b[i] - b[i - 1]);

	dp[1][1] = a[1]; dp[1][0] = -INF;
	REP(i, 2, n) {
		dp[i][i&1] = a[i];
		dp[i][(i&1)^1] = -INF;
		REP(j, 0, 2) upd(dp[i][j], dp[i-1][j] + sign((i&1)^j) * a[i]);
	}

	LL ans = -(1LL << 60);
	REP(i, 1, n) REP(j, 0, 2) upd(ans, dp[i][j]);
	printf("%lld\n", ans);

	return 0;
}


