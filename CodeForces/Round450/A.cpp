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
	int l = 0, r = 0;
	int n; scanf("%d", &n);
	while(n--) {
		int x, y; scanf("%d%d", &x, &y);
		if(x < 0) l++;
		else r++;
	}

	if(l <= 1 || r <= 1) printf("Yes\n");
	else printf("No\n");

	return 0;
}

