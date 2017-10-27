#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 300000 + 10;

int n, p[maxn];

int C[maxn];
#define lowbit(x) (x&-x)

void add(int x) {
	while(x <= n) {
		C[x]++;
		x += lowbit(x);
	}
}

int query() {
	int ans = 0;
	int x, cnt = 1;
	for(x = 1; (x << 1) <= n; x <<= 1) cnt++;
	for(int i = 0; i < cnt; i++) {
		int low = lowbit(x);
		if(C[x] == low) {
			ans += C[x];
			x += low >> 1;
		} else {
			x -= low >> 1;
		}
	}

	return ans;
}

int main() {
	scanf("%d", &n);
	printf("1");
	for(int i = 1; i <= n; i++) {
		int x; scanf("%d", &x);
		add(n - x + 1);
		printf(" %d", i - query() + 1);
	}
	printf("\n");

	return 0;
}