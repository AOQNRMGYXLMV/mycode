#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

char str[20];

long long pow[15], sum[15];

void preprocess() {
	pow[0] = sum[0] = 1;
	for(int i = 1; i < 15; i++) {
		pow[i] = pow[i - 1] * 10;
		sum[i] = sum[i - 1] + pow[i];
	}
}

int main()
{
	preprocess();

	int T; scanf("%d", &T);
	while(T--) {
		scanf("%s", str);
		long long x = 0;
		for(int i = 4; str[i]; i++) x = x * 10 + str[i] - '0';
		int n = strlen(str) - 4;
		long long L = sum[n - 1] + 1989 - 1;
		while(x < L) x += pow[n];
		printf("%lld\n", x);
	}

	return 0;
}
