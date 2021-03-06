#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef unsigned long long LL;

const LL MOD = 9223372034707292160ULL;

LL add(LL a, LL b) { a += b; if(a >= MOD) a -= MOD; return a; }

LL mul(LL a, LL b) {
	LL ans = 0;
	while(b) {
		if(b & 1) ans = add(ans, a);
		a = add(a, a);
		b >>= 1;
	}
	return ans;
}

const int maxn = 100000 + 10;
const int maxnode = maxn * 4;

int n, m;

LL sumv[maxnode], mcnt[maxnode], s;

void build(int o, int L, int R) {
	if(L == R) {
		scanf("%llu", &sumv[o]);
		mcnt[o] = 0;
		return;
	}
	int M = (L + R) / 2;
	build(o<<1, L, M);
	build(o<<1|1, M+1, R);
	sumv[o] = add(sumv[o<<1], sumv[o<<1|1]);
	mcnt[o] = 0;
}

void query(int o, int L, int R, int qL, int qR) {
	if(qL <= L && R <= qR) {
		s = add(s, sumv[o]);
		return;
	}
	int M = (L + R) / 2;
	if(qL <= M) query(o<<1, L, M, qL, qR);
	if(qR > M) query(o<<1|1, M+1, R, qL, qR);
}

void update(int o, int L, int R, int qL, int qR) {
	if(mcnt[o] >= 30) return;
	if(L == R) {
		sumv[o] = mul(sumv[o], sumv[o]);
		mcnt[o]++;
		return;
	}
	int M = (L + R) / 2;
	if(qL <= M) update(o<<1, L, M, qL, qR);
	if(qR > M) update(o<<1|1, M+1, R, qL, qR);
	sumv[o] = add(sumv[o<<1], sumv[o<<1|1]);
	mcnt[o] = min(mcnt[o<<1], mcnt[o<<1|1]);
}

int main()
{
	int T; scanf("%d", &T);
	for(int kase = 1; kase <= T; kase++) {
		printf("Case #%d:\n", kase);
		scanf("%d%d", &n, &m);
		build(1, 1, n);
		s = 0;
		while(m--) {
			int qL, qR; scanf("%d%d", &qL, &qR);
			query(1, 1, n, qL, qR);
			update(1, 1, n, qL, qR);
			printf("%llu\n", s);
		}
	}

	return 0;
}
