#include <cstdio>

typedef long long LL;
const int maxn = 200000 + 10;
const LL MOD = 1000000007LL;

LL pow_mod(LL a, int p) {
	LL ans = 1;
	while(p) {
		if(p & 1) ans = ans * a % MOD;
		a = a * a % MOD;
		p >>= 1;
	}
	return ans;
}

LL add(LL a, LL b) { a += b; if(a >= MOD) a -= MOD; return a; }

int to[maxn], dep[maxn];
int vis[maxn];
LL ans = 1, cycle;

void dfs(int u, int d, int tag) {
	vis[u] = tag;
	dep[u] = d;
	if(!vis[to[u]]) dfs(to[u], d + 1, tag);
	else if(vis[to[u]] == tag){
		int t = d - dep[to[u]] + 1;
		ans = ans * add(pow_mod(2, t), MOD - 2) % MOD;
		cycle += t;
	}
}

int main()
{
	int n; scanf("%d", &n);

	for(int i = 1; i <= n; i++) scanf("%d", to + i);
	for(int i = 1; i <= n; i++) if(!vis[i]) dfs(i, 1, i);
	ans = ans * pow_mod(2, n - cycle) % MOD;
	printf("%lld\n", ans);

	return 0;
}
