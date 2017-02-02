#include <cstdio>
#include <cstring>

int main()
{
	int T; scanf("%d", &T);
	while(T--) {
		int n; scanf("%d", &n);
		int center = 0, free = 0;
		while(n--) {
			int x; scanf("%d", &x);
			if(x & 1) center++;
			free += x >> 1;
		}
		if(!center) { printf("%d\n", free << 1); continue; }
		printf("%d\n", free / center * 2 + 1);
	}

	return 0;
}
