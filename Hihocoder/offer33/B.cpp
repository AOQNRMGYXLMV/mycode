#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
#define MP make_pair
#define PB push_back
#define REP(i, a, b) for(int i = a; i < b; i++)
#define PER(i, a, b) for(int i = b - 1; i >= a; i--)

const int maxn = 10000 + 10;

int n;
vector<int> G[maxn], root;
int l[maxn], r[maxn];
int fa[maxn], error;
bool vis[maxn];
int tot;

void dfs(int u) {
	if(error == 1) return;
	vis[u] = true;
	tot++;
	for(int i = 0; i < G[u].size(); i++) {
		int v = G[u][i];
		if(vis[v]) { error = 1; return; }
		dfs(v);
	}
}

vector<int> check;
void dfs2(int u) {
	if(error) return;
	int sz = G[u].size();
	if(sz == 1) {
		if(G[u][0] < u) { dfs2(G[u][0]); check.PB(u); }
		else { check.PB(u); dfs2(G[u][0]); }
	}else if(sz > 1) {
		if(G[u][0] > u || G[u][1] < u) { error = 3; return; }
		dfs2(G[u][0]); check.PB(u); dfs2(G[u][1]);
	}
}

void print(int u) {
	if(!u) { printf("()"); return; }
	printf("(");
	printf("%d", u);
	print(l[u]);
	print(r[u]);
	printf(")");
}

int main() {
	int _; scanf("%d", &_);
	while(_--) {
		scanf("%d", &n);
		REP(i, 1, n + 1) G[i].clear();
		memset(fa, 0, sizeof(fa));
		error = 0;
		REP(i, 1, n) {
			int a, b; scanf("%d%d", &a, &b);
			G[a].PB(b);
			if(fa[b]) error = 1;
			fa[b] = a;
		}
		if(error) { printf("ERROR%d\n", error); continue; }

		root.clear();
		error = 0;
		REP(i, 1, n + 1) {
			if(!fa[i]) root.PB(i);
			if(G[i].size() > 2) error = 2;
			sort(G[i].begin(), G[i].end());
		}

		if(root.size() != 1) {
			printf("ERROR1\n"); continue;
		}

		memset(vis, false, sizeof(vis));
		tot = 0;
		dfs(root[0]);
		if(tot < n) error = 1;
		if(error) { printf("ERROR%d\n", error); continue; }
		
		check.clear();
		dfs2(root[0]);
		if(error) { printf("ERROR%d\n", error); continue; }
		REP(i, 1, check.size()) {
			if(check[i] < check[i-1]) {
				error = 3;
				break;
			}
		}
		if(error) { printf("ERROR%d\n", error); continue; }

		memset(l, 0, sizeof(l));
		memset(r, 0, sizeof(r));
		REP(u, 1, n + 1) {
			if(G[u].size() == 1) {
				if(G[u][0] < u) l[u] = G[u][0];
				else r[u] = G[u][0];
			} else if(G[u].size() > 1) {
				l[u] = G[u][0];
				r[u] = G[u][1];
			}
		}
		print(root[0]);
		printf("\n");
	}

	return 0;
}
