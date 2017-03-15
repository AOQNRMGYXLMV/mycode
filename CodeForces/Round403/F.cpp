#include <cstdio>
#include <bitset>
using namespace std;

const int maxn = 500;
const int maxlog = 61;
typedef long long LL;

LL go[maxlog][2][maxn];
bitset<maxn> arrive[maxlog][2][maxn];

void max(LL& a, LL b) { if(b > a) a = b; }

int main()
{
	int n, m; scanf("%d%d", &n, &m);
	while(m--) {
		int u, v, t; scanf("%d%d%d", &u, &v, &t);
		u--; v--;
		go[0][t][u] = 1;
		arrive[0][t][u][v] = 1;
	}

	for(int i = 0; i + 1 < maxlog; i++) {
		for(int t = 0; t < 2; t++) {
			for(int u = 0; u < n; u++) {
				go[i+1][t][u] = go[i][t][u];
				for(int v = 0; v < n; v++) if(arrive[i][t][u][v]) {
					arrive[i+1][t][u] |= arrive[i][t^1][v];
					max(go[i+1][t][u], (1LL << i) + go[i][t^1][v]);
				}
			}
		}
	}

	const LL limit = 1000000000000000000LL;
	LL& ans = go[maxlog - 1][0][0];
	if(ans > limit) puts("-1");
	else printf("%lld\n", ans);

	return 0;
}
