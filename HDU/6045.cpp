#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <cmath>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
#define PB push_back
#define PII pair<int, int>
#define REP(i, a, b) for(int i = a; i < b; i++)
#define PER(i, a, b) for(int i = b - 1; i >= a; i--)
#define ALL(x) x.begin(), x.end()

const int maxn = 80000 + 10;

char s[maxn], t[maxn];

int main() {
	int _; scanf("%d", &_);
	while(_--) {
		int n, x, y; scanf("%d%d%d", &n, &x, &y);
		if(x > y) swap(x, y);
		scanf("%s%s", s, t);
		int diff = 0;
		REP(i, 0, n) if(s[i] != t[i]) diff++;
		int same = n - diff;
		if(y - x > diff) printf("Lying\n");
		else {
			int maxx = same + (diff-y+x)/2;
			if(x > maxx) printf("Lying\n");
			else printf("Not lying\n");
		}
	}

	return 0;
}

