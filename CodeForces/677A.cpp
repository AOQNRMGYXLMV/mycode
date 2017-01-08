#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
	int n, h; scanf("%d%d", &n, &h);

	int ans = 0;
	while(n--) {
		int x; scanf("%d", &x);
		if(x > h) ans++;
		ans++;
	}

	printf("%d\n", ans);

	return 0;
}
