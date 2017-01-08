#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int maxn = 1000 + 10;

int a[maxn];
vector<int> ans;

int gcd(int a, int b) { return !b ? a : gcd(b, a % b); }

int main()
{
	int n; scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", a + i);
	ans.push_back(a[1]);
	for(int i = 2; i <= n; i++) {
		if(gcd(a[i], a[i-1]) > 1) ans.push_back(1);
		ans.push_back(a[i]);
	}

	int sz = ans.size();
	printf("%d\n", sz - n);
	for(int i = 0; i < ans.size(); i++) printf("%d ", ans[i]);
	printf("\n");

	return 0;
}
