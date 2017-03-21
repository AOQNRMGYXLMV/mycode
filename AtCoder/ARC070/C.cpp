#include <cstdio>

typedef long long LL;

int main()
{
	LL X; scanf("%lld", &X);
	LL L = 0, R = X;
	while(L < R) {
		LL M = (L + R + 1) / 2;
		if(M * (M + 1) / 2 <= X) L = M;
		else R = M - 1;
	}

	if(L * (L + 1) / 2 == X) { printf("%lld\n", L); return 0; }
	printf("%lld\n", L + 1);

	return 0;
}
