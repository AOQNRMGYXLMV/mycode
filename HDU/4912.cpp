#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int maxn = 100000 + 10;

int n, m;

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

int pa[maxn];
int findset(int x) { return x == pa[x] ? x : pa[x] = findset(pa[x]); }

int fa[maxn], dep[maxn], lca[maxn];
int vis[maxn], kase;
vector<int> q[maxn];

struct Node
{
    int u, v, lca;
    void read() { scanf("%d%d", &u, &v); }
    bool operator < (const Node& t) const {
        return dep[lca] > dep[t.lca];
    }
}path[maxn];

void Tarjan(int u) {
    pa[u] = u;
    for(int i = head[u]; ~i; i = edges[i].nxt) {
        int v = edges[i].v;
        if(v == fa[u]) continue;
        fa[v] = u;
        dep[v] = dep[u] + 1;
        Tarjan(v);
        pa[v] = u;
    }
    for(int i : q[u]) if(~pa[path[i].v]) {
        path[i].lca = findset(path[i].v);
    }
}

bool check(int i) {
    int u = path[i].u, v = path[i].v, lca = path[i].lca;
    if(vis[lca] == kase) return false;
    while(u != lca) { if(vis[u] == kase) return false; u = fa[u]; }
    while(v != lca) { if(vis[v] == kase) return false; v = fa[v]; }
    return true;
}

void cover(int i) {
    int u = path[i].u, v = path[i].v, lca = path[i].lca;
    vis[lca] = kase;
    while(u != lca) { vis[u] = kase; u = fa[u]; }
    while(v != lca) { vis[v] = kase; v = fa[v]; }
}

//sxjing@chd.edu.cn

int main()
{
    while(scanf("%d%d", &n, &m) == 2) {
        kase++;
        memset(head, -1, sizeof(head));
        ecnt = 0;
        for(int i = 1; i < n; i++) {
            int u, v; scanf("%d%d", &u, &v);
            AddEdge(u, v);
            AddEdge(v, u);
        }
        for(int i = 1; i <= n; i++) q[i].clear();
        for(int i = 1; i <= m; i++) {
            path[i].read();
            q[path[i].u].push_back(i);
        }

        for(int i = 1; i <= n; i++) pa[i] = -1;
        Tarjan(1);

        sort(path + 1, path + 1 + m);
        int ans = 0;
        for(int i = 1; i <= m; i++) {
            if(!check(i)) continue;
            ans++;
            cover(i);
        }

        printf("%d\n", ans);
    }

    return 0;
}
