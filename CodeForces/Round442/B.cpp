#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
#define MP make_pair
#define PB push_back
#define REP(i, a, b) for(int i = a; i < b; i++)
#define PER(i, a, b) for(int i = b - 1; i >= a; i--)

const int maxn = 5000 + 10;

char s[maxn];
int sum[maxn];

int main() {
	scanf("%s", s + 1);
	int n = strlen(s + 1);
	REP(i, 1, n + 1) {
		sum[i] = sum[i - 1];
		if(s[i] == 'a') sum[i]++;
	}

	int ans = sum[n];
	REP(i, 1, n + 1) if(s[i] == 'b')
		REP(j, i, n + 1) if(s[j] == 'b') {
			ans = max(ans, j-i+1 - (sum[j] - sum[i]) + sum[i-1] + sum[n] - sum[j]);
		}

	printf("%d\n", ans);

	return 0;
}

