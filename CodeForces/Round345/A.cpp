#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
	int a, b; scanf("%d%d", &a, &b);
	int ans = 0;
	while(a > 0 && b > 0) {
		if(a == 1 && b == 1) break;
		if(a > b) swap(a, b);
		a++; b -= 2;
		ans++;
	}

	printf("%d\n", ans);

	return 0;
}
