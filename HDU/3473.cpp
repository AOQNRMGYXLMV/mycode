#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long LL;
const int maxn = 100000 + 10;
const int maxd = 20;

int n;
int sorted[maxn];

int T[maxd][maxn], cnt[maxd][maxn];
LL sum[maxd][maxn], pre[maxn];

void build(int d, int L, int R) {
	int M = (L + R) / 2;
	int lsame = M - L + 1;
	for(int i = L; i <= R; i++)
		if(T[d][i] < sorted[M]) lsame--;
	int lpos = L, rpos = M + 1;
	for(int i = L; i <= R; i++) {
		if(i == L) { sum[d][i] = 0; cnt[d][i] = 0; }
		else { sum[d][i] = sum[d][i-1]; cnt[d][i] = cnt[d][i-1]; }
		if(T[d][i] < sorted[M] || (T[d][i] == sorted[M] && lsame)) {
			cnt[d][i]++;
			sum[d][i] += T[d][i];
			T[d+1][lpos++] = T[d][i];
			if(T[d][i] == sorted[M]) lsame--;
		} else T[d+1][rpos++] = T[d][i];
	}

	if(L < M) build(d + 1, L, M);
	if(M + 1 < R) build(d + 1, M + 1, R);
}

LL q_kth, q_sum;

void query(int d, int L, int R, int qL, int qR, int k) {
	if(L == R) { q_kth = T[d][L]; q_sum += T[d][L]; return; }
	int M = (L + R) / 2;
	int numl;
	if(qL == L) numl = 0;
	else numl = cnt[d][qL - 1];
	int numr = cnt[d][qR];
	int num = numr - numl;
	if(num >= k) {
		query(d + 1, L, M, L + numl, L + numr - 1, k);
	} else {
		LL suml;
		if(qL == L) suml = 0;
		else suml = sum[d][qL - 1];
		q_sum += sum[d][qR] - suml;
		numl = qL - L - numl;
		numr = qR - L + 1 - numr;
		query(d + 1, M+1, R, M+1+numl, M+numr, k - num);
	}
}

int main()
{
	int _; scanf("%d", &_);
	for(int kase = 1; kase <= _; kase++) {
		scanf("%d", &n);
		for(int i = 1; i <= n; i++) {
			scanf("%d", sorted + i);
			pre[i] = pre[i - 1] + sorted[i];
			T[0][i] = sorted[i];
		}
		sort(sorted + 1, sorted + 1 + n);
		build(0, 1, n);

		printf("Case #%d:\n", kase);
		int q; scanf("%d", &q);
		while(q--) {
			int l, r; scanf("%d%d", &l, &r);
			l++; r++;
			int k = (r - l) / 2 + 1;
			q_sum = 0;
			query(0, 1, n, l, r, k);
			LL ans = q_kth * k - q_sum;
			ans += (pre[r] - pre[l-1] - q_sum) - q_kth * (r - l + 1 - k);
			printf("%lld\n", ans);
		}
		printf("\n");
	}

	return 0;
}
