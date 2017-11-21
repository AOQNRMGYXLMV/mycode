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

const int maxn = 1000 + 10;

int a[maxn];

int main() {
	int n; scanf("%d", &n);
	REP(i, 0, n) {
		scanf("%d", a + i);
		if(i) {
			if(a[i] % a[0] != 0) {
				printf("-1\n");
				return 0;
			}
		}
	}

	printf("%d\n", n * 2 - 1);
	printf("%d", a[0]);
	REP(i, 1, n) printf(" %d %d", a[0], a[i]);
	printf("\n");

	return 0;
}

