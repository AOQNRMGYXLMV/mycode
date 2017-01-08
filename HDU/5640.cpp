#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int ans;

void gcd(int a, int b) {
	if(!b) return;
	else { ans += a / b; gcd(b, a % b); }
}

int main()
{
	int T; scanf("%d", &T);
	while(T--) {
		int n, m; scanf("%d%d", &n, &m);
		ans = 0;
		gcd(n, m);
		printf("%d\n", ans);
	}

	return 0;
}
