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

const int maxn = 1000000;

bool vis[maxn + 1];
int n, m, k;

int main() {
	scanf("%d%d%d", &n, &m, &k); k--;
	int maxa = 1;
	while(n--) {
		int x; scanf("%d", &x);
		if(x > maxa) maxa = x;
		vis[x] = true;
	}

	int ans = 0;
	int cur = 0;
	REP(i, 1, m + 1) {
		if(vis[i]) {
			if(cur < k) cur++;
			else {
				vis[i] = false;
				ans++;
			}
		}
	}

	REP(i, 2, maxa-m+2) {
		if(vis[i-1]) cur--;
		if(vis[i+m-1]) {
			if(cur < k) cur++;
			else {
				ans++;
				vis[i+m-1] = false;
			}
		}
	}

	printf("%d\n", ans);

	return 0;
}

