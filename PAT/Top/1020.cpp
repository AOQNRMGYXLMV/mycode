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

const int maxn = 1000000 + 10;

char s[maxn];
LL cnt;

int main() {
	scanf("%s", s);
	int n = strlen(s);
	LL ans = 1;
	cnt = 0;
	for(int i = 0, j; i < n; i = j) {
		for(j = i; s[j] == s[i]; j++);
		cnt++;
		if(j - i > 1) ans++;
	}
	ans += cnt * (cnt + 1) / 2;
	REP(i, 2, n) if(s[i] != s[i-1] && s[i] == s[i-2]) ans--;
	printf("%lld\n", ans);

	return 0;
}

