#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <utility>
#include <cmath>
using namespace std;

typedef long long LL;
typedef pair<LL, LL> PLL;

vector<PLL> ans;

int cmp(LL n, int k, LL m) {
	LL C = 1;
	for(int i = 1; i <= k; i++) {
		if(m * i / (n - i + 1) / C == 0) return 1;
		C = C * (n - i + 1) / i;
	}
	return C == m ? 0 : -1;
}

void output(const PLL& x) {
	printf("(%lld,%lld)", x.first, x.second);
}

int main()
{
	int T; scanf("%d", &T);
	while(T--) {
		LL m; scanf("%lld", &m);
		ans.clear();
		ans.push_back(make_pair(m, 1LL));
		ans.push_back(make_pair(m, m - 1LL));
		for(int i = 2; i <= 30; i++) {
			LL L = i, R = m;
			while(L <= R) {
				LL mid = (L + R) / 2;
				int c = cmp(mid, i, m);
				if(c == 0) {
					ans.push_back(make_pair(mid, i));
					ans.push_back(make_pair(mid, mid - i));
					break;
				} else if(c == 1) R = mid - 1;
				else L = mid + 1;
			}
		}
		sort(ans.begin(), ans.end());
		ans.resize(unique(ans.begin(), ans.end()) - ans.begin());
		printf("%d\n", ans.size());
		if(!ans.empty()) output(ans[0]);
		for(int i = 1; i < ans.size(); i++) {
			printf(" "); output(ans[i]);
		}
		printf("\n");
	}

	return 0;
}
