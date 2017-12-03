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

int n, m, c;
const int maxn = 1000 + 10;
int a[maxn];

bool check() {
	if(!a[1]) return false;
	REP(i, 1, n) if(!a[i+1] || a[i] > a[i+1]) return false;
	return true;
}

int main() {
	scanf("%d%d%d", &n, &m, &c);
	int mid = c / 2;
	while(m--) {
		int x; scanf("%d", &x);
		if(x <= mid) {
			REP(i, 1, n + 1) if(!a[i] || a[i] > x) {
				a[i] = x;
				printf("%d\n", i);
				fflush(stdin);
				break;
			}
		} else {
			PER(i, 1, n + 1) if(!a[i] || a[i] < x) {
				a[i] = x;
				printf("%d\n", i);
				fflush(stdin);
				break;
			}
		}
#ifdef LOG
		printf("a:");
		REP(i, 1, n + 1) printf(" %d", a[i]);
		printf("\n");
#endif
		if(check()) return 0;
	}

	return 0;
}

