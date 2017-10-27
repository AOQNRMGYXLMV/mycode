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

const int maxn = 100000 + 10;

int n, m;

vector<int> G[maxn << 1], ans;
bool mark[maxn << 1];
int S[maxn << 1], c;

#define id(a, b) (a<<1|b)

void add_clause(int x, int y) {
	G[x^1].PB(y);
	G[y^1].PB(x);
}

bool dfs(int x) {
	if(mark[x^1]) return false;
	if(mark[x]) return true;
	mark[x] = true;
	S[c++] = x;
	for(int y : G[x]) if(!dfs(y)) return false;
	return true;
}

bool solve(int n) {
	for(int i = 0; i < n * 2; i += 2) {
		if(!mark[i] && !mark[i^1]) {
			c = 0;
			if(!dfs(i)) {
				while(c) mark[S[--c]] = false;
				if(!dfs(i^1)) return false;
			}
		}
	}
	return true;
}

int a[2][maxn];

void quit() { printf("No\n"); exit(0); }

int main() {
	scanf("%d%d", &n, &m);
	scanf("%d", &a[0][0]);
	REP(i, 1, a[0][0] + 1) scanf("%d", &a[0][i]);
	REP(i, 1, n) {
		int cur = i&1;
		scanf("%d", &a[cur][0]);
		REP(j, 1, a[cur][0] + 1) scanf("%d", &a[cur][j]);
		int _min = min(a[cur][0], a[cur^1][0]);
		int p;
		for(p = 1; p <= _min; p++) {
			if(a[cur][p] != a[cur^1][p]) break;
		}

		if(p <= _min) {
			int y = a[cur][p], x = a[cur^1][p];
			x--; y--;
			if(x > y) {
				G[id(x, 0)].PB(id(x, 1));
				G[id(y, 1)].PB(id(y, 0));
/*
				if(mark[id(y)] || mark[id(x, 1)]) quit();
				mark[id(y, 1)] = true;
				mark[id(x)] = true;
*/
			} else {
				add_clause(id(x, 1), id(y, 0));
			}
		} else if(a[cur][0] < a[cur^1][0]) {
			quit();
		}
	}

	if(!solve(m)) quit();
	else {
		REP(i, 0, m) if(mark[id(i, 1)]) ans.PB(i + 1);
		printf("Yes\n%d\n", (int)ans.size());
		for(int x : ans) printf("%d ", x);
		printf("\n");
	}

	return 0;
}