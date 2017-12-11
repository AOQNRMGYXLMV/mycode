#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
#define PB push_back
#define PII pair<int, int>
#define REP(i, a, b) for(int i = a; i < b; i++)
#define PER(i, a, b) for(int i = b - 1; i >= a; i--)
#define ALL(x) x.begin(), x.end()
#define MP make_pair
#define fi first
#define se second

int n, m, K, H;
int ans;
const int maxn = 10;
const int BLANK = 0;
const int ANIMAL = 1;

char s[10];
int a[maxn][maxn], put[maxn][maxn];
int qx[110], qy[110], tail;

set<LL> Set, solution;

inline bool in(int x, int y) {
  return 0<=x && x<n && 0<=y && y<m;
}

int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 };

#define code(i, j) (i*m+j)

bool check(LL S) {
  REP(i, 0, n) REP(j, 0, m)
    put[i][j] = ((S>>code(i, j))&1);
  int hole_num = 0;

  int cc = 0;
  REP(i, 0, n) REP(j, 0, m) if(!put[i][j]) {
    bool hole = true;
    int animals = a[i][j] == ANIMAL;
	put[i][j] = 1;
    tail = 0;
    qx[tail] = i; qy[tail++] = j;
    REP(p, 0, tail) {
      int x = qx[p], y = qy[p];
      REP(dir, 0, 4) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if(!in(nx, ny)) { hole = false; continue; }
        if(put[nx][ny]) continue;
        qx[tail] = nx; qy[tail++] = ny;
        put[nx][ny] = 1;
		if(a[nx][ny] == ANIMAL) {
			animals++;
			if(animals > 1) return false;
		}
      }
    }
    if(hole) {
      hole_num++;
      if(hole_num > H) return false;
    }
  }
  return hole_num == H;
}

void dfs(LL S, int k) {
  if(Set.count(S)) return;
  Set.insert(S);
  if(k == K) {
    if(check(S)) {
		ans++; solution.insert(S);
	}
    return;
  }
  LL t = S;
  for(int i = 0; t; i++, t >>= 1) if(t & 1) {
    int x = i / m, y = i % m;
    REP(dir, 0, 4) {
      int nx = x + dx[dir];
      int ny = y + dy[dir];
      if(in(nx, ny) && a[nx][ny] == BLANK && !((S>>code(nx, ny))&1)) {
        dfs(S | (1LL << code(nx, ny)), k + 1);
      }
    }
  }
}

int main() {
  scanf("%d%d%d%d", &n, &m, &K, &H);
  int tot_animals = 0;
  REP(i, 0, n) {
    scanf("%s", s);
    REP(j, 0, m) {
      if(s[j] == '.') a[i][j] = BLANK;
      else { a[i][j] = ANIMAL; tot_animals++; }
    }
  }

  if(tot_animals + K > n * m) {
    printf("0\n");
	return 0;
  }

  PER(i, 0, n) PER(j, 0, m) if(a[i][j] == BLANK) {
    dfs(1LL << code(i, j), 1);
  }

  printf("%d\n", ans);

  return 0;
}
