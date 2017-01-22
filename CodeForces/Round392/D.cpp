#include <cstdio>
#include <cstring>

typedef long long LL;

char s[100];
int k[100];
LL pow[10];

int main()
{
	LL base;
	scanf("%lld", &base);
	scanf("%s", s);
	int n = strlen(s);
	for(int i = 0; i < n; i++) k[i] = s[i] - '0';
	pow[0] = 1;
	for(int i = 1; i < 10; i++) pow[i] = pow[i - 1] * 10;

	LL ans = 0, p = 1;
	for(int i = n - 1, j; i >= 0; i = j - 1) {
		LL t = 0;
		for(j = i; j >= 0 && pow[i-j]<base && t+pow[i-j]*k[j]<base; j--) {
			t += pow[i-j]*k[j];
		}
		for(j++; j<i && k[j]==0; j++);
		ans += t * p;
		p *= base;
	}

	printf("%lld\n", ans);

	return 0;
}
