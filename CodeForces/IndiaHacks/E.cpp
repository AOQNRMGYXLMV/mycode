#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
using namespace std;

const int maxn = 300000 + 10;

int n, m, k;
bool vis[maxn];
set<int> noedge[maxn];
set<int> remain;

void dfs(int u) {
	vector<int> tmp;
	for(int v : remain) if(!noedge[u].count(v))
		tmp.push_back(v);
	for(int v : tmp) remain.erase(v);
	for(int v : tmp) dfs(v);
}

int main()
{
	scanf("%d%d%d", &n, &m, &k);
	int mdeg = n - 1;
	for(int i = 1; i <= m; i++) {
		int a, b; scanf("%d%d", &a, &b);
		noedge[a].insert(b);
		noedge[b].insert(a);
		if(a == 1 || b == 1) mdeg--;
	}

	if(mdeg < k) { puts("impossible"); return 0; }

	for(int i = 2; i <= n; i++) remain.insert(i);

	int cnt = 0;
	for(int i = 2; i <= n; i++)
		if(!noedge[1].count(i) && remain.count(i)) {
			dfs(i);
			cnt++;
		}

	if(!remain.empty() || cnt > k) puts("impossible");
	else puts("possible");

	return 0;
}
