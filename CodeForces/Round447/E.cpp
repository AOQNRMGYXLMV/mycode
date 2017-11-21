#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <stack>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
#define PB push_back
#define PII pair<int, int>
#define REP(i, a, b) for(int i = a; i < b; i++)
#define PER(i, a, b) for(int i = b - 1; i >= a; i--)
#define ALL(x) x.begin(), x.end()

namespace IO {
	#define BUF_SIZE 500000

    bool inline nc(char& c) {
        static char buf[BUF_SIZE], *p = buf + BUF_SIZE, *pend = buf + BUF_SIZE;
	        if(p == pend) {
	            p = buf;
	            pend = buf + fread(buf, 1, BUF_SIZE, stdin);
	            if(pend == buf) { c = ' '; return false; }
	        }
	        c = *p++;
	        return true;
	    }

	    bool read(int& x) {
	        char c = ' ';
	        x = 0;
	        while(c < '0' || c > '9') if(!nc(c)) return false;
	        while('0' <= c && c <= '9') { x = (x<<1)+(x<<3)+c-'0'; nc(c); }
	        return true;
	    }

	#undef BUF_SIZE
};

using namespace IO;

const int maxn = 1000000 + 10;

int n, m, s;
int pre[maxn];
int sccno[maxn];
LL val[maxn];

struct Edge {
	int v, nxt, w;
	Edge() {}
	Edge(int nxt, int v, int w): nxt(nxt), v(v), w(w) {}
};

struct Graph {
	int ecnt, head[maxn];
	Edge edges[maxn];
	void init() { ecnt = 0; memset(head, -1, sizeof(head)); }
	void addEdge(int u, int v, int w) {
		edges[ecnt] = Edge(head[u], v, w);
		head[u] = ecnt++;
	}
};

Graph G, G2;

LL calc(int w) {
	LL L = 0, R = 20000;
	while(L < R) {
		LL M = (L + R + 1) / 2;
		if(M * (M + 1) / 2 >= w) R = M - 1;
		else L = M;
	}
	return (L+1)*w - (L*(L+1)*(L*2+1)/6+L*(L+1)/2)/2;
}

int dfs_clock, scc_cnt;
int S[maxn], top;
int dfs(int u) {
	pre[u] = ++dfs_clock;
	int lowu = dfs_clock;
	S[++top] = u;
	for(int i = G.head[u]; ~i; i = G.edges[i].nxt) {
		int v = G.edges[i].v;
		if(!pre[v]) {
			lowu = min(lowu, dfs(v));
		} else if(!sccno[v]) lowu = min(lowu, pre[v]);
	}

	if(lowu >= pre[u]) {
		scc_cnt++;
		for(;;) {
			int x = S[top--];
			sccno[x] = scc_cnt;
			if(x == u) break;
		}
	}

	return lowu;
}

LL d[maxn];
LL dp(int u) {
	if(d[u] != -1) return d[u];
	LL& ans = d[u];
	ans = 0;
	for(int i = G2.head[u]; ~i; i = G2.edges[i].nxt) {
		Edge& e = G2.edges[i];
		ans = max(ans, dp(e.v) + e.w);
	}
	ans += val[u];
	return ans;
}

int main() {
	read(n); read(m);
	G.init();
	while(m--) {
		int u, v, w; read(u); read(v); read(w);
		G.addEdge(u, v, w);
	}
	read(s);

	REP(i, 1, n + 1) if(!pre[i]) dfs(i);
	G2.init();
	REP(u, 1, n + 1) for(int i = G.head[u]; ~i; i = G.edges[i].nxt) {
		Edge& e = G.edges[i];
		int& v = e.v, &w = e.w;
		if(sccno[u] == sccno[v]) val[sccno[u]] += calc(w);
		else G2.addEdge(sccno[u], sccno[v], w);
	}

	memset(d, -1, sizeof(d));
	printf("%lld\n", dp(sccno[s]));

	return 0;
}

