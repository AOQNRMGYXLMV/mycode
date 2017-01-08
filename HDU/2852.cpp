#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 100000 + 10;
const int maxnode = (maxn << 5);

int n;

int sz, root[maxn];
int lch[maxnode], rch[maxnode], sum[maxnode];

int update(int pre, int L, int R, int p, int v) {
	int rt = ++sz;
	sum[rt] = sum[pre] + v;
	if(L < R) {
		int M = (L + R) / 2;
		if(p <= M) { rch[rt] = rch[pre]; lch[rt] = update(lch[pre], L, M, p, v); }
		else { lch[rt] = lch[pre]; rch[rt] = update(rch[pre], M+1, R, p, v); }
	}
	return rt;
}

int Qcnt(int rt, int L, int R, int p) {
	if(L == R) return sum[rt];
	int M = (L + R) / 2;
	if(p <= M) return Qcnt(lch[rt], L, M, p);
	else return Qcnt(rch[rt], M+1, R, p);
}

int Qsum(int rt, int L, int R, int p) {
	if(L == R) return sum[rt];
	int M = (L + R) / 2;
	if(p <= M) return Qsum(lch[rt], L, M, p);
	else return sum[lch[rt]] + Qsum(rch[rt], M+1, R, p);
}

int kth(int rt, int L, int R, int k) {
	if(L == R) return L;
	int num = sum[lch[rt]];
	int M = (L + R) / 2;
	if(num >= k) return kth(lch[rt], L, M, k);
	else return kth(rch[rt], M+1, R, k-num);
}

int main()
{
	while(scanf("%d", &n) == 1) {
		int cnt = 0;
		sz = 0;
		while(n--) {
			int op, a; scanf("%d%d", &op, &a);
			if(op == 0) {
				cnt++;
				root[cnt] = update(root[cnt-1], 1, maxn, a, 1);
			} else if(op == 1) {
				if(!Qcnt(root[cnt], 1, maxn, a)) puts("No Elment!");
				else {
					cnt++;
					root[cnt] = update(root[cnt-1], 1, maxn, a, -1);
				}
			} else {
				int b; scanf("%d", &b);
				int k = Qsum(root[cnt], 1, maxn, a);
				//printf("k1 = %d\n", k);
				k += b;
				//printf("k2 = %d\n", k);
				if(k > sum[root[cnt]]) { puts("Not Find!"); continue; }
				printf("%d\n", kth(root[cnt], 1, maxn, k));
			}
		}
	}

	return 0;
}
