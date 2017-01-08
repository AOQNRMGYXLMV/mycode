#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 1000000 + 10;

int n, m, a[maxn], b[maxn], sorted[maxn];

int sum[maxn];

int C[maxn];

int lowbit(int x) { return x & (-x); }

void add(int x, int v) {
	while(x <= n) {
		C[x] ^= v;
		x += lowbit(x);
	}
}

int query(int x) {
	int ans = 0;
	while(x) {
		ans ^= C[x];
		x -= lowbit(x);
	}
	return ans;
}

int last[maxn];
int l[maxn], r[maxn], ans[maxn];
int head[maxn], next[maxn];

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		scanf("%d", a + i);
		sum[i] = sum[i - 1] ^ a[i];
		sorted[i] = a[i];
	}

	sort(sorted + 1, sorted + 1 + n);
	int tot = unique(sorted + 1, sorted + 1 + n) - sorted - 1;
	for(int i = 1; i <= n; i++) {
		b[i] = lower_bound(sorted + 1, sorted + 1 + tot, a[i]) - sorted;
	}

	scanf("%d", &m);
	for(int i = 1; i <= m; i++) {
		scanf("%d%d", l + i, r + i);
		next[i] = head[r[i]];
		head[r[i]] = i;
	}

	for(int i = 1; i <= n; i++) {
		if(last[b[i]]) add(last[b[i]], a[i]);
		last[b[i]] = i;
		add(last[b[i]], a[i]);
		for(int j = head[i]; j != 0; j = next[j]) {
			ans[j] = sum[r[j]] ^ sum[l[j] - 1] ^ query(r[j]) ^ query(l[j] - 1);
		}
	}

	for(int i = 1; i <= m; i++) printf("%d\n", ans[i]);

	return 0;
}
