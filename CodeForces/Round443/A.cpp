#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
#define MP make_pair
#define PB push_back
#define REP(i, a, b) for(int i = a; i < b; i++)
#define PER(i, a, b) for(int i = b - 1; i >= a; i--)

const int maxn = 1000 + 10;

int s[maxn], d[maxn];

int main() {
	int n; scanf("%d", &n);
	REP(i, 0, n) {
		scanf("%d%d", s + i, d + i);
	}
	int ans = s[0];
	REP(i, 1, n) {
		int t = s[i];
		while(t <= ans) t += d[i];
		ans = t;
	}
	printf("%d\n", ans);

	return 0;
}
