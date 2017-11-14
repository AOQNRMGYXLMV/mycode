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

const int maxn = 200;

int n;
int a[maxn];

int main() {
	scanf("%d", &n);
	REP(i, 0, n) REP(j, 0, n) {
		int x; scanf("%d", &x);
		a[j] += x;
	}

	sort(a, a + n);
	int i;
	for(i = 0; i + 1 < n; i += 2) {
		if(a[i] <= 0 && a[i+1] <= 0) {
			a[i] = -a[i];
			a[i+1] = -a[i+1];
		} else {
			break;
		}
	}

	if(i + 1 < n && -a[i]-a[i+1] > a[i]+a[i+1]) {
		a[i] = -a[i];
		a[i+1] = -a[i+1];
	}

	int ans = 0;
	REP(i, 0, n) ans += a[i];
	printf("%d\n", ans);

	return 0;
}
