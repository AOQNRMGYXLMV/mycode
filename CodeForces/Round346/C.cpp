#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int maxn = 100000 + 10;
const int maxm = 1000000;

bool has[maxm];

int n, m;

vector<int> ans;

int main()
{
	scanf("%d%d", &n, &m);
	while(n--) {
		int x; scanf("%d", &x);
		if(x < maxm) has[x] = true;
	}

	for(int i = 1; i < maxm && m > 0; i++) {
		if(has[i]) continue;
		m -= i;
		if(m >= 0) ans.push_back(i);
	}

	int sz = ans.size();
	printf("%d\n", sz);
	for(int i = 0; i < sz - 1; i++) printf("%d ", ans[i]);
	if(sz >= 1) printf("%d", ans[sz-1]);
	printf("\n");

	return 0;
}
