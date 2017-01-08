#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 100000 + 10;
const int maxnode = maxn * 4;

int maxv[maxnode], minv[maxnode];
bool setv[maxnode];

struct Building
{
	int l, r, h;
	void read() { scanf("%d%d%d", &l, &r, &h); }
};

Building a[maxn];

void pushup(int o) {
	maxv[o] = max(maxv[o<<1], maxv[o<<1|1]);
	minv[o] = min(minv[o<<1], minv[o<<1|1]);
}

void pushdown(int o) {
	if(setv[o]) {
		setv[o] = false;
		maxv[o<<1] = maxv[o<<1|1] = maxv[o];
		minv[o<<1] = minv[o<<1|1] = minv[o];
		setv[o<<1] = setv[o<<1|1] = true;
	}
}

int query(int o, int L, int R, int qL, int qR, int v) {
	int M = (L + R) / 2;
	int ans = 0;
	if(qL <= L && R <= qR) {
		if(minv[o] > v) return 0;
		else if(maxv[o] <= v) {
			setv[o] = true;
			minv[o] = maxv[o] = v;
			return R - L + 1;
		}
	}
	pushdown(o);
	if(qL <= M) ans += query(o<<1, L, M, qL, qR, v);
	if(qR > M) ans += query(o<<1|1, M+1, R, qL, qR, v);
	pushup(o);
	return ans;
}

int main()
{
	int T; scanf("%d", &T);
	while(T--) {
		maxv[1] = minv[1] = 0;
		setv[1] = true;
		int n; scanf("%d", &n);
		int maxR = 1;
		for(int i = 0; i < n; i++) {
			a[i].read();
			maxR = max(maxR, a[i].r);
		}
		int ans = 0;
		for(int i = 0; i < n; i++) {
			ans += query(1, 1, maxR, a[i].l + 1, a[i].r, a[i].h);
		}
		printf("%d\n", ans);
	}

	return 0;
}
