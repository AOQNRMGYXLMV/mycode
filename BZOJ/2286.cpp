#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
#define MP make_pair
#define PB push_back
#define REP(i, a, b) for(int i = a; i < b; i++)
#define PER(i, a, b) for(int i = b - 1; i >= a; i--)
  
const int maxn = 250000 + 10;
  
void read(int& x) {
    x = 0;
    char c = ' ';
    while(c < '0' || c > '9') c = getchar();
    while('0' <= c && c <= '9') { x = (x<<3)+(x<<1)+(c-'0'); c = getchar(); }
}

void read(LL& x) {
    x = 0;
    char c = ' ';
    while(c < '0' || c > '9') c = getchar();
    while('0' <= c && c <= '9') { x = (x<<3)+(x<<1)+(c-'0'); c = getchar(); }
}

struct Edge {
    int v, nxt;
    LL w;
    Edge() {}
    Edge(int v, LL w, int nxt): v(v), w(w), nxt(nxt) {}
};
  
int n, m;
int head[maxn], ecnt;
Edge edges[maxn << 1];
  
void addEdge(int u, int v, LL w) {
    edges[ecnt] = Edge(v, w, head[u]);
    head[u] = ecnt++;
    edges[ecnt] = Edge(u, w, head[v]);
    head[v] = ecnt++;
}

int dfs_clock;
int son[maxn], dep[maxn], sz[maxn], pre[maxn], fa[maxn];
LL minv[maxn];
  
void dfs(int u) {
    sz[u] = 1;
    son[u] = 0;
    pre[u] = ++dfs_clock;
    for(int i = head[u]; ~i; i = edges[i].nxt) {
        int& v = edges[i].v;
        if(v == fa[u]) continue;
        dep[v] = dep[u] + 1;
        fa[v] = u;
        minv[v] = min(minv[u], edges[i].w);
        dfs(v);
        if(sz[v] > sz[son[u]]) son[u] = v;
        sz[u] += sz[v];
    }
}
  
int top[maxn];
void dfs2(int u, int t = 1) {
    top[u] = t;
    if(son[u]) dfs2(son[u], t);
    for(int i = head[u]; ~i; i = edges[i].nxt) {
        int& v = edges[i].v;
        if(v == son[u] || v == fa[u]) continue;
        dfs2(v, v);
    }
}
  
int LCA(int u, int v) {
    while(top[u] != top[v]) {
        if(dep[top[u]] < dep[top[v]]) swap(u, v);
        u = fa[top[u]];
    }
    return dep[u] < dep[v] ? u : v;
}
  
bool mark[maxn];
int a[maxn];
bool cmp(int u, int v) { return pre[u] < pre[v]; }
int S[maxn], tot;
vector<int> G[maxn];
  
void init() {
    dfs_clock = ecnt = tot = 0;
    memset(head, -1, sizeof(head));
}
  
LL dp(int u = 1) {
    LL ans = 0;
    for(int i = 0; i < (int)G[u].size(); i++) {
        int v = G[u][i];
        ans += dp(v);
    }
    G[u].clear();
    if(mark[u]) return minv[u];
    return min(minv[u], ans);
}
  
int main() {
    read(n);
    init();
    REP(i, 1, n) {
        int u, v, w; read(u); read(v); read(w);
        addEdge(u, v, w);
    }
  
    minv[1] = 1LL << 60;
    dfs(1);
    dfs2(1);
  
    read(m);
    while(m--) {
        int k; read(k);
        REP(i, 0, k) { read(a[i]); mark[a[i]] = true; }
        sort(a, a + k, cmp);
        S[tot = 1] = 1;
        REP(i, 0, k) {
            int lca = LCA(a[i], S[tot]);
            while(tot > 1 && pre[S[tot-1]] > pre[lca]) {
                G[S[tot-1]].PB(S[tot]);
                tot--;
            }
            if(tot && pre[S[tot]] > pre[lca]) { G[lca].PB(S[tot]); tot--; }
            if(tot && S[tot] != lca) S[++tot] = lca;
            S[++tot] = a[i];
        }
        while(tot > 1) { G[S[tot-1]].PB(S[tot]); tot--; }
        printf("%lld\n", dp());
        REP(i, 0, k) mark[a[i]] = false;
    }
 
    return 0;
}