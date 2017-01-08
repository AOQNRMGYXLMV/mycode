#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int a[5000 + 10];

void init() {
	for(int i = 1; i <= 5000; i++) {
		a[i] = 0;
		for(int j = 1; j < i; j++)
			a[i] = (a[i] + i - j) % (j + 1);
		a[i]++;
	}
}

int main()
{
	init();
	int T; scanf("%d", &T);
	while(T--) {
		int x; scanf("%d", &x);
		printf("%d\n", a[x]);
	}

	return 0;
}
