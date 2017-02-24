#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int maxn = 100000 + 10;

struct TwoSAT
{
    int n;
    vector<int> G[maxn * 2];
    bool mark[maxn * 2];
    int S[maxn * 2], c;

    bool dfs(int x) {
        if(mark[x^1]) return false;
        if(mark[x]) return true;
        mark[x] = true;
        S[c++] = x;
        for(int i = 0; i < G[x].size(); i++)
            if(!dfs(G[x][i])) return false;
        return true;
    }

    void init(int n) {
        this->n = n;
        for(int i = 0; i < n * 2; i++) G[i].clear();
        memset(mark, false, sizeof(mark));
    }

    void add_clause(int x, int xval, int y, int yval) {
        x = x * 2 + xval;
        y = y * 2 + yval;
        G[x^1].push_back(y);
        G[y^1].push_back(x);
    }

    bool solve() {
        for(int i = 0; i < n * 2; i += 2)
            if(!mark[i] && !mark[i+1]) {
                c = 0;
                if(!dfs(i)) {
                    while(c > 0) mark[S[--c]] = false;
                    if(!dfs(i+1)) return false;
                }
            }

        return true;
    }
}solver;

int state[maxn];
int swt[maxn][2], p[maxn];

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; i++) scanf("%d", state + i);
	for(int i = 0; i < m; i++) {
		int x; scanf("%d", &x);
		while(x--) {
			int y; scanf("%d", &y); y--;
			swt[y][p[y]++] = i;
		}
	}

	solver.init(m);
	for(int i = 0; i < n; i++) {
		solver.add_clause(swt[i][0], 1, swt[i][1], state[i] ^ 1);
		solver.add_clause(swt[i][0], 0, swt[i][1], state[i]);
	}

	printf("%s\n", solver.solve() ? "YES" : "NO");

	return 0;
}
