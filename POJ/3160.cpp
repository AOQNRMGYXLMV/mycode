#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 30000 + 10;
const int maxm = 150000 + 10;

struct Edge
{
	int v, nxt;
	Edge() {}
	Edge(int v, int nxt): v(v), nxt(nxt) {}
};

struct Graph
{
	int ecnt, head[maxn];
	Edge edges[maxm];

	void init() { ecnt = 0; memset(head, -1, sizeof(head)); }

	void AddEdge(int u, int v) {
		edges[ecnt] = Edge(v, head[u]);
		head[u] = ecnt++;
	}
};

Graph g, t;

int main()
{


	return 0;
}
