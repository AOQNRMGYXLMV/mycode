#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long LL;

int A, n, k;
const int maxk = 30000;
const int maxa = 11;

LL d[1 << maxa][maxk];

int bitcount(int x) {
	int ans = 0;
	while(x) { if(x & 1) ans++; x >>= 1; }
	return ans;
}

bool vis[maxa + 5];

bool check(LL x) {
	int S = 0;
	while(x) {
		int t = x % A;
		x /= A;
		if(S & (1 << t)) return false;
		S |= (1 << t);
	}
	return true;
}

int main()
{
	int T; scanf("%d", &T);
	while(T--) {
		scanf("%d%d%d", &A, &n, &k);

		if(n == 0) {
			if(k == 1) printf("1\n");
			else printf("0\n");
			continue;
		}
		if(n == 1) {
			printf("%d\n", A / k);
			continue;
		}

		//DP
		if(k < maxk) {
			memset(d, 0, sizeof(d));
			for(int i = 1; i < A; i++) d[1 << i][i % k] = 1;
			for(int S = 0; S < (1 << A); S++) if(bitcount(S) < n) {
				for(int x = 0; x < k; x++) if(d[S][x]) {
					for(int i = 0; i < A; i++) if(!(S&(1<<i))) {
						d[S|(1<<i)][(x*A+i)%k] += d[S][x];
					}
				}
			}
			LL ans = 0;
			for(int S = 0; S < (1 << A); S++)
				if(d[S][0]) ans += d[S][0];
			printf("%lld\n", ans);
		} else {
	    	if(n > A) n = A;
	    	LL An = 1; //A^n
    		for(int i = 1; i <= n; i++) An *= A;
			LL ans = 0;
			for(LL t = k; t <= An; t += k)
				if(check(t)) ans++;
			printf("%lld\n", ans);
		}
	}

	return 0;
}
