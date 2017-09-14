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

int n, m;
vector<PII> G[maxn];
PII fa[maxn];
int d[maxn];
bool vis[maxn];
int choose[maxn];

void dfs(int u, int pa = 0) {
	for(PII x : G[u]) {
		int v = x.first, id = x.second;
		if(v == pa || vis[v]) continue;
		vis[v] = true;
		dfs(v, u);
		fa[v] = MP(u, id);
		if(d[v] == 1) {
			d[v] = 0;
			if(d[u] != -1) d[u] ^= 1;
			choose[id] ^= 1;
		}
	}
}

int main() {
	scanf("%d%d", &n, &m);
	int tag = 0, cnt = 0;
	REP(i, 1, n + 1) {
		scanf("%d", d + i);
		if(d[i] == -1) tag = i;
		else if(d[i] == 1) cnt++;
	}
	REP(i, 1, m + 1) {
		int u, v; scanf("%d%d", &u, &v);
		G[u].PB(MP(v, i));
		G[v].PB(MP(u, i));
	}
	if(!tag && (cnt & 1)) { printf("-1\n"); return 0; }
	dfs(1);
	if(d[1] == 1) {
		if(!tag) { printf("-1\n"); return 0; }
		while(tag != 1) {
			choose[fa[tag].second] ^= 1;
			tag = fa[tag].first;
		}
	}

	int ans = 0;
	REP(i, 1, m + 1) if(choose[i]) ans++;
	printf("%d\n", ans);
	REP(i, 1, m + 1) if(choose[i]) printf("%d ", i);
	printf("\n");

	return 0;
}


