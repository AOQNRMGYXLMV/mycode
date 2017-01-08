#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int f(int x) {
	int ans = 0;
	for(int i = 1; i < x; i++) ans += i ^ (x - i);
	return ans;
}

int main()
{
	int x;
	while(scanf("%d", &x) == 1) printf("%d\n", f(x));

	return 0;
}
