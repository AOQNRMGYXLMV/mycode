#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n, q;
char g[6][6], s1[5], s2[5];

int ans;
char s[10];

int check() {
	char c1 = s[0];
	for(int i = 1; i < n; i++) {
		char c2 = s[i];
		if(!g[c1-'a'][c2-'a']) return 0;
		c1 = g[c1-'a'][c2-'a'];
	}
	return c1 == 'a' ? 1 : 0;
}

void dfs(int d) {
	if(d == n) {
		ans += check();
		return;
	}
	for(int i = 0; i < 6; i++) {
		s[d] = 'a' + i;
		dfs(d + 1);
	}
}

int main()
{
	//freopen("in.txt", "r", stdin);
	scanf("%d%d", &n, &q);
	for(int i = 0; i < q; i++) {
		scanf("%s %s", s1, s2);
		int c1 = s1[0] - 'a', c2 = s1[1] - 'a';
		g[c1][c2] = s2[0];
	}

	dfs(0);

	printf("%d\n", ans);

	return 0;
}
