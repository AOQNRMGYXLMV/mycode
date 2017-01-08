#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long LL;
const int maxn = 100000 + 10;

struct Edge
{
    int v, nxt;
	Edge() {}
	Edge(int v, int nxt): v(v), nxt(nxt) {}
};

int ecnt, head[maxn];
Edge edges[maxn * 2];

void AddEdge(int u, int v) {
    edges[ecnt] = Edge(v, head[u]);
    head[u] = ecnt++;
}

int n, m;
int u[maxn],v[maxn];
int fa[maxn], dep[maxn];

LL sum1[maxn], sum2[maxn];

void dfs(int u) {
    for(int i = head[u]; ~i; i = edges[i].nxt) {
        int v = edges[i].v;
        if(v == fa[u]) continue;
        fa[v] = u;
        dep[v] = dep[u] + 1;
        dfs(v);
    }
}

int anc[maxn][20];

void preprocess() {
    memset(anc, 0, sizeof(anc));
    for(int i = 1; i <= n; i++) anc[i][0] = fa[i];
    for(int j = 1; (1 << j) < n; j++)
        for(int i = 1; i <= n; i++) if(anc[i][j-1])
            anc[i][j] = anc[anc[i][j-1]][j-1];
}

int LCA(int u, int v) {
    if(dep[u] < dep[v]) swap(u, v);
    int log;
    for(log = 0; (1 << log) < dep[u]; log++);
    for(int i = log; i >= 0; i--)
        if(dep[u] - (1<<i) >= dep[v])
            u = anc[u][i];
    if(u == v) return u;
    for(int i = log; i >= 0; i--)
        if(anc[u][i] && anc[u][i] != anc[v][i])
            u = anc[u][i], v = anc[v][i];
    return fa[u];
}

void dfs2(int u) {
    for(int i = head[u]; ~i; i = edges[i].nxt) {
        int v = edges[i].v;
        if(v == fa[u]) continue;
        dfs2(v);
        sum1[u] += sum1[v];
        sum2[u] += sum2[v];
    }
}

int main()
{
    int T; scanf("%d", &T);
    for(int kase = 1; kase <= T; kase++) {
        scanf("%d%d", &n, &m);
        
        ecnt = 0;
		memset(fa, 0, sizeof(fa));
		memset(dep, 0, sizeof(dep));
        memset(head, -1, sizeof(head));
        for(int i = 1; i < n; i++) {
            scanf("%d%d", u + i, v + i);
            AddEdge(u[i], v[i]);
            AddEdge(v[i], u[i]);
        }
        dfs(1);
        preprocess();
        
        memset(sum1, 0, sizeof(sum1));
        memset(sum2, 0, sizeof(sum2));
        while(m--) {
            char op[10]; int a, b, k;
            scanf("%s", op);
            scanf("%d%d%d", &a, &b, &k);
            int lca = LCA(a, b);
            if(op[3] == '1') {
                sum1[a] += k;
                sum1[b] += k;
                sum1[lca] -= k;
                if(lca != 1) sum1[fa[lca]] -= k;
            } else {
                sum2[a] += k;
                sum2[b] += k;
                sum2[lca] -= k * 2;
            }
        }
        
        dfs2(1);
        for(int i = 1; i < n; i++)
            if(dep[u[i]] < dep[v[i]])
                swap(u[i], v[i]);
        
        printf("Case #%d:\n", kase);
        for(int i = 1; i < n; i++) printf("%lld ", sum1[i]);
        printf("%lld\n", sum1[n]);
		if(n == 1) { puts(""); continue; }
        for(int i = 1; i < n - 1; i++)
            printf("%lld ", sum2[u[i]]);
        printf("%lld\n", sum2[u[n-1]]);
    }
    
    return 0;
} 
