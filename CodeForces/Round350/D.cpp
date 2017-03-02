#include <cstdio>

const int maxn = 100000 + 10;
typedef long long LL;
int a[maxn], b[maxn];

int n, k;

bool ok(int x) {
	int left = k;
	for(int i = 0; i < n; i++) {
		LL need = (LL)a[i] * x;
		if(need > b[i]) {
			if(need - b[i] > left) return false;
			left -= need - b[i];
		}
	}
	return true;
}

int main()
{
	scanf("%d%d", &n, &k);
	for(int i = 0; i < n; i++) scanf("%d", a + i);
	for(int i = 0; i < n; i++) scanf("%d", b + i);

	int L = 0, R = (b[0] + k) / a[0];
	while(L < R) {
		int M = L + (R - L + 1) / 2;
		if(ok(M)) L = M;
		else R = M - 1;
	}

	printf("%d\n", L);

	return 0;
}
