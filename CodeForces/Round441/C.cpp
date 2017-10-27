#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int digits(int x) {
	int ans = 0;
	while(x) { ans += x % 10; x /= 10; }
	return ans;
}

int cnt, ans[110];

int main() {
	int n; scanf("%d", &n);
	int l = max(0, n - 100);
	for(int i = l; i <= n; i++) {
		if(digits(i) + i == n) {
			ans[cnt++] = i;
		}
	}

	printf("%d\n", cnt);
	if(cnt) {
		for(int i = 0; i < cnt; i++) printf("%d ", ans[i]);
		printf("\n");
	}

	return 0;
}