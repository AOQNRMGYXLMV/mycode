#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int maze[20][6][6];
bool vis[6][6][6][6];
int st[20], ed[20];

struct Node
{
	int pos1, pos2, pre, d;
	Node() {}
	Node(int a, int b, int c, int d): pos1(a), pos2(b), pre(c), d(d) {}
};

Node Q[1300];
int path[1300];

int dx[] = { 1, 0, 0, -1 };
int dy[] = { 0, -1, 1, 0 };
int bit[] = { 1, 0, 2, 3 };
char str[] = "DLRU";

bool in(int x, int y) { return 0<=x && x<6 && 0<=y && y<6; }

int main()
{
	int T; scanf("%d", &T);
	for(int t = 0; t < T; t++) {
		for(int i = 0; i < 6; i++) {
			for(int j = 0; j < 6; j++) {
				scanf("%d", &maze[t][i][j]);
				int& a = maze[t][i][j];
				if((a >> 5) & 1) st[t] = i * 6 + j;
				if((a >> 6) & 1) ed[t] = i * 6 + j;
			}
		}
	}

	for(int t = 0; t + 1 < T; t++) {
		int head = 0, rear = 0;
		Q[rear++] = Node(st[t], st[t + 1], -1, -1);
		memset(vis, false, sizeof(vis));
		vis[st[t]/6][st[t]%6][st[t+1]/6][st[t+1]%6] = true;
		bool ok = false;
		while(head < rear) {
			Node x = Q[head++];
			if(x.pos1 == ed[t] && x.pos2 == ed[t + 1]) {
				ok = true;
				//TODO
				int tot = 0, cur = head - 1;
				while(Q[cur].pre != -1) {
					path[tot++] = Q[cur].d;
					cur = Q[cur].pre;
				}
				for(tot--; tot >= 0; tot--) printf("%c", str[path[tot]]);
				printf("\n");
				break;
			}
			int x1 = x.pos1 / 6, y1 = x.pos1 % 6;
			int x2 = x.pos2 / 6, y2 = x.pos2 % 6;
			for(int dir = 0; dir < 4; dir++) {
				int nx1 = x1, ny1 = y1, nx2 = x2, ny2 = y2;
				if(((maze[t][x1][y1] >> bit[dir]) & 1) == 0) {
					nx1 += dx[dir];
					ny1 += dy[dir];
					if(!in(nx1, ny1)) continue;
					if(((maze[t][nx1][ny1] >> 4) & 1) == 0) continue;
				}
				if(((maze[t+1][nx2][ny2] >> bit[dir]) & 1) == 0) {
					nx2 += dx[dir];
					ny2 += dy[dir];
					if(!in(nx2, ny2)) continue;
					if(((maze[t+1][nx2][ny2] >> 4) & 1) == 0) continue;
				}
				if(vis[nx1][ny1][nx2][ny2]) continue;
				vis[nx1][ny1][nx2][ny2] = true;
				Q[rear++] = Node(nx1*6+ny1, nx2*6+ny2, head-1, dir);
			}
		}
		if(!ok) printf("-1\n");
	}

	return 0;
}
