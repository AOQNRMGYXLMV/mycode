#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

typedef long long LL;
const int maxn = 100000 + 10;
const int maxm = 500000 + 10;

struct Edge
{
	int v, nxt;
	Edge() {}
	Edge(int v, int nxt): v(v), nxt(nxt) {}
};

int n, m, a, b;

int head[maxn], ecnt;
Edge edges[maxm * 2];

void init() {
	memset(head, -1, sizeof(head));
	ecnt = 0;
}

void AddEdge(int u, int v) {
	edges[ecnt] = Edge(v, head[u]);
	head[u] = ecnt++;
}

LL dis[maxn];

LL BFS() {
	queue<int> Q;
	memset(dis, -1, sizeof(dis));
	dis[1] = 0;
	Q.push(1);
	while(!Q.empty()) {
		int u = Q.front(); Q.pop();
		for(int i = head[u]; ~i; i = edges[i].nxt) {
			int v = edges[i].v;
			if(dis[v] != -1) continue;
			dis[v] = dis[u] + a;
			if(dis[v] >= b) return b;
			Q.push(v);
			if(v == n) return dis[n];
		}
	}
	return dis[n] == -1 ? b : dis[n];
}

bool connect[maxn];

LL BFS2() {
	queue<int> Q;
	memset(dis, -1, sizeof(dis));
	dis[1] = 0;
	Q.push(1);
	while(!Q.empty()) {
		int u = Q.front(); Q.pop();
		for(int i = 1; i <= n; i++) connect[i] = true;
		for(int i = head[u]; ~i; i = edges[i].nxt)
			connect[edges[i].v] = false;
		for(int v = 1; v <= n; v++) if(connect[v]) {
			if(dis[v] != -1) continue;
			dis[v] = dis[u] + b;
			if(dis[v] >= a) return a;
			if(v == n) return dis[n];
			Q.push(v);
		}
	}
	return dis[n] == -1 ? a : dis[n];
}

int main()
{
	while(scanf("%d%d%d%d", &n, &m, &a, &b) == 4) {
		init();
		bool flag = false;
		while(m--) {
			int u, v; scanf("%d%d", &u, &v);
			AddEdge(u, v);
			AddEdge(v, u);
			if((u == 1 && v == n) || (u == n && v == 1)) flag = true;
		}
		
		LL ans = flag ? BFS2() : BFS();
		printf("%lld\n", ans);
	}

	return 0;
}
