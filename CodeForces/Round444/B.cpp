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

int a[3][6];
bool vis[100];

int main() {
	int n; scanf("%d", &n);
	REP(i, 0, n) REP(j, 0, 6) {
		scanf("%d", &a[i][j]);
		vis[a[i][j]] = true;
	}

	REP(i1, 0, n) REP(i2, i1+1, n) REP(j1, 0, 6) REP(j2, 0, 6) {
		vis[a[i1][j1] * 10 + a[i2][j2]] = true;
		vis[a[i2][j2] * 10 + a[i1][j1]] = true;
	}

	int ans = 0;
	REP(i, 1, 100) if(vis[i]) ans = i; else break;
	printf("%d\n", ans);

	return 0;
}

