#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
#define PB push_back
#define PII pair<int, int>
#define REP(i, a, b) for(int i = a; i < b; i++)
#define PER(i, a, b) for(int i = b - 1; i >= a; i--)
#define ALL(x) x.begin(), x.end()

char s[50];
LL k, p;

int main() {
	scanf("%lld%lld", &k, &p);

	LL ans = 0;
	REP(i, 1, k + 1) {
		sprintf(s, "%d", i);
		int l = strlen(s);
		LL t = 0;
		REP(j, 0, l) t = ((t * 10 % p) + (s[j] - '0')) % p;
		PER(j, 0, l) t = ((t * 10 % p) + (s[j] - '0')) % p;
		ans += t; if(ans >= p) ans -= p;
	}
	printf("%lld\n", ans);

	return 0;
}

