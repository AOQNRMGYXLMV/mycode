#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 100000 + 10;

int n, m;
char T[maxn], P[50];

bool match(int p) {
	for(int i = 0; i < m; i++)
		if(P[i] != T[p + i]) return false;
	return true;
}

int main()
{
	scanf("%s%s", T, P);
	n = strlen(T);
	m = strlen(P);

	int ans = 0;
	for(int i = 0; i + m <= n; i++) if(match(i)) {
		ans++;
		i += m - 1;
	}

	printf("%d\n", ans);

	return 0;
}