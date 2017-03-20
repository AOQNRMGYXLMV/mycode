#include <cstdio>

const int maxn = 150000 + 10;
typedef long long LL;

int n, m;

int pa[maxn], sz[maxn], cc;
LL edge[maxn];
int findset(int x) { return x == pa[x] ? x : pa[x] = findset(pa[x]); }
void Union(int x, int y) {
	int px = findset(x), py = findset(y);
	if(px != py) { pa[px] = py; cc--; sz[py] += sz[px]; }
}

int u[maxn], v[maxn];

int main()
{
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++) { pa[i] = i; sz[i] = 1; }
	cc = n;
	for(int i = 0; i < m; i++) {
		scanf("%d%d", u + i, v + i);
		Union(u[i], v[i]);
	}

	for(int i = 0; i < m; i++)
		edge[findset(u[i])]++;

	bool ok = true;
	for(int i = 1; i <= n; i++) if(findset(i) == i) {
		if((LL)sz[i] * (sz[i] - 1) / 2 != edge[i]) {
			puts("NO"); return 0;
		}
	}

	puts("YES");

	return 0;
}
