#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long LL;
const int maxn = 300000 + 10;

int n, m;
int a[maxn], pos[maxn];
vector<int> foe[maxn];

int main()
{
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++) {
		scanf("%d", a + i);
		pos[a[i]] = i;
	}

	while(m--) {
		int a, b; scanf("%d%d", &a, &b);
		a = pos[a], b = pos[b];
		if(a > b) swap(a, b);
		foe[a].push_back(b);
	}

	LL ans = 0;
	int r = n + 1;
	for(int i = n; i >= 1; i--) {
		for(int j : foe[i]) r = min(r, j);
		ans += r - i;
	}

	printf("%lld\n", ans);

	return 0;
}
