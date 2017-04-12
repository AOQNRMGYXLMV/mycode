#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <set>
#include <vector>
#include <iostream>
#include <string>
#include <queue>
using namespace std;
#define REP(i, a, b) for(int i = a; i < b; i++)
#define PER(i, a, b) for(int i = b - 1; i >= a; i--)
#define SZ(a) ((int)a.size())
#define MP make_pair
#define PB push_back
#define EB emplace_back
#define ALL(a) a.begin(), a.end()
typedef long long LL;
typedef pair<LL, int> PII;

const int maxn = 100000 + 10;

int n, q, s;

struct Edge {
	int v, w, nxt;
	Edge() {}
	Edge(int v, int w, int nxt): v(v), w(w), nxt(nxt) {}
};

int ecnt, head[maxn * 9];
Edge edges[maxn * 36];

void AddEdge(int u, int v, int w) {
	edges[ecnt] = Edge(v, w, head[u]);
	head[u] = ecnt++;
}

int tot, T[2][maxn << 2];
void build(int t, int o, int L, int R) {
	T[t][o] = ++tot;
	if(L == R) {
		if(0 == t) AddEdge(T[t][o], L, 0);
		else AddEdge(L, T[t][o], 0);
		return;
	}
	int M = (L + R) / 2;
	build(t, o<<1, L, M);
	build(t, o<<1|1, M+1, R);
	if(0 == t) {
		AddEdge(T[t][o], T[t][o<<1], 0);
		AddEdge(T[t][o], T[t][o<<1|1], 0);
	} else {
		AddEdge(T[t][o<<1], T[t][o], 0);
		AddEdge(T[t][o<<1|1], T[t][o], 0);
	}
}

int type, v, qL, qR, w;

void update(int o, int L, int R) {
	if(qL <= L && R <= qR) {
		if(0 == type) AddEdge(v, T[type][o], w);
		else AddEdge(T[type][o], v, w);
		return;
	}
	int M = (L + R) / 2;
	if(qL <= M) update(o<<1, L, M);
	if(qR > M) update(o<<1|1, M+1, R);
}

const LL INF = 0x3f3f3f3f3f3f3f3f;
bool vis[maxn * 9];
LL d[maxn * 9];

priority_queue<PII, vector<PII>, greater<PII> > Q;
void dijkstra() {
	memset(d, 0x3f, sizeof(d));
	d[s] = 0;
	Q.emplace(0, s);
	while(!Q.empty()) {
		PII t = Q.top(); Q.pop();
		int& u = t.second;
		if(vis[u]) continue;
		vis[u] = true;
		for(int i = head[u]; ~i; i = edges[i].nxt) {
			int& v = edges[i].v;
			int& w = edges[i].w;
			if(d[v] > d[u] + w) {
				d[v] = d[u] + w;
				Q.emplace(d[v], v);
			}
		}
	}
}

int main() {
	scanf("%d%d%d", &n, &q, &s);
	memset(head, -1, sizeof(head));
	tot = n;
	REP(t, 0, 2) build(t, 1, 1, n);

	while(q--) {
		scanf("%d%d%d", &type, &v, &qL);
		if(type == 1) {
			scanf("%d", &w);
			AddEdge(v, qL, w);
		} else {
			type -= 2;
			scanf("%d%d", &qR, &w);
			update(1, 1, n);
		}
	}

	dijkstra();
	REP(i, 1, n + 1) printf("%lld ", d[i] == INF ? -1 : d[i]);
	printf("\n");

	return 0;
}

