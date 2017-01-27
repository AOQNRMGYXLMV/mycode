#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;

const int maxn = 100000 + 10;

int gcd(int a, int b) { return !b ? a : gcd(b, a%b); }

int n, m, a[maxn], ql[maxn], qr[maxn], g[maxn];

int d[maxn][20];

int query(int i, int j) {
	int k = 0;
	while((1<<(k+1)) <= j-i+1) k++;
	return gcd(d[i][k], d[j-(1<<k)+1][k]);
}

map<int, long long> ans;

int main()
{
	int T; scanf("%d", &T);
	for(int kase = 1; kase <= T; kase++) {
		scanf("%d", &n);
		for(int i = 0; i < n; i++) {
			scanf("%d", a + i);
			d[i][0] = a[i];
		}
		for(int j = 1; (1 << j) <= n; j++) {
			for(int i = 0; i + (1<<j) - 1 < n; i++) {
				d[i][j] = gcd(d[i][j-1], d[i+(1<<(j-1))][j-1]);
			}
		}

		ans.clear();
		scanf("%d", &m);
		for(int i = 0; i < m; i++) {
			scanf("%d%d", ql + i, qr + i);
			ql[i]--; qr[i]--;
			g[i] = query(ql[i], qr[i]);
			ans[g[i]] = 0;
		}

		for(int i = 0; i < n; i++) {
			for(int j = i; j < n; j++) {
				int g = query(i, j);
				int L = j, R = n - 1;
				while(L < R) {
					int M = (L + R + 1) / 2;
					if(query(i, M) < g) R = M - 1;
					else L = M;
				}
				if(ans.count(g)) ans[g] += L - j + 1;
				j = L;
			}
		}

		printf("Case #%d:\n", kase);
		for(int i = 0; i < m; i++) {
			printf("%d %lld\n", g[i], ans[g[i]]);
		}
	}
	

	return 0;
}
