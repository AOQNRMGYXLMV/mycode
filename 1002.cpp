#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
 
const int maxn = 100000 + 10;
const int maxnode = maxn * 4;
 
struct Edge
{
    int v, nxt;
    Edge() {}
    Edge(int v, int nxt):v(v), nxt(nxt) {}
};
 
int n, m;
int u[maxn], v[maxn], w[maxn];
int color[maxn];
 
int ecnt, head[maxn];
Edge edges[maxn * 2];
 
void AddEdge(int u, int v) {
    edges[ecnt] = Edge(v, head[u]);
    head[u] = ecnt++;
    edges[ecnt] = Edge(u, head[v]);
    head[v] = ecnt++;
}
 
int fa[maxn], dep[maxn], sz[maxn], son[maxn];
int tot, top[maxn], id[maxn], pos[maxn];
 
void dfs(int u) {
    sz[u] = 1; son[u] = 0;
    for(int i = head[u]; ~i; i = edges[i].nxt) {
        int v = edges[i].v;
        if(v == fa[u]) continue;
        dep[v] = dep[u] + 1;
        fa[v] = u;
        dfs(v);
        sz[u] += sz[v];
        if(sz[v] > sz[son[u]]) son[u] = v;
    }
}
 
void dfs2(int u, int tp) {
    id[u] = tot;
    pos[tot++] = u;
    top[u] = tp;
    if(!son[u]) return;
    dfs2(son[u], tp);
    for(int i = head[u]; ~i; i = edges[i].nxt) {
        int v = edges[i].v;
        if(v == fa[u] || v == son[u]) continue;
        dfs2(v, v);
    }
}

struct Node
{
    int lcol, rcol, cntv;
 
    Node() {}
 
    Node(int l, int r, int c): lcol(l), rcol(r), cntv(c) {}
};
 
void reverse(Node& t) { swap(t.lcol, t.rcol); }
 
Node operator + (const Node& a, const Node& b) {
    if(!a.cntv) return b; if(!b.cntv) return a;
    return Node(a.lcol, b.rcol, a.cntv + b.cntv - 1 + (a.rcol != b.lcol));
}
 
int setv[maxnode];
Node t[maxnode];
 
void build(int o, int L, int R) {
    setv[o] = -1;
    if(L == R) {
        t[o].cntv = 1;
        t[o].lcol = t[o].rcol = color[pos[L]];
        return;
    }
    int M = (L + R) / 2;
    build(o<<1, L, M);
    build(o<<1|1, M+1, R);
    t[o] = t[o<<1] + t[o<<1|1];
}
 
void pushdown(int o) {
    if(setv[o] != -1) {
        setv[o<<1] = setv[o<<1|1] = setv[o];
        t[o<<1].cntv = t[o<<1|1].cntv = 1;
        t[o<<1].lcol = t[o<<1].rcol = t[o<<1|1].lcol = t[o<<1|1].rcol = setv[o];
        setv[o] = -1;
    }
}
 
void update(int o, int L, int R, int qL, int qR, int v) {
    if(qL <= L && R <= qR) {
        t[o].lcol = t[o].rcol = setv[o] = v;
        t[o].cntv = 1;
        return;
    }
    pushdown(o);
    int M = (L + R) / 2;
    if(qL <= M) update(o<<1, L, M, qL, qR, v);
    if(qR > M) update(o<<1|1, M+1, R, qL, qR, v);
    t[o] = t[o<<1] + t[o<<1|1];
}
 
void UPDATE(int u, int v, int val) {
    int t1 = top[u], t2 = top[v];
    while(t1 != t2) {
        if(dep[t1] < dep[t2]) { swap(u, v); swap(t1, t2); }
        update(1, 1, n - 1, id[t1], id[u], val);
        u = fa[t1]; t1 = top[u];
    }
    if(dep[u] > dep[v]) swap(u, v);
    if(u != v) update(1, 1, n - 1, id[son[u]], id[v], val);
}
 
Node query(int o, int L, int R, int qL, int qR) {
    Node ans(0, 0, 0);
    if(qL <= L && R <= qR) return t[o];
    pushdown(o);
    int M = (L + R) / 2;
    if(qL <= M) ans = ans + query(o<<1, L, M, qL, qR);
    if(qR > M) ans = ans + query(o<<1|1, M+1, R, qL, qR);
    return ans;
}
 
int QUERY(int u, int v) {
    Node q1(0, 0, 0), q2(0, 0, 0), tmp;
    int t1 = top[u], t2 = top[v];
    while(t1 != t2) {
        if(dep[t1] > dep[t2]) {
            tmp = query(1, 1, n - 1, id[t1], id[u]);
            reverse(tmp);
            q1 = q1 + tmp;
            u = fa[t1];
            t1 = top[u];
        } else {
            tmp = query(1, 1, n - 1, id[t2], id[v]);
            reverse(tmp);
            q2 = q2 + tmp;
            v = fa[t2];
            t2 = top[v];
        }
    }
    if(dep[u] > dep[v]) {
        tmp = query(1, 1, n - 1, id[son[v]], id[u]);
        reverse(tmp);
        q1 = q1 + tmp;
    } else if(u != v) {
        tmp = query(1, 1, n - 1, id[son[u]], id[v]);
        reverse(tmp);
        q2 = q2 + tmp;
    }
 
    reverse(q2);
    q1 = q1 + q2;
    return q1.cntv;
}

void debug() {
	//for(int i = 1; i <= n; i++) printf("id[%d] = %d\n", i, id[i]);
	//for(int i = 1; i <= n; i++) printf("fa[%d] = %d\n", i, fa[i]);
	for(int i = 2; i <= n; i++) printf("color[%d] = %d\n", i, color[i]);
}

int main()
{
    while(scanf("%d%d", &n, &m) == 2) {
 
    ecnt = 0;
    memset(head, -1, sizeof(head));
    for(int i = 1; i < n; i++) {
        scanf("%d%d%d", u + i, v + i, w + i);
        AddEdge(u[i], v[i]);
    }
 
    dfs(1);
    tot = 0;
    dfs2(1, 1);
    //u[i] is the son
    for(int i = 1; i < n; i++) {
        if(dep[u[i]] < dep[v[i]]) swap(u[i], v[i]);
        color[u[i]] = w[i];
    }

	//debug();

    build(1, 1, n - 1);
 
    char cmd[15];
    int a, b, c;
    while(m--) {
        scanf("%s", cmd);
        scanf("%d%d", &a, &b);
        if(cmd[0] == 'C') {
            scanf("%d", &c);
            UPDATE(a, b, c);
        } else {
            if(a == b) { printf("0\n"); continue; }
            printf("%d\n", QUERY(a, b));
        }
    }
    }
 
    return 0;
}
