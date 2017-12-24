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

const int maxn = 200000 + 10;

int n, h[maxn], pre[maxn];

int main() {
	scanf("%d", &n);
	bool unique = true;
	int pos;
	REP(i, 0, n + 1) {
		scanf("%d", h + i);
		if(i && h[i] > 1 && h[i-1] > 1) {
			unique = false;
			pos = i;
		}
	}
	pre[0] = h[0];
	REP(i, 1, n + 1) pre[i] = pre[i-1] + h[i];
	
	if(unique) { printf("perfect\n"); return 0; }
	else printf("ambiguous\n");

	printf("0");
	REP(i, 1, n + 1) REP(j, 0, h[i])
		printf(" %d", pre[i-1]);
	printf("\n");

	printf("0");
	REP(i, 1, n + 1) {
		if(i == pos) {
			printf(" %d", pre[i-1]-1);
			REP(j, 1, h[i]) printf(" %d", pre[i-1]);
		} else {
			REP(j, 0, h[i])
				printf(" %d", pre[i-1]);
		}
	}
	printf("\n");

	return 0;
}

