#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long LL;

int n;

int mul(int a, int b) { return (LL)a * b % n; }

int pow_mod(int a, int p) {
	int ans = 1;
	while(p) {
		if(p & 1) ans = mul(ans, a);
		a = mul(a, a);
		p >>= 1;
	}
	return ans;
}

int main()
{
	scanf("%d", &n);

	if(n == 1) { printf("YES\n1\n"); return 0; }

	if(n == 4) { printf("YES\n1\n3\n2\n4\n"); return 0; }

	bool isprime = true;
	for(int i = 2; i * i <= n; i++) if(n % i == 0) {
		isprime = false; break;
	}

	if(!isprime) { printf("NO\n"); return 0; }

	printf("YES\n1\n");
	for(int i = 2; i < n; i++)
		printf("%d\n", mul(i, pow_mod(i - 1, n - 2)));
	printf("%d\n", n);

	return 0;
}
