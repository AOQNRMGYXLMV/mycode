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
	int n; scanf("%d", &n);
	int a = 0, b = 0;
	while(n--) {
		int x; scanf("%d", &x);
		if(x == 1) a++;
		else b++;
	}

	int ans = min(a, b);
	a -= ans;
	ans += a / 3;
	printf("%d\n", ans);

	return 0;
}

