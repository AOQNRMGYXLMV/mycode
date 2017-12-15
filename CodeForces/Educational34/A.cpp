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
	int n; scanf("%d", &n);
	while(n--) {
		int x; scanf("%d", &x);
		bool ok = false;
		for(int j = 0; j <= x; j += 7) {
			if((x - j) % 3 == 0) {
				ok = true;
				break;
			}
		}
		if(ok) printf("YES\n");
		else printf("NO\n");
	}

	return 0;
}

