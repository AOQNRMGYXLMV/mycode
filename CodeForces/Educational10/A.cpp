#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int h1, h2, a, b;

int main()
{
	scanf("%d%d%d%d", &h1, &h2, &a, &b);
	int h = h2 - h1;
	int day = 0;
	if(h <= 8 * a) { printf("0\n"); return 0; }
	if(a <= b) { printf("-1\n"); return 0; }
	for(int i = 0; i < 200000 + 10; i++) {
		h -= a * 8;
		if(h <= 0) { printf("%d\n", day); return 0; }
		day++;
		h += b * 12;
		h -= a * 4;
		if(h <= 0) { printf("%d\n", day); return 0; }
	}
	printf("-1\n");

	return 0;
}
