#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
#define MP make_pair
#define PB push_back
#define REP(i, a, b) for(int i = a; i < b; i++)
#define PER(i, a, b) for(int i = b - 1; i >= a; i--)

const int maxn = 1000 + 10;

int n, m, k, x1, y1, x2, y2;
char s[maxn][maxn];
int dis[maxn][maxn];

struct Node {
	int x, y, s;
	Node(int x = 0, int y = 0, int s = 0): x(x), y(y), s(s) {}
};

queue<Node> Q;

int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 };

bool in(int x, int y) { return 0<=x&&x<n&&0<=y&&y<m; }

bool check(int x, int y) {
	if(!in(x, y) || s[x][y] == '#') return false;
	return true;
}

int BFS() {
	memset(dis, 0x3f, sizeof(dis));
	Q.push(Node(x1, y1, 0));
	dis[x1][y1] = 0;
	while(!Q.empty()) {
		Node t = Q.front(); Q.pop();
		if(t.x == x2 && t.y == y2) return t.s;
		REP(dir, 0, 4) {
			REP(i, 1, k + 1) {
				int nx = t.x + dx[dir] * i;
				int ny = t.y + dy[dir] * i;
				if(!check(nx, ny)) break;
				if(dis[nx][ny] <= dis[t.x][t.y]) break;
				if(dis[nx][ny] > dis[t.x][t.y] + 1) {
					Q.push(Node(nx, ny, t.s + 1));
					dis[nx][ny] = t.s + 1;
				}
			}
		}
	}
	return -1;
}

int main() {
	scanf("%d%d%d", &n, &m, &k);
	REP(i, 0, n) scanf("%s", s[i]);
	scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
	x1--; y1--; x2--; y2--;
	printf("%d\n", BFS());

	return 0;
}