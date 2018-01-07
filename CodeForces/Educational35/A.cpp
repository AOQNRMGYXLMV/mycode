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

const int maxn = 200000 + 10;

int a[maxn];

int main() {
	int n; scanf("%d", &n);
	int minv = 1000000000 + 1;
	REP(i, 0, n) {
		scanf("%d", a + i);
		if(a[i] < minv) minv = a[i];
	}
	int ans = n, pre = -1;
	REP(i, 0, n) {
		if(a[i] == minv) {
			if(pre != -1) ans = min(ans, i - pre);
			pre = i;
		}
	}

	printf("%d\n", ans);

	return 0;
}

