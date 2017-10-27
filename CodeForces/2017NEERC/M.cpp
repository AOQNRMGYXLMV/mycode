#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
	int x1, y1, x2, y2;
	scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
	int ans = (abs(x1-x2)+abs(y1-y2)) * 2 + 4;
	if(x1 == x2 || y1 == y2) ans += 2;
	printf("%d\n", ans);

	return 0;
}
