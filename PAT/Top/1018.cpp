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

const int maxn = 100000 + 10;
const LL MOD = 1000000007LL;
char s[maxn];
LL p[maxn];

LL mul(LL a, LL b) { return a * b % MOD; }
void add(LL& a, LL b) { a += b; if(a >= MOD) a -= MOD; }

int main() {
	scanf("%s", s);
	int n = strlen(s);
	p[0] = 1;
	REP(i, 1, n) p[i] = mul(p[i-1], 10LL);
	REP(i, 1, n) add(p[i], p[i-1]);

	LL ans = 0;
	LL cnt = 0;
	REP(i, 0, n) {
		s[i] -= '0';
		if(!s[i]) continue;
		cnt++;
		add(ans, mul(cnt, mul((LL)s[i], p[n-i-1])));
	}
	printf("%lld\n", ans);

	return 0;
}

