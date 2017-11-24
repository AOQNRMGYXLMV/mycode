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
	int a = 1, b = 2, c = 3;
	while(n--) {
		int win; scanf("%d", &win);
		if(win == a) swap(b, c);
		else if(win == b) swap(a, c);
		else { printf("NO\n"); return 0; }
	}
	printf("YES\n");

	return 0;
}

