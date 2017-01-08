#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 100000 + 10;
const int maxd = 20;

int n, m;
int sorted[maxn];
int T[maxd][maxn], num[maxd][maxn];

void build(int d, int L, int R) {
	int M = (L + R) / 2;
	int lsame = M - L + 1;
	for(int i = L; i <= R; i++) if(T[d][i] < sorted[M]) lsame--;
	int lpos = L, rpos = M+1;
	for(int i = L; i <= R; i++) {
		if(i == L) num[d][i] = 0;
		else num[d][i] = num[d][i - 1];
		if(T[d][i] < sorted[M] || (T[d][i] == sorted[M] && lsame)) {
			T[d+1][lpos++] = T[d][i];
			num[d][i]++;
			if(T[d][i] == sorted[M]) lsame--;
		} else {
			T[d+1][rpos++] = T[d][i];
		}
	}
	if(L < M) build(d + 1, L, M);
	if(M+1 < R) build(d + 1, M+1, R);
}

int query(int d, int L, int R, int qL, int qR, int k) {
	if(L == R) return T[d][L];
	int M = (L + R) / 2;
	int cntl;
	if(L == qL) cntl = 0;
	else cntl = num[d][qL - 1];
	int cntr = num[d][qR];
	int cnt = cntr - cntl;
	if(cnt >= k) return query(d + 1, L, M, L + cntl, L + cntr - 1, k);
	else {
		cntl = qL - L - cntl;
		cntr = qR - L + 1 - cntr;
		return query(d + 1, M+1, R, M+1+cntl, M+cntr, k - cnt);
	}
}

int main()
{
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++) {
		scanf("%d", sorted + i);
		T[0][i] = sorted[i];
	}

	sort(sorted + 1, sorted + 1 + n);
	build(0, 1, n);

	while(m--) {
		int l, r, k; scanf("%d%d%d", &l, &r, &k);
		printf("%d\n", query(0, 1, n, l, r, k));
	}

	return 0;
}
