#include <cstdio>
#include <cstring>
#include <algorithm>

const int maxm = 100000 + 10;
const int maxn = 20;
typedef long long LL;

int bitcount(int x) {
	int ans = 0;
	for(; x; x >>= 1) if(x & 1) ans++;
	return ans;
}

char s[maxm];
LL cnt[1 << maxn], mone[1 << maxn];
int a[1 << maxn];

void fwtXor(LL* a, int l) {
	if(l == 1) return;
	l >>= 1;
	fwtXor(a, l);
	fwtXor(a + l, l);
	for(int i = 0; i < l; i++) {
		LL t1 = a[i];
		LL t2 = a[i + l];
		a[i] = t1 + t2;
		a[i + l] = t1 - t2;
	}
}

void ifwtXor(LL* a, int l) {
	if(l == 1) return;
	l >>= 1;
	for(int i = 0; i < l; i++) {
		LL t1 = a[i];
		LL t2 = a[i + l];
		a[i] = (t1 + t2) / 2;
		a[i + l] = (t1 - t2) / 2;
	}
	ifwtXor(a, l);
	ifwtXor(a + l, l);
}

int main()
{
	int n, m; scanf("%d%d", &n, &m);
	for(int i = 0; i < (1 << n); i++) {
		int t = bitcount(i);
		mone[i] = std::min(t, n - t);
	}

	for(int i = 0; i < n; i++) {
		scanf("%s", s);
		for(int j = 0; j < m; j++) if(s[j] == '1')
			a[j] |= (1 << i);
	}

	for(int i = 0; i < m; i++) cnt[a[i]]++;

	fwtXor(cnt, 1 << n);
	fwtXor(mone, 1 << n);
	for(int i = 0; i < (1 << n); i++) cnt[i] *= mone[i];
	ifwtXor(cnt, 1 << n);

	LL ans = n * m;
	for(int i = 0; i < (1 << n); i++) if(cnt[i] < ans) ans = cnt[i];

	printf("%lld\n", ans);

	return 0;
}
