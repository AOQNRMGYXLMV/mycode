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

int main() {
	int n, m; scanf("%d%d", &n, &m);
	int l = 0, r = 0;
	while(n--) {
		int a, b; scanf("%d%d", &a, &b);
		if(a <= r) r = max(r, b);
	}

	printf("%s\n", r >= m ? "YES" : "NO");

	return 0;
}

