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

const int maxn = 100 + 10;

char s[maxn];

int main() {
	int n, m; scanf("%d%d", &n, &m);
	scanf("%s", s + 1);
	while(m--) {
		int l, r;
		char c1, c2;
		scanf("%d %d %c %c", &l, &r, &c1, &c2);
		REP(i, l, r + 1) if(s[i] == c1) s[i] = c2;
	}
	printf("%s\n", s + 1);

	return 0;
}

