#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 100 + 10; 

char a[maxn], b[maxn];

int main()
{
	scanf("%s%s", a, b);
	if(strcmp(a, b) == 0) printf("%s\n", a);
	else printf("1\n");

	return 0;
}
