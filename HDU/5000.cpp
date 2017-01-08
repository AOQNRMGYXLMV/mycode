#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MOD = 1000000007;

void add(int& a, int b) {
	a += b; if(a >= MOD) a -= MOD;
}

int n;
int a[2000 + 10], d[2][1000 + 10];

int main()
{
	int T; scanf("%d", &T);
	while(T--) {
		scanf("%d", &n);
		int sum = 0;
		for(int i = 1; i <= n; i++) {
			scanf("%d", a + i);
			sum += a[i];
		}
		sum >>= 1;
		memset(d[0], 0, sizeof(d[0]));
		d[0][0] = 1;
		int cur = 0, tsum = 0;
		for(int i = 1; i <= n; i++) {
			cur ^= 1;
			memset(d[cur], 0, sizeof(d[cur]));
			for(int j = 0; j <= tsum; j++) {
				for(int k = 0; k <= a[i] && j + k <= sum; k++) {
					add(d[cur][j + k], d[cur ^ 1][j]);
				}
			}
			tsum += a[i];
		}
		printf("%d\n", d[cur][sum]);
	}

	return 0;
}
