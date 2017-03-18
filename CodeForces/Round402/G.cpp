#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

const int maxn = 60;
typedef pair<int, int> PII;
#define ALL(x) (x).begin(), (x).end()

int n, m, Max;
char s1[maxn][maxn], s2[maxn][maxn];
vector<PII> a, b;

void rotate(char s[][maxn], int x, int y) {
	if(s[x][y] == 'U') {
		s[x][y] = s[x+1][y] = 'L';
		s[x][y+1] = s[x+1][y+1] = 'R';
	} else {
		s[x][y] = s[x][y+1] = 'U';
		s[x+1][y] = s[x+1][y+1] = 'D';
	}
}

bool check(char s[][maxn], int x, int y) {
	if(s[x][y] == s[x][y+1] && s[x][y] == 'U' && s[x+1][y] == s[x+1][y+1] && s[x+1][y] == 'D') return true;
	if(s[x][y] == s[x+1][y] && s[x][y] == 'L' && s[x][y+1] == s[x+1][y+1] && s[x][y+1] == 'R') return true;
	return false;
}

bool adjust(char s[][maxn], int x, int y, int flag, vector<PII>& a) {
	if(x + 1 >= n || y + 1 >= m) return false;
	if(check(s, x, y)) {
		rotate(s, x, y);
		a.emplace_back(x, y);
		return true;
	} else {
		if(!adjust(s, x+1-flag, y+flag, flag^1, a)) return false;
		rotate(s, x, y);
		a.emplace_back(x, y);
		return true;
	}
}

void op(char& c) {
	switch(c) {
		case 'L': c = 'U'; break;
		case 'U': c = 'L'; break;
		case 'R': c = 'D'; break;
		case 'D': c = 'R'; break;
	}
}

void change(char s[][maxn]) {
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++) op(s[i][j]);
	for(int i = 0; i < Max; i++)
		for(int j = 0; j < i; j++)
			swap(s[i][j], s[j][i]);
}

int main()
{
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; i++) scanf("%s", s1[i]);
	for(int i = 0; i < n; i++) scanf("%s", s2[i]);
	Max = n > m ? n : m;
	bool changed = false;
	if(m & 1) { change(s1); change(s2); swap(n, m); changed = true; }

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j += 2) {
			if(s1[i][j] != 'L') {
				if(!adjust(s1, i, j, 1, a)) { puts("-1"); return 0; }
			}
			if(s2[i][j] != 'L') {
				if(!adjust(s2, i, j, 1, b)) { puts("-1"); return 0; }
			}
		}
	}

	reverse(ALL(b));
	a.insert(a.end(), ALL(b));
	printf("%d\n", (int)a.size());
	for(pair<int, int> t : a) {
		if(changed) swap(t.first, t.second);
		printf("%d %d\n", t.first + 1, t.second + 1);
	}

	return 0;
}
