#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#define MP make_pair
#define F first
#define S second
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<int, LL> PLL;
const int maxn = 30000 + 10;
const int INF = 0x3f3f3f3f;

int n, m, k;

vector<PII> G[maxn];

int d[maxn];
bool inq[maxn];

void SPFA(int s) {
    queue<int> Q;
    Q.push(s);
    memset(inq, false, sizeof(inq));
    inq[s] = true;
    memset(d, 0x3f, sizeof(d));
    d[s] = 0;

    while(!Q.empty()) {
        int u = Q.front(); Q.pop(); inq[u] = false;
        for(int i = 0; i < G[u].size(); i++) {
            PII& e = G[u][i];
            int v = e.first, w = e.second;
            if(d[u] + w < d[v]) {
                d[v] = d[u] + w;
                if(!inq[v]) { Q.push(v); inq[v] = true; }
            }
        }
    }
}

struct Edge
{
    int v, w, nxt;
    Edge() {}
    Edge(int v, int w, int nxt): v(v), w(w), nxt(nxt) {}
};

int ecnt, head[maxn];
Edge edges[maxn * 2];

void AddEdge(int u, int v, int w) {
    edges[ecnt] = Edge(v, w, head[u]);
    head[u] = ecnt++;
}

void build(int u) {
    inq[u] = true;
    for(int i = 0; i < G[u].size(); i++) {
        PII& e = G[u][i];
        int v = e.first, w = e.second;
        if(inq[v]) continue;
        if(d[v] == d[u] + w) {
            AddEdge(u, v, w);
            AddEdge(v, u, w);
            build(v);
        }
    }
}

int fa[maxn], sz[maxn];
bool del[maxn];

void dfs(int u) {
    sz[u] = 1;
    for(int i = head[u]; ~i; i = edges[i].nxt) {
        int v = edges[i].v;
        if(v == fa[u] || del[v]) continue;
        fa[v] = u;
        dfs(v);
        sz[u] += sz[v];
    }
}

PII findCenter(int u, int t) {
    PII ans(INF, -1);
    int m = t - sz[u];
    for(int i = head[u]; ~i; i = edges[i].nxt) {
        int v = edges[i].v;
        if(v == fa[u] || del[v]) continue;
        m = max(m, sz[v]);
        ans = min(ans, findCenter(v, t));
    }
    ans = min(ans, MP(m, u));
    return ans;
}

const PLL O(0, 0);
PLL ans, f[maxn], f2[maxn], tmp[maxn];
int has[maxn], dep[maxn], tot, Md;

void update(PLL& a, PLL b) {
	if(b.F > a.F) a = b;
	else if(b.F == a.F) a.S += b.S;
}

void getMdep(int u, int p, int d) {
	if(d > Md) Md = d;
	if(Md >= k - 1) return;
	for(int i = head[u]; ~i; i = edges[i].nxt) {
		int v = edges[i].v;
		if(del[v] || v == p) continue;
		getMdep(v, u, d + 1);
	}
}

void getdist(int u, int p, int c, int d) {
	update(f2[c], MP(d, 1LL));
    if(c == k - 1) { update(ans, MP(d, 1LL)); return; }
    for(int i = head[u]; ~i; i = edges[i].nxt) {
        int v = edges[i].v, w = edges[i].w;
        if(del[v] || v == p) continue;
        getdist(v, u, c + 1, d + w);
    }
}

void solve(int u) {
    fa[u] = 0;
    dfs(u);
    int s = findCenter(u, sz[u]).S;
    del[s] = true;

	tot++;
    for(int i = head[s]; ~i; i = edges[i].nxt) {
        int v = edges[i].v, w = edges[i].w;
		if(del[v]) continue;
        Md = -1; getMdep(v, s, 1);
		Md = min(Md, k - 2);
		for(int i = 1; i <= Md; i++) f2[i] = O;
		getdist(v, s, 1, w);
		for(int j = 1; j <= Md; j++) {
			int j2 = k - 1 - j;
			if(j2 < 1 || has[j2] != tot) continue;
			update(ans, MP(f2[j].F + f[j2].F, f2[j].S * f[j2].S));
		}

        for(int i = 1; i <= Md; i++) {
			if(has[i] == tot) update(f[i], f2[i]);
			else { has[i] = tot; f[i] = f2[i]; }
		}
			
    }

    for(int i = head[s]; ~i; i = edges[i].nxt) {
        int v = edges[i].v;
        if(del[v]) continue;
        solve(v);
    }
	del[s] = false;
}

int main()
{
    int _; scanf("%d", &_);
    while(_--) {
        scanf("%d%d%d", &n, &m, &k);
        for(int i = 1; i <= n; i++) G[i].clear();
        for(int i = 0; i < m; i++) {
            int u, v, w; scanf("%d%d%d", &u, &v, &w);
            G[u].emplace_back(v, w);
            G[v].emplace_back(u, w);
        }
        SPFA(1);

        //build tree
        ecnt = 0;
        memset(head, -1, sizeof(head));
        memset(inq, false, sizeof(inq));
        for(int i = 1; i <= n; i++) sort(G[i].begin(), G[i].end());
        build(1);

        ans = O;
		memset(has, 0, sizeof(has));
		tot = 0;
        solve(1);

		printf("%d %lld\n", ans.F, ans.S);
    }

    return 0;
}
