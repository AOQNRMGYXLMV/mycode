#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long LL;
const int maxn = 100000 + 10;
const int maxq = 35000 * 3 + 10;
const int maxnode = maxn << 5;
const int maxcmd = maxn + maxq;

int n;
char cmd[15];
int type[maxcmd], a[maxcmd], b[maxcmd], c[maxcmd];

int x[maxn], tot;

int sz, root[maxn];
int lch[maxnode], rch[maxnode], sum[maxnode];

int update(int pre, int L, int R, int pos) {
	int rt = ++sz;
	sum[rt] = sum[pre] + 1;
	if(L < R) {
		int M = (L + R) / 2;
		if(pos <= M) { rch[rt] = rch[pre]; lch[rt] = update(lch[pre], L, M, pos); }
		else { lch[rt] = lch[pre]; rch[rt] = update(rch[pre], M+1, R, pos); }
	}
	return rt;
}

int query(int l, int r, int L, int R, int k) {
	if(L == R) return L;
	int num = sum[lch[r]] - sum[lch[l]];
	int M = (L + R) / 2;
	if(num >= k) return query(lch[l], lch[r], L, M, k);
	else return query(rch[l], rch[r], M+1, R, k - num);
}

int Rank(int rt, int L, int R, int x) {
	if(L == R) return sum[rt];
	int M = (L + R) / 2;
	if(x > M) return sum[lch[rt]] + Rank(rch[rt], M+1, R, x);
	else return Rank(lch[rt], L, M, x);
}

int main()
{
	int kase = 1;
	while(scanf("%d", &n) == 1) {
		tot = 0;
		for(int i = 0; i < n; i++) {
			scanf("%s", cmd);
			scanf("%d", a + i);
			if(!cmd[6]) { type[i] = 0; x[tot++] = a[i]; }
			else type[i] = cmd[6] - '0';
			if(type[i] == 1) scanf("%d%d", b + i, c + i);
		}
		sort(x, x + tot);

		int cnt = 0;
		sz = 0;
		LL ans[3];
		for(int i = 0; i < 3; i++) ans[i] = 0;
		for(int i = 0; i < n; i++) {
			if(type[i] == 0) {
				cnt++;
				int pos = lower_bound(x, x + tot, a[i]) - x + 1;
				root[cnt] = update(root[cnt-1], 1, tot, pos);
			} else if(type[i] == 1) {
				int q = query(root[a[i]-1], root[b[i]], 1, tot, c[i]);
				ans[0] += x[q - 1];
			} else if(type[i] == 2) {
				int pos = lower_bound(x, x + tot, a[i])	- x + 1;
				ans[1] += Rank(root[cnt], 1, tot, pos);
			} else {
				int q = query(0, root[cnt], 1, tot, a[i]);
				ans[2] += x[q - 1];
			}
		}

		printf("Case %d:\n", kase++);
		for(int i = 0; i < 3; i++) printf("%lld\n", ans[i]);
	}

	return 0;
}
