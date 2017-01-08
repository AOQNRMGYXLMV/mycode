#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

const int maxn = 300 + 10;

struct Node
{
	int step, pos;
	Node(int s, int p): step(s), pos(p) {}
	bool operator < (const Node& t) const {
		return step > t.step;
	}
};

char s[maxn][maxn];
int n, m, sx, sy, tx, ty;

bool in(int x, int y) { return 0<=x && x<n && 0<=y && y<m; }

int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };

int BFS() {
	priority_queue<Node> Q;
	Q.push(Node(0, sx * m + sy));
	s[sx][sy] = 'R';

	while(!Q.empty()) {
		Node t = Q.top(); Q.pop();
		int x = t.pos / m, y = t.pos % m;
		if(x == tx && y == ty) return t.step;
		for(int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if(!in(nx, ny)) continue;
			if(s[nx][ny] == 'R') continue;
			if(s[nx][ny] == 'B') Q.push(Node(t.step+2, nx*m+ny));
			else Q.push(Node(t.step+1, nx*m+ny));
			s[nx][ny] = 'R';
		}
	}
	return -1;
}

int main()
{
	freopen("in.txt", "r", stdin);
	while(scanf("%d%d", &n, &m) == 2) {
		if(!n && !m) break;
		for(int i = 0; i < n; i++) scanf("%s", s[i]);
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++) {
				if(s[i][j] == 'Y') { sx = i; sy = j; }
				else if(s[i][j] == 'T') { tx = i; ty = j; }
				else if(s[i][j] == 'S') s[i][j] = 'R';
			}
		printf("%d\n", BFS());
	}

	return 0;
}
