#include <cstdio>
#include <cstring>
#include <algorithm>
#include <utility>
using namespace std;

const int maxn = 100000 + 10;

int n;
pair<int, int> a[maxn];

int blank[maxn << 2];
int ans[maxn];

void pushup(int o) { blank[o] = blank[o<<1] + blank[o<<1|1]; }

void build(int o, int L, int R) {
	if(L == R) { blank[o] = 1; return; }
	int M = (L + R) / 2;
	build(o<<1, L, M);
	build(o<<1|1, M+1, R);
	pushup(o);
}

void update(int o, int L, int R, int pos, int v) {
	if(L == R) { blank[o] = 0; ans[L] = v; return; }
	int M = (L + R) / 2;
	if(blank[o<<1] >= pos) update(o<<1, L, M, pos, v);
	else update(o<<1|1, M+1, R, pos - blank[o<<1], v);
	pushup(o);
}

int main()
{
	int T; scanf("%d", &T);
	for(int kase = 1; kase <= T; kase++) {
		scanf("%d", &n);
		for(int i = 1; i <= n; i++) {
			scanf("%d%d", &a[i].first, &a[i].second);
		}
		sort(a + 1, a + 1 + n);
		build(1, 1, n);
		bool ok = true;
		for(int i = 1; i <= n; i++) {
			int k = a[i].second;
			if(k > n - i) { ok = false; break; }
			int pos = min(k + 1, n - i + 1 - k);
			update(1, 1, n, pos, a[i].first);
		}

		printf("Case #%d:", kase);
		if(ok) {
			for(int i = 1; i <= n; i++) printf(" %d", ans[i]);
			printf("\n");
		} else {
			printf(" impossible\n");
		}
	}

	return 0;
}
