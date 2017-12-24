#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
#define PB push_back
#define PII pair<int, int>
#define REP(i, a, b) for(int i = a; i < b; i++)
#define PER(i, a, b) for(int i = b - 1; i >= a; i--)
#define ALL(x) x.begin(), x.end()

const int maxn = 20;

char s[maxn][maxn];

int main() {
	REP(i, 0, 9) for(int j = 0; j < 9; j += 3) {
		scanf("%s", s[i] + j);
	}

	int x, y; scanf("%d%d", &x, &y);
	x--; y--;
	x %= 3; y %= 3;
	bool empty = false;
	REP(i, 0, 3) REP(j, 0, 3) {
		if(s[x*3+i][y*3+j] == '.') {
			empty = true;
			break;
		}
	}

	if(empty) {
		REP(i, 0, 3) REP(j, 0, 3) if(s[x*3+i][y*3+j] == '.')
			s[x*3+i][y*3+j] = '!';
	} else {
		REP(i, 0, 9) REP(j, 0, 9) if(s[i][j] == '.')
			s[i][j] = '!';
	}

	REP(i, 0, 9) {
		REP(j, 0, 9) {
			putchar(s[i][j]);
			if(j == 2 || j == 5) putchar(' ');
			else if(j == 8) putchar('\n');
		}
		if(i == 2 || i == 5) putchar('\n');
	}

	return 0;
}

