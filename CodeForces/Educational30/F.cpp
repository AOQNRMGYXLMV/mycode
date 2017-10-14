#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define REP(i, a, b) for(int i = a; i < b; i++)
#define PER(i, a, b) for(int i = b - 1; i >= a; i--)
typedef long long LL;

const int maxn = 200000 + 10;

int n, sum[maxn];
char s[maxn], t[maxn];

int fi[maxn], se[maxn], c[maxn], sa[maxn];

bool equal(int *a, int i, int j, int k) {
	if(a[i] != a[j]) return false;
	if(i + k < n && j + k < n) return a[i + k] == a[j + k];
	if(i + k >= n && j + k >= n) return true;
	return false;
}

void build_sa(int m = 27) {
	int *x = fi, *y = se;
	REP(i, 0, m) c[i] = 0;
	REP(i, 0, n) c[x[i] = s[i]]++;
	REP(i, 1, m) c[i] += c[i - 1];
	PER(i, 0, n) sa[--c[x[i]]] = i;
	for(int k = 1; k <= n; k <<= 1) {
		int p = 0;
		REP(i, n - k, n) y[p++] = i;
		REP(i, 0, n) if(sa[i] >= k) y[p++] = sa[i] - k;
		REP(i, 0, m) c[i] = 0;
		REP(i, 0, n) c[x[y[i]]]++;
		REP(i, 1, m) c[i] += c[i - 1];
		PER(i, 0, n) sa[--c[x[y[i]]]] = y[i];
		swap(x, y);
		p = 1; x[sa[0]] = 0;
		REP(i, 1, n)
			x[sa[i]] = equal(y, sa[i], sa[i-1], k) ? p-1 : p++;
		if(p >= n) break;
		m = p;
	}
}

int rank[maxn], height[maxn];
void get_height() {
	REP(i, 0, n) rank[sa[i]] = i;
	int k = 0;
	REP(i, 0, n) {
		if(k) k--;
		if(!rank[i]) { k = 0; continue; }
		int j = sa[rank[i] - 1];
		while(s[i+k] == s[j+k]) k++;
		height[rank[i]] = k;
	}
}

int C[maxn];
#define lowbit(x) (x&(-x))
void init() { memset(C, -1, sizeof(C)); }
void upd(int x, int v) {
	while(x <= n) {
		C[x] = max(C[x], v);
		x += lowbit(x);
	}
}
int query(int x) {
	int ans = -1;
	while(x) {
		ans = max(ans, C[x]);
		x -= lowbit(x);
	}
	return ans;
}

int pre[maxn], suf[maxn];

int main() {
	scanf("%d\n%s\n%s", &n, s, t);
	reverse(s, s + n);
	reverse(t, t + n);
	LL ans = 0;
	REP(i, 0, n) if(t[i] == '0') { ans = n - i; break; }
	REP(i, 0, n) { s[i] -= 'a' - 1; }

	build_sa();
	get_height();
	REP(i, 0, n) sum[i] = t[sa[i]] == '1';
	REP(i, 1, n) sum[i] += sum[i - 1];

	REP(i, 0, n) { upd(height[i] + 1, i); pre[i] = query(height[i]); }
	init();
	PER(i, 0, n) { upd(height[i] + 1, n - i - 1); suf[i] = n - query(height[i]) - 1; }

	REP(i, 1, n) {
		upd(height[i] + 1, i);
		if(!height[i]) continue;
		LL len = suf[i] - pre[i];
		LL ban = sum[suf[i] - 1];
		if(pre[i] > 0) ban -= sum[pre[i] - 1];
		LL tmp = (LL)(len - ban) * height[i];
		if(tmp > ans)
			ans = tmp;
	}
	printf("%I64d\n", ans);

	return 0;
}