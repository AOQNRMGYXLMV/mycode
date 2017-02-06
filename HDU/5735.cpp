#include <cstdio>
#include <cstring>
#include <algorithm>
using std::max;

#define low(x) (x&((1<<8)-1))
#define high(x) (x>>8)
const int maxn = 1 << 16;
const int MOD = 1000000007;
typedef long long LL;
typedef unsigned int UINT;

int n, w[maxn];
char op[5];

inline UINT OPT(UINT a, UINT b) {
	if(op[0] == 'A') return a&b;
	if(op[0] == 'X') return a^b;
	return a|b;
}

inline void add(LL& a, LL b) { a += b; if(a >= MOD) a -= MOD; }

LL mul(LL a, LL b) { return a * b % MOD; }

UINT ds[1 << 8][1 << 8];
UINT d[maxn];
UINT mem[maxn][8], pointer;

struct Edge
{
	int v, nxt;
	Edge() {}
	Edge(int v, int nxt): v(v), nxt(nxt) {}
};

int ecnt, head[maxn];
Edge edges[maxn];

void AddEdge(int u, int v) {
	edges[ecnt] = Edge(v, head[u]);
	head[u] = ecnt++;
}

void dfs(int u) {
	UINT a = high(w[u]), b = low(w[u]);
	if(u) {
		for(UINT x = 0; x < (1 << 8); x++) {
			d[u] = max(d[u], ds[x][b] + (OPT(a, x) << 8));
		}
	}
	memcpy(mem[pointer], ds[a], sizeof(ds[0]));
	pointer++;
	for(UINT y = 0; y < (1 << 8); y++) {
		ds[a][y] = max(ds[a][y], OPT(b, y));
	}
	for(int i = head[u]; ~i; i = edges[i].nxt)
		dfs(edges[i].v);
	pointer--;
	memcpy(ds[a], mem[pointer], sizeof(ds[0]));
}

int main()
{
	int T; scanf("%d", &T);
	while(T--) {
		scanf("%d%s", &n, op);
		for(int i = 0; i < n; i++) scanf("%d", w + i);

		ecnt = 0;
		memset(head, -1, sizeof(head));
		for(int i = 1; i < n; i++) {
			int fa; scanf("%d", &fa); fa--;
			AddEdge(fa, i);
		}
		
		pointer = 0;
		dfs(0);

		LL ans = 0;
		for(int i = 0; i < n; i++) {
			d[i] %= MOD;
			add(ans, mul(i + 1, (d[i] + w[i]) % MOD));
		}
		printf("%lld\n", ans);
	}

	return 0;
}
