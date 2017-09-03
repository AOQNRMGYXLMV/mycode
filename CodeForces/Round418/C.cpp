#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <set>
#include <vector>
#include <iostream>
#include <string>
#include <bitset>
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

const int maxn = 1500 + 10;
int n, m, c;
char s[maxn];
int ans[26][maxn];
int a[26][maxn];
vector<int> zero[26];
int sum[26];

/*int length() {
	int ans = 0;
	for(int j, i = 0; i < n; i++) if(a[c][i] == 1) {
		for(j = i; j < n && a[c][j] == 1; j++);
		if(j - i > ans) ans = j - i;
		i = j;
	}
	return ans;
}*/

bool ok(int x) {
	int need = 0;
	REP(i, 0, x) if(!a[c][i]) need++;
	if(need <= m) return true;
	REP(i, x, n) {
		if(!a[c][i]) need++;
		if(!a[c][i-x]) need--;
		if(need <= m) return true;
	}
	return false;
}

int calc() {
	int L = 1, R = n;
	while(L < R) {
		int M = (L + R + 1) / 2;
		if(ok(M)) L = M;
		else R = M - 1;
	}
	return L;
}

int main() {
	scanf("%d\n%s\n", &n, s);
	REP(i, 0, n) {
		int x = s[i] - 'a';
		a[x][i] = 1;
		sum[x]++;
		REP(j, 0, 26) if(j != x) zero[j].PB(i);
	}
	int _; scanf("%d", &_);
	char q[5];
	while(_--) {
		scanf("%d %s", &m, q);
		c = q[0] - 'a';
		if(m >= n - sum[c]) { printf("%d\n", n); continue; }
		if(ans[c][m]) { printf("%d\n", ans[c][m]); continue; }
		ans[c][m] = calc();
		printf("%d\n", ans[c][m]);
	}

	return 0;
}


