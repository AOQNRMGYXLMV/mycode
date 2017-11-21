#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
#define REP(i, a, b) for(int i = a; i < b; i++)
#define PER(i, a, b) for(int i = b - 1; i >= a; i--)
#define ALL(x) x.begin(), x.end()

const int maxn = 100 + 5;

char s[maxn];
int pre[maxn], suf[maxn];

int main() {
	scanf("%s", s + 1);
	int n = strlen(s + 1);
	REP(i, 1, n + 1) pre[i] = pre[i - 1] + (s[i] == 'Q');
	PER(i, 1, n + 1) suf[i] = suf[i + 1] + (s[i] == 'Q');

	int ans = 0;
	REP(i, 1, n) if(s[i] == 'A')
		ans += pre[i] * suf[i];
	printf("%d\n", ans);

	return 0;
}

