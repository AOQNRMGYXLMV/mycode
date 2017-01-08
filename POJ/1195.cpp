#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 1050;

int n;

int C[maxn][maxn];

int lowbit(int x) { return x & (-x); }

void init() { memset(C, 0, sizeof(C)); }

void add(int x, int y, int v) {
	for(int i = x; i <= n; i += lowbit(i)) {
		for(int j = y; j <= n; j += lowbit(j)) {
			C[i][j] += v;
		}
	}
}

int query(int x, int y) {
	int ans = 0;
	if(!x || !y) return 0;
	for(int i = x; i; i -= lowbit(i)) {
		for(int j = y; j; j -= lowbit(j)) {
			ans += C[i][j];
		}
	}
	return ans;
}

int main()
{
	int cmd;
	while(scanf("%d", &cmd) == 1 && cmd != 3) {
		if(cmd == 0) {
			init();
			scanf("%d", &n);
		} else if(cmd == 1) {
			int x, y, a; scanf("%d%d%d", &x, &y, &a);
			x++; y++;
			add(x, y, a);
		} else {
			int l, b, r, t; scanf("%d%d%d%d", &l, &b, &r, &t);
			l++; b++; r++; t++;
			int ans = query(r, t);
			ans -= query(l-1, t);
			ans -= query(r, b-1);
			ans += query(l-1, b-1);
			printf("%d\n", ans);
		}
	}

	return 0;
}
