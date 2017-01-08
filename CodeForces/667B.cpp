#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 100000 + 10;

int n, h, k;
int a[maxn];

int main()
{
	scanf("%d%d%d", &n, &h, &k);
	for(int i = 1; i <= n; i++) scanf("%d", a + i);
	int p = 1, curh = 0, time = 0;
	while(p <= n || curh) {
		while(curh + a[p] <= h) { curh += a[p]; p++; }

	}

	

	return 0;
}
