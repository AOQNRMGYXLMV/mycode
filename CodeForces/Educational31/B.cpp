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

int main() {
	int n, x; scanf("%d%d", &n, &x);
	REP(i, 0, n) {
		int a; scanf("%d", &a);
		x -= a;
	}

	x -= n - 1;
	if(x) printf("NO\n");
	else printf("YES\n");

	return 0;
}
