#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
	int n, a, b;
	scanf("%d%d%d", &n, &a, &b);
	a--;
	b = ((b % n) + n) % n;
	a = (a + b) % n;
	printf("%d\n", a + 1);

	return 0;
}
