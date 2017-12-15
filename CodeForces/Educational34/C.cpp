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

const int maxn = 5000 + 10;

int n, a[maxn];

int main() {
	scanf("%d", &n);
	REP(i, 0, n) scanf("%d", a + i);
	sort(a, a + n);
	int ans = 1;
	for(int i = 0, j; i < n; i = j) {
		for(j = i; j < n && a[j] == a[i]; j++);
		ans = max(ans, j - i);
	}

	printf("%d\n", ans);

	return 0;
}

