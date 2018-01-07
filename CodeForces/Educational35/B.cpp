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
	int a, b, n;
	scanf("%d%d%d", &n, &a, &b);
	int mn = min(a, b);
	int ans = 1;
	for(int i = 1; i <= mn; i++) {
		if(a / i + b / i >= n) ans = i;
		else break;
	}
	printf("%d\n", ans);

	return 0;
}

