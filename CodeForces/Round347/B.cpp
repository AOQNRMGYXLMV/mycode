#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 100 + 10;
int a[maxn];

int main()
{
	int n, cnt = 1, add = 1, sub = 0;
	getchar();
	a[1] = 1;
	for(;;) {
		char c;
		getchar();
		c = getchar();
		if(c == '=') break;
		a[++cnt] = (c == '+' ? 1 : -1);
		if(c == '+') add++; else sub++;
		getchar();
		getchar();
	}

	scanf("%d", &n);
	
	int Max = add * n - sub;
	int Min = add - sub * n;
	if(n < Min || n > Max) { printf("Impossible\n"); return 0; }
	int delta = add - sub - n;

	for(int i = 1; i <= cnt && delta; i++) {
		if(delta > 0 && a[i] == -1) {
			int t = min(delta, n - 1);
			a[i] -= t;
			delta -= t;
			
		}
		else if(delta < 0 && a[i] == 1) {
			int t = min(-delta, n - 1);
			a[i] += t;
			delta += t;
		}
	}

	printf("Possible\n");
	printf("%d", a[1]);
	for(int i = 2; i <= cnt; i++) {
		printf(" ");
		printf("%c %d", a[i] > 0 ? '+' : '-', abs(a[i]));
	}
	printf(" = %d\n", n);

	return 0;
}
