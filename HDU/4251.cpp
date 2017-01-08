#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 100000 + 10;
const int maxd = 20;

int n, a[maxn];
int T[maxd][maxn], sum[maxd][maxn];

void build(int d, int L, int R) {
	int M = (L + R) / 2;
	int lsame = M - L + 1;
	for(int i = L; i <= R; i++)
		if(T[d][i] < a[M]) lsame--;
	int lpos = L, rpos = M+1;
	for(int i = L; i <= R; i++) {
		if(i == L) sum[d][i] = 0;
		else sum[d][i] = sum[d][i-1];
		if(T[d][i] < a[M] || (T[d][i] == a[M] && lsame)) {
			T[d+1][lpos++] = T[d][i];
			sum[d][i]++;
			if(T[d][i] == a[M]) lsame--;
		} else T[d+1][rpos++] = T[d][i];
	}
	if(L < M) build(d + 1, L, M);
	if(M+1 < R) build(d + 1, M+1, R);
}

int query(int d, int L, int R, int qL, int qR, int k) {
	if(L == R) return T[d][L];
	int M = (L + R) / 2;
	int cntl;
	if(qL == L) cntl = 0;
	else cntl = sum[d][qL - 1];
	int cntr = sum[d][qR];
	int cnt = cntr - cntl;
	if(cnt >= k) return query(d+1, L, M, L+cntl, L+cntr-1, k);
	else {
		cntl = qL - L - cntl;
		cntr = qR - L + 1 - cntr;
		return query(d+1, M+1, R, M+1+cntl, M+cntr, k-cnt);
	}
}

int main()
{
	int kase = 1;
	while(scanf("%d", &n) == 1) {
		for(int i = 1; i <= n; i++) {
			scanf("%d", a + i);
			T[0][i] = a[i];
		}
		sort(a + 1, a + 1 + n);
		build(0, 1, n);

		printf("Case %d:\n", kase++);
		int q; scanf("%d", &q);
		while(q--) {
			int l, r; scanf("%d%d", &l, &r);
			int k = (r - l) / 2 + 1;
			printf("%d\n", query(0, 1, n, l, r, k));
		}
	}

	return 0;
}
