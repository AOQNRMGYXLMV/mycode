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

const int maxn = 1510;

int n, a[maxn];

int main() {
	scanf("%d", &n);
	REP(i, 0, n) scanf("%d", a + i);
	int ans = 0;
	REP(i, 0, n) REP(j, i + 1, n) {
		if(a[i] > a[j]) ans ^= 1;
	}

	int m; scanf("%d", &m);
	while(m--) {
		int l, r; scanf("%d%d", &l, &r);
		int x = (r-l+1) % 4;
		if(x == 2 || x == 3) ans ^= 1;
		if(ans) printf("odd\n");
		else printf("even\n");
	}

	return 0;
}

