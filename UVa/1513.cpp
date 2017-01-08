#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 100000 + 10;

int n, m;
int C[maxn << 1];

int lowbit(int x) { return x & (-x); }

void add(int x, int v) {
	while(x <= n + m) {
		C[x] += v;
		x += lowbit(x);
	}
}

int query(int x) {
	int ans = 0;
	while(x) {
		ans += C[x];
		x -= lowbit(x);
	}
	return ans;
}

int pos[maxn];

int main()
{
	int T; scanf("%d", &T);
	while(T--) {
		scanf("%d%d", &n, &m);
		memset(C, 0, sizeof(C));
		for(int i = 1; i <= n; i++) {
			pos[i] = n - i + 1;
			add(i, 1);
		}

		int tot = n;
		for(int i = 0; i < m; i++) {
			int x;
			scanf("%d", &x);
			printf("%d", n - query(pos[x]));
			add(pos[x], -1);
			add(++tot, 1);
			pos[x] = tot;
			if(i < m - 1) printf(" ");
			else printf("\n");
		}
	}

	return 0;
}
