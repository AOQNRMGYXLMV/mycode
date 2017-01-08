#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long LL;

const int maxn = 2000 + 10;
const LL MOD = 1000000007;

LL mul(LL a, LL b) { return a * b % MOD; }

LL add(LL a, LL b) { a += b; if(a >= MOD) a -= MOD; return a; }

LL d[maxn][4];

int main()
{
	d[1][1] = 26;
	for(int i = 2; i <= 2000; i++) {
		d[i][1] = mul(add(d[i-1][1], add(d[i-1][2], d[i-1][3])), 25);
		for(int j = 2; j <= 3; j++)
			d[i][j] = d[i-1][j-1];
	}
	int T; scanf("%d", &T);
	while(T--) {
		int n; scanf("%d", &n);
		LL ans = 0;
		for(int i = 1; i <= 3; i++)
			ans = add(ans, d[n][i]);
		printf("%lld\n", ans);
	}

	return 0;
}
