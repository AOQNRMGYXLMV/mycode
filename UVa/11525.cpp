#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 50000 + 10;
const int maxnode = maxn * 4;

int n, S[maxn];
int cntv[maxnode];

void pushup(int o) {
	cntv[o] = cntv[o<<1] + cntv[o<<1|1];
}

void build(int o, int L, int R) {
	if(L == R) { cntv[o] = 1; return; }
	int M = (L + R) / 2;
	build(o<<1, L, M);
	build(o<<1|1, M+1, R);
	pushup(o);
}

void query(int o, int L, int R, int s) {
	if(L == R) {
		printf("%d", L);
		cntv[o] = 0;
		return;
	}
	int M = (L + R) / 2;
	if(cntv[o<<1] >= s) query(o<<1, L, M, s);
	else query(o<<1|1, M+1, R, s - cntv[o<<1]);
	pushup(o);
}

int main()
{
	int T; scanf("%d", &T);
	while(T--) {
		scanf("%d", &n);
		build(1, 1, n);
		for(int i = 0; i < n; i++) {
			int s; scanf("%d", &s);
			query(1, 1, n, s + 1);
			if(i < n - 1) printf(" ");
			else printf("\n");
		}
	}

	return 0;
}

