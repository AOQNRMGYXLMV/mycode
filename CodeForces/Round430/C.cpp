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

const int maxn = 200000 + 10;

int gcd(int a, int b) { return !b ? a : gcd(b, a%b); }

int n, a[maxn], ans[maxn];
vector<int> G[maxn];
int sz;
vector<int> fac, cnt;

void decompose(int x) {
	for(int i = 1; i * i <= x; i++) if(x % i == 0) {
		fac.push_back(i);
		fac.push_back(x / i);
		if(i * i == x) fac.pop_back();
	}
	sort(ALL(fac));
	sz = SZ(fac);
	cnt.resize(sz);
}

void dfs1(int u, int pa = 0) {
	for(int v : G[u]) {
		if(v == pa) continue;
		ans[v] = gcd(a[v], ans[u]);
		dfs1(v, u);
	}
}

void dfs2(int u, int pa = 0, int dep = 0) {
	REP(i, 0, sz) if(a[u] % fac[i] == 0) cnt[i]++;
	PER(i, 0, sz) {
		if(cnt[i] >= dep) {
			ans[u] = max(ans[u], fac[i]);
			break;
		}
	}
	for(int v : G[u]) {
		if(v == pa) continue;
		dfs2(v, u, dep + 1);
	}
	REP(i, 0, sz) if(a[u] % fac[i] == 0) cnt[i]--;
}

int main() {
	scanf("%d", &n);
	REP(i, 1, n + 1) scanf("%d", a + i);
	REP(i, 1, n) {
		int x, y; scanf("%d%d", &x, &y);
		G[x].push_back(y);
		G[y].push_back(x);
	}
	dfs1(1);
	decompose(a[1]);
	dfs2(1);

	REP(i, 1, n + 1) printf("%d ", ans[i]);
	printf("\n");

	return 0;
}


