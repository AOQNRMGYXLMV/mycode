#include <cstdio>
#include <cstring>

const int maxn = 200000 + 10;

char t[maxn], p[maxn];

int a[maxn], n, l;

bool vis[maxn];

bool check(int x) {
	memset(vis, false, sizeof(vis));
	for(int i = 0; i < x; i++) vis[a[i]] = true;
	int pos = 0;
	for(int i = 0; i < n && pos < l; i++)
		if(!vis[i] && t[i] == p[pos]) pos++;
	return pos == l;
}

int main()
{
	scanf("%s%s", t, p);
	n = strlen(t);
	l = strlen(p);
	for(int i = 0; i < n; i++)
		scanf("%d", a + i), a[i]--;
	check(4);
	int L = 0, R = n - l;
	while(L < R) {
		int M = (L + R + 1) / 2;
		if(check(M)) L = M;
		else R = M - 1;
	}

	printf("%d\n", L);

	return 0;
}
