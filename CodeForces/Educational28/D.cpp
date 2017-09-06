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

const int maxn = 505;

bool vis[maxn][maxn];

struct Pixel {
	int t, x, y;

	void read() { scanf("%d%d%d", &x, &y, &t); }

	bool operator < (const Pixel& a) const {
		return t < a.t;
	}
};

int n, m, k, q;
Pixel p[maxn * maxn];
int t[maxn * maxn], dp[maxn][maxn];

bool broken(int x) {
	int num = upper_bound(t, t + q, x) - t;
	if(num < k * k) return false;
	memset(vis, false, sizeof(vis));
	REP(i, 0, num) vis[p[i].x][p[i].y] = true;
	REP(i, 1, n + 1) REP(j, 1, m + 1)
		dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + vis[i][j];
	REP(i, k, n + 1) REP(j, k, m + 1)
		if(dp[i][j]-dp[i][j-k]-dp[i-k][j]+dp[i-k][j-k] == k*k)
			return true;
	return false;
}

int main() {
	scanf("%d%d%d%d", &n, &m, &k, &q);
	REP(i, 0, q) {
		p[i].read();
		t[i] = p[i].t;
	}
	if(q < k * k) { printf("-1\n"); return 0; }
	sort(t, t + q);
	sort(p, p + q);
	
	if(broken(0)) { printf("0\n"); return 0; }
	if(!broken(t[q-1])) { printf("-1\n"); return 0; }
	int L = 0, R = t[q-1];
	while(L < R) {
		int M = (L + R) / 2;
		if(broken(M)) R = M;
		else L = M + 1;
	}
	if(L > t[q-1]) printf("-1\n");
	else printf("%d\n", L);

	return 0;
}


