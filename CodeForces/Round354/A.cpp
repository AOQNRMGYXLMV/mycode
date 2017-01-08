#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
	int n; scanf("%d", &n);
	int a, b;
	for(int i = 1; i <= n; i++) {
		int x; scanf("%d", &x);
		if(x == 1) a = i;
		else if(x == n) b = i;
	}

	int ans1 = max(a - 1, n - a);
	int ans2 = max(b - 1, n - b);
	printf("%d\n", max(ans1, ans2));

	return 0;
}
