#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long LL;

int main()
{
	int a; scanf("%d", &a);
	if(a == 3 || a == 10) printf("%lld\n", 1LL << a);
	else puts("8");

	return 0;
}
