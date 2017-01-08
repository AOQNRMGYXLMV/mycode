#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

const int maxn = 200 + 10;

struct Node
{
	int p, s;
	Node(int p, int s): p(p), s(s) {}
	bool operator < (const Node& t) const {
		return s > t.s;
	}
};

int n, m, sx, sy, ex, ey;
char s[maxn][maxn];

int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };

bool in(int x, int y) { return 0<=x && x<n && 0<=y && y<m; }

int BFS() {
	priority_queue<Node> Q;
	Q.push(Node(sx*m+sy, 0));
	s[sx][sy] = '#';

	while(!Q.empty()) {
		Node t = Q.top(); Q.pop();
		int x = t.p / m, y = t.p % m;
		if(x == ex && y == ey) return t.s;
		for(int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if(!in(nx, ny)) continue;
			if(s[nx][ny] == '#') continue;
			int np = nx * m + ny;
			int add;
			if(s[nx][ny] == 'x') add = 2;
			else add = 1;
			Q.push(Node(np, t.s + add));
			s[nx][ny] = '#';
		}
	}

	return -1;
}

int main()
{
	while(scanf("%d%d", &n, &m) == 2) {
		for(int i = 0; i < n; i++) scanf("%s", s[i]);
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++) {
				if(s[i][j] == 'r') { sx = i; sy = j; }
				else if(s[i][j] == 'a') { ex = i; ey = j; }
			}

		int ans = BFS();
		if(ans != -1) printf("%d\n", ans);
		else puts("Poor ANGEL has to stay in the prison all his life.");
	}

	return 0;
}
