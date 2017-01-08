#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 50;

int n, cur, x, y;
int a[maxn][maxn];

void go(int flag = 0) {
	if(flag) { x++; if(x == n) x = 0; return; }
	y++; if(y == n) y = 0;
	x--; if(x < 0) x = n - 1;
}

int main()
{
	scanf("%d", &n);
	y = n >> 1;
	x = 0;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			a[x][y] = ++cur;
			if(j == n - 1) go(1);
			else go();
		}

	}

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n - 1; j++) printf("%d ", a[i][j]);
		printf("%d\n", a[i][n - 1]);
	}

	return 0;
}
