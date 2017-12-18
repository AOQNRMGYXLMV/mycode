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
	int n, a, b;
	scanf("%d%d%d", &n, &a, &b);
	for(int x = 0; x * a <= n; x++) {
		if((n - x * a) % b == 0) {
			printf("YES\n");
			printf("%d %d\n", x, (n - x * a) / b);
			return 0;
		}
	}

	printf("NO\n");

	return 0;
}

