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

int main() {
	LL max1 = 0, max2 = 0;
	int n; scanf("%d", &n);
	LL sum = 0;
	REP(i, 0, n) {
		int a; scanf("%d", &a);
		sum += a;
	}
	REP(i, 0, n) {
		int a; scanf("%d", &a);
		if(a > max1) { max2 = max1; max1 = a; }
		else if(a > max2) max2 = a;
	}
	if(sum <= max1 + max2) printf("YES\n");
	else printf("NO\n");

	return 0;
}

