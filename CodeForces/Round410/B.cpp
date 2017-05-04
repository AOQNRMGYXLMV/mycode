#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <set>
#include <vector>
#include <iostream>
#include <string>
using namespace std;
#define REP(i, a, b) for(int i = a; i < b; i++)
#define PER(i, a, b) for(int i = b - 1; i >= a; i--)
#define SZ(a) ((int)a.size())
#define MP make_pair
#define PB push_back
#define EB emplace_back
#define ALL(a) a.begin(), a.end()
typedef long long LL;
typedef pair<int, int> PII;

const int maxn = 60;

int n, l;
char s[maxn][maxn], t[maxn];

bool eq(int x, int i, int j) {
	REP(k, 0, l) {
		if(s[x][i] != t[j]) return false;
		i = (i + 1) % l;
		j = (j + 1) % l;
	}
	return true;
}

int dist(int x, int j) {
	REP(i, 0, l) if(eq(x, i, j)) return i;
	return -1;
}

int main() {
	scanf("%d", &n);
	REP(i, 0, n) scanf("%s", s[i]);
	l = strlen(s[0]);
	strcpy(t, s[0]);

	int ans = 0x3f3f3f3f;
	REP(j, 0, l) {
		int t = 0;
		REP(x, 0, n) {
			int d = dist(x, j);
			if(d == -1) { printf("-1\n"); return 0; }
			t += d;
		}
		if(t < ans) ans = t;
	}

	printf("%d\n", ans);

	return 0;
}


