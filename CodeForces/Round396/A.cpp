#include <cstdio>
#include <cstring>
#include <algorithm>
using std::max;

const int maxn = 100000 + 10;

char s[2][maxn];

int main()
{
	scanf("%s%s", s[0], s[1]);
	int ans = max(strlen(s[0]), strlen(s[1]));

	if(strcmp(s[0], s[1]) == 0) printf("-1\n");
	else printf("%d\n", ans);

	return 0;
}
