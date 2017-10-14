#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 100000;

char s[maxn];
int a[maxn], p[maxn * 4 + 10];

int main() {
	int n; scanf("%d%s", &n, s);
	for(int i = 1; i <= n; i++) a[i] = (s[i-1] == '1' ? 1 : -1);
	memset(p, -1, sizeof(p));
	int ans = 0;
	p[n] = 0;
	for(int i = 1; i <= n; i++) {
		a[i] += a[i - 1];
		if(p[a[i] + n] != -1) {
			ans = max(ans, i - p[a[i] + n]);
		} else {
			p[a[i] + n] = i;
		}
	}
	printf("%d\n", ans);

	return 0;
}
