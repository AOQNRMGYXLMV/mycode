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

const int maxn = 100000 + 10;

int n;
LL a[maxn], b[maxn];
vector<int> G[maxn];
int fa[maxn];
LL k[maxn];

const LL INF = 200000000000000000LL;

void dfs(int u) {
	for(int v : G[u]) dfs(v);
	if(u == 1) return;
	if(b[u] < 0 && INF / (-b[u]) == 0) {
		printf("NO\n");
		exit(0);
	}
	LL need = a[u] - b[u];
	if(need < 0) {
		b[fa[u]] -= need;
	} else {
		if((double)need * k[u] > (double)INF) {
			printf("NO\n");
			exit(0);
		}
		b[fa[u]] -= need * k[u];
		if(b[fa[u]] < 0 && INF / (-b[fa[u]]) == 0) {
			printf("NO\n");
			exit(0);
		}
	}
	b[u] = a[u];
}

int main() {
	scanf("%d", &n);
	REP(i, 1, n + 1) scanf("%lld", b + i);
	REP(i, 1, n + 1) scanf("%lld", a + i);
	REP(i, 2, n + 1) {
		scanf("%d%lld", fa + i, k + i);
		G[fa[i]].push_back(i);
	}

	dfs(1);
	if(b[1] >= a[1]) printf("YES\n");
	else printf("NO\n");

	return 0;
}


