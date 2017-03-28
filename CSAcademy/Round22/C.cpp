#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <set>
#include <vector>
using namespace std;
#define REP(i, a, b) for(int i = a; i < b; i++)
#define SZ(a) ((int)a.size())
#define MP make_pair
#define ALL(a) a.begin(), a.end()
typedef long long LL;
typedef pair<int, int> PII;

const int maxn = 1000 + 10;

int n, m;
char tmp[5];
char s[maxn][maxn];

int tot, cc, color[maxn][maxn], sz[maxn * maxn];

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

inline bool in(int xx, int yy) {
    if(xx < 0 || xx >= n || yy < 0 || yy >= m) return false;
    return true;
}

void dfs(int x, int y) {
    tot++;
    color[x][y] = cc;
    REP(dir, 0, 4) {
        int xx = x + dx[dir];
        int yy = y + dy[dir];
        if(!in(xx, yy)) continue;
        if(s[xx][yy] == '1' && !color[xx][yy]) dfs(xx, yy);
    }
}

int main() {
    scanf("%d%d", &n, &m);
    REP(i, 0, n) REP(j, 0, m) { scanf("%s", tmp); s[i][j] = tmp[0]; }
    
    REP(i, 0, n) REP(j, 0, m) if(s[i][j] == '1' && !color[i][j]) {
        tot = 0; cc++; dfs(i, j);
        sz[cc] = tot;
    }

    if(cc == 1 && sz[1] == n * m) { printf("%d\n", n * m - 1); return 0; }

    set<int> S;
    int ans = 0;
    REP(i, 0, n) REP(j, 0, m) if(s[i][j] == '0') {
        int t = 1;
        S.clear();
        REP(dir, 0, 4) {
            int x = i + dx[dir], y = j + dy[dir];
            if(!in(x, y)) continue;
            if(!S.count(color[x][y])) {
                t += sz[color[x][y]];
                S.insert(color[x][y]);
            }
        }
        if(t > ans) ans = t;
    }

    printf("%d\n", ans);

    return 0;
}
