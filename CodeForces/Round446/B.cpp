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

const int maxn = 1000000 + 10;

int a[maxn];

int main() {
	int n; scanf("%d", &n);
	REP(i, 0, n) scanf("%d", a + i);
	int p = n;
	int ans = 0;
	PER(i, 0, n) {
		if(p > i) ans++;
		if(i - a[i] < p) p = i - a[i];
	}
	printf("%d\n", ans);

	return 0;
}

