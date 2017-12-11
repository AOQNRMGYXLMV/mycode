#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
#define PB push_back
#define PII pair<int, int>
#define REP(i, a, b) for(int i = a; i < b; i++)
#define PER(i, a, b) for(int i = b - 1; i >= a; i--)
#define ALL(x) x.begin(), x.end()
#define fi first
#define se second

const int maxn = 500 + 10;

int n, m;
vector<int> u, v, w, r;

int pa[maxn], cc;
int findset(int x) { return x == pa[x] ? x : pa[x] = findset(pa[x]); }

bool mark[maxn * maxn];
vector<PII> G[maxn];
int maxv[maxn][maxn];

int root;
void dfs(int u, int p = 0, int m = 0) {
	maxv[root][u] = maxv[u][root] = m;
	for(PII e : G[u]) {
		int v = e.fi;
		if(v == p) continue;
		dfs(v, u, max(m, e.se));
	}
}

int main() {
	scanf("%d%d", &n, &m);
	REP(i, 0, m) {
		int U, V, W; scanf("%d%d%d", &U, &V, &W);
		u.PB(U); v.PB(V); w.PB(W); r.PB(i);
	}
	sort(ALL(r), [](const int& i, const int& j){ return w[i]<w[j]; });
	REP(i, 1, n + 1) pa[i] = i;
	cc = n;
	int sum = 0;
	for(int i : r) {
		int pu = findset(u[i]), pv = findset(v[i]);
		if(pu != pv) {
			//printf("%d <-> %d\n", u[i], v[i]);
			cc--;
			pa[pv] = pu;
			sum += w[i];
			mark[i] = true;
			G[u[i]].emplace_back(v[i], w[i]);
			G[v[i]].emplace_back(u[i], w[i]);
			if(cc == 1) break;
		}
	}

	if(cc > 1) { printf("No MST\n%d\n", cc); return 0; }

	REP(i, 1, n + 1) { root = i; dfs(i); }

	bool unique = true;
	REP(i, 0, m) if(!mark[i] && maxv[u[i]][v[i]] == w[i]) {
		unique = false;
		break;
	}

	printf("%d\n%s\n", sum, unique ? "Yes" : "No");

	return 0;
}

