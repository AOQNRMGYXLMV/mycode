#include <cstdio>

int main()
{
	int a, b; scanf("%d%d", &a, &b);
	if(!(a + b)) { printf("NO\n"); return 0; }
	if(-1 <= a - b && a - b <= 1) printf("YES\n");
	else printf("NO\n");

	return 0;
}
