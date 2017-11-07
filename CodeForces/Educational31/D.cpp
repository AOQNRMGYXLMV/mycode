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

int n;
vector<int> a;

int main() {
	scanf("%d", &n);
	if(!(n&1)) a.push_back(0);
	LL l = n >> 1;
	while(n--) {
		int x; scanf("%d", &x);
		a.push_back(x);
	}
	sort(ALL(a));

	LL ans = l * a[0];
	for(int i = 1; l; i += 2, l--) {
		ans += l * (a[i] + a[i+1]);
	}

	printf("%lld\n", ans);

	return 0;
}

