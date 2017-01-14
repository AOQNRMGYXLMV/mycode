#include <cstdio>
#include <cstring>

const int log = 30;
const int maxn = 1000000 + 10;
const int maxv = maxn * log;
#define bit(x, i) ((x >> i) & 1)

int sz, ch[maxv][2], val[maxv];
int n, k;

void init() { sz = 0; memset(ch[0], 0, sizeof(ch[0])); }

void insert(int x) {
	int u = 0;
	for(int i = 29; i >= 0; i--) {
		int c = bit(x, i);
		if(!ch[u][c]) {
			ch[u][c] = ++sz;
			memset(ch[sz], 0, sizeof(ch[sz]));
		}
		u = ch[u][c];
		val[u]++;
	}
}

int query(int x) {
	int u = 0, ans = 0;
	for(int i = 29; i >= 0; i--) {
		int bitk = bit(k, i);
		int bitx = bit(x, i);
		int c = bitk ^ bitx;
		if(bitk == 0 && ch[u][c ^ 1]) ans += val[ch[u][c ^ 1]];
		if(!ch[u][c]) return ans;
		u = ch[u][c];
	}
	ans += val[u];
	return ans;
}

int main()
{
	scanf("%d%d", &n, &k);

	int pre = 0;
	long long ans = 0;
	for(int i = 0; i < n; i++) {
		insert(pre);
		int a; scanf("%d", &a);
		pre ^= a;
		ans += query(pre);
	}

	printf("%lld\n", ans);

	return 0;
}
