#include <cstdio>

const int maxn = 1000 + 10;

int calc(int x) {
	int ans = x + 1, i;
	for(i = 2; i * i < x; i++) if(x % i == 0) {
		ans += i; ans += x / i;
	}
	if(i * i == x) ans += i;
	return ans;
}

int f[maxn];

int main()
{
	f[1] = 1;
	for(int i = 2; i < 1000; i++) f[i] = calc(i);
	int kase = 1, x;
	while(scanf("%d", &x) == 1 && x) {
		printf("Case %d: ", kase++);
		bool ok = false;
		for(int i = x; i; i--) if(f[i] == x) {
			printf("%d\n", i);
			ok = true;
			break;
		}
		if(!ok) printf("-1\n");
	}

	return 0;
}
