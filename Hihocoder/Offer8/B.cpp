#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
#define MP make_pair
using namespace std;

const int maxn = 500 + 10;

int n, m;
char s[maxn][maxn];
int vis[maxn][maxn];

struct Block
{
	int top, down, lft, rgh, dr, dc, color;
	Block(int top, int down, int lft, int rgh, int dr, int dc, int color): top(top), down(down), lft(lft), rgh(rgh), dr(dr), dc(dc), color(color) {}
	bool operator < (const Block& t) const {
		return dc < t.dc || (dc == t.dc && dr < t.dr);
		//return top < t.top || (top == t.top && lft < t.lft);
	}
};
typedef pair<int, int> PII;
int top, lft, down, rgh, dr, dc;

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

PII Q[maxn * maxn];
int cnt, color;

void bfs(int r, int c) {
	vis[r][c] = color;
	cnt = 0;
	Q[cnt++] = MP(r, c);
	top = down = dr = r;
	lft = rgh = dc = c;
	while(cnt) {
		PII x = Q[--cnt];
		top = min(top, x.first);
		lft = min(lft, x.second);
		down = max(down, x.first);
		rgh = max(rgh, x.second);
		if(x.second < dc || (x.second == dc && x.first < dr)) {
			dr = x.first; dc = x.second;
		}
		for(int i = 0; i < 4; i++) {
			int rr = x.first + dx[i];
			int cc = x.second + dy[i];
			if(s[rr][cc] == '1' && !vis[rr][cc]) {
				Q[cnt++] = MP(rr, cc);
				vis[rr][cc] = color;
			}
		}
	}
}

/*void dfs(int r, int c) {
	vis[r][c] = true;
	top = min(top, r);
	lft = min(lft, c);
	down = max(down, r);
	rgh = max(rgh, c);
	for(int dir = 0; dir < 4; dir++) {
		int x = r + dx[i];
		int y = c + dy[i];
		if(!vis[x][y]) dfs(x, y);
	}
}*/

vector<Block> b;

void output(Block& x) {
	printf("%d %d\n", x.down - x.top + 1, x.rgh - x.lft + 1);
	for(int i = x.top; i <= x.down; i++) {
		for(int j = x.lft; j <= x.rgh; j++) {
			if(s[i][j] == '1' && vis[i][j] == x.color)
				printf("1");
			else printf("0");
		}
		printf("\n");
	}
}

int main()
{
	while(scanf("%d%d", &n, &m) == 2) {
		for(int i = 0; i < n; i++) scanf("%s", s[i]);
		memset(vis, false, sizeof(vis));
		
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) if(s[i][j] == '1' && !vis[i][j]) {
				color++;
				bfs(i, j);
				b.push_back(Block(top, down, lft, rgh, dr, dc, color));
			}
		}

		sort(b.begin(), b.end());
		for(int i = 0; i < b.size(); i++)
			output(b[i]);
	}

	return 0;
}
