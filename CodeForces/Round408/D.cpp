#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <set>
#include <vector>
#include <iostream>
#include <string>
using namespace std;
#define REP(i, a, b) for(int i = a; i < b; i++)
#define PER(i, a, b) for(int i = b - 1; i >= a; i--)
#define SZ(a) ((int)a.size())
#define MP make_pair
#define PB push_back
#define EB emplace_back
#define ALL(a) a.begin(), a.end()
typedef long long LL;
typedef pair<int, int> PII;

const int maxn = 300000 + 10;

struct Edge {
	int v, id, nxt;
	Edge() {}
	Edge(int v, int id, int nxt): v(v), id(id), nxt(nxt) {}
};

int n, k, d;
int head[maxn], ecnt;
Edge edges[maxn * 2];

void AddEdge(int u, int v, int id) {
	edges[ecnt] = Edge(v, id, head[u]);
	head[u] = ecnt++;
	edges[ecnt] = Edge(u, id, head[v]);
	head[v] = ecnt++;
}

int police[maxn];
bool vis[maxn];
int Q[maxn], q;
bool ans[maxn];

void BFS() {
	REP(i, 0, q) {
		int& u = Q[i];
		for(int i = head[u]; ~i; i = edges[i].nxt) {
			int& v = edges[i].v;
			if(police[v] == police[u]) continue;
		   	if(police[v]) { ans[edges[i].id] = true; continue; }
			police[v] = police[u];
			Q[q++] = v;
		}
	}
}

int main() {
	scanf("%d%d%d", &n, &k, &d);
	int cnt = 0;
	while(k--) {
		int p; scanf("%d", &p);
		if(!police[p]) { police[p] = p; cnt++; Q[q++] = p; }
	}

	memset(head, -1, sizeof(head));
	REP(i, 1, n) {
		int u, v; scanf("%d%d", &u, &v);
		AddEdge(u, v, i);
	}

	BFS();

	printf("%d\n", cnt - 1);
	REP(i, 1, n) if(ans[i]) printf("%d ", i);
	printf("\n");

	return 0;
}


