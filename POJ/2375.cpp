#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 500 + 10;
const int maxnode = maxn * maxn;
const int maxm = maxnode * 4;

struct Edge
{
	int v, nxt;
	Edge() {}
	Edge(int v, int nxt): v(v), nxt(nxt) {}
};

int m, n;

int ecnt, head[maxnode];
Edge edges[maxm];

void AddEdge(int u, int v) {
	edges[ecnt] = Edge(v, head[u]);
	head[u] = ecnt++;
}

int a[maxn][manx];

int id(int i, int j) { return i * m + j; }

int main()
{
	scanf("%d%d", &m, &n);
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++) scanf("%d", &a[i][j]);
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			int u = id(i, j);

		}
	}

	return 0;
}
