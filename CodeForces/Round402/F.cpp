#include <cstdio>

const int maxn = 300000 + 10;

int ch[maxn * 2][26];
int n;
int cnt, tot;

int ans[maxn];

int merge(int x, int y) {
	if(!x || !y) return x | y;
	cnt++;
	int node = ++tot;
	for(int i = 0; i < 26; i++)
		ch[node][i] = merge(ch[x][i], ch[y][i]);
	return node;
}

void dfs(int u, int d) {
	tot = n; cnt = 0;
	int node = ++tot;
	for(int i = 0; i < 26; i++) if(ch[u][i])
		node = merge(node, ch[u][i]);
	ans[d] += cnt;
	for(int i = 0; i < 26; i++) if(ch[u][i])
		dfs(ch[u][i], d + 1);
}

int main()
{
	scanf("%d", &n);
	for(int i = 1; i < n; i++) {
		int u, v; char c;
		scanf("%d %d %c", &u, &v, &c);
		ch[u][c - 'a'] = v;
	}
	dfs(1, 1);
	int p = 1;
	for(int i = 2; i <= n; i++) if(ans[i] > ans[p]) p = i;
	printf("%d\n%d\n", n - ans[p], p);

	return 0;
}
