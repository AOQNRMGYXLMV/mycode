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

const int maxn = 300000 + 10;

int n, a, b, c, d, start, len;
int t[maxn], q[maxn];

int main() {
	scanf("%d%d%d%d%d%d%d", &n, &a, &b, &c, &d, &start, &len);
	REP(i, 1, n + 1) scanf("%d%d", t + i, q + i);

	int R = 1;
	LL before = start, change = 0, minv = 0;
	while(R <= n && t[R] < len) {
		change += q[R] ? c : -d;
		minv = min(minv, change);
		R++;
	}

	if(minv + start >= 0) { printf("0\n"); return 0; }

	for(int L = 1; L <= n; L++) {
		while(R <= n && t[R] - t[L - 1] <= len) {
			change += q[R] ? c : -d;
			minv = min(minv, change);
			R++;
		}
		if(minv + before >= 0) { printf("%d\n", t[L-1]+1); return 0; }
		change -= q[L] ? c : -d;
		minv -= q[L] ? c : -d;
		before += q[L] ? a : -b;
		if(before < 0) { printf("-1\n"); return 0; }
	}

	printf("%d\n", t[n] + 1);

	return 0;
}

