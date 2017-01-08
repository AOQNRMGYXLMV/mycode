#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long LL;

int main()
{
	int n;
	LL x;
	scanf("%d%lld", &n, &x);
	int ans = 0;
	while(n--) {
		char op[5]; scanf("%s", op);
		int d; scanf("%d", &d);
		if(op[0] == '+') x += d;
		else {
			if(x < d) ans++;
			else x -= d;
		}
	}

	printf("%lld %d\n", x, ans);

	return 0;
}
