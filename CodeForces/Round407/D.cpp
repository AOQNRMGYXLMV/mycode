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

const int maxn = 1000000 + 10;

int n, m, cc;
bool vis[maxn];
int pa[maxn], deg[maxn];
int findset(int x) { return x == pa[x] ? x : pa[x] = findset(pa[x]); }

int main() {
	scanf("%d%d", &n, &m); cc = n;
	REP(i, 0, n) pa[i] = i;
	int loops = 0, unvisited = n;
	REP(i, 0, m) {
		int u, v; scanf("%d%d", &u, &v);
		u--; v--;
		if(!vis[u]) { vis[u] = true; unvisited--; }
		if(!vis[v]) { vis[v] = true; unvisited--; }
		if(u == v) { loops++; continue; }
		deg[u]++; deg[v]++;
		int pu = findset(u), pv = findset(v);
		if(pu != pv) { cc--; pa[pu] = pv; }
	}

	if(cc != unvisited + 1) { puts("0"); return 0; }

	LL ans = 0;
	REP(i, 0, n) if(vis[i]) ans += (LL)deg[i] * (deg[i] - 1) / 2;
	ans += (LL) loops * (loops - 1) / 2;
	ans += (LL) loops * (m - loops);

	printf("%lld\n", ans);

	return 0;
}


