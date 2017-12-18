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

const int maxq = 40000;
const int maxn = 200000 + 10;
const int maxa = 1000000000;

int p, sqr[maxq];
int n, a[maxn];
int lb[maxn];
bool is[maxn];
vector<int> cost;

int main() {
	for(int i = 0; ; i++) {
		sqr[p++] = i * i;
		if(i * i > maxa) break;
	}
	int cnt = 0;
	scanf("%d", &n);
	REP(i, 0, n) {
		scanf("%d", a + i);
		int& t = lb[i];
		t = lower_bound(sqr, sqr + p, a[i]) - sqr;
		if(t < p && sqr[t] == a[i]) cnt++, is[i] = true;
	}
	
	if(cnt == n / 2) { printf("0\n"); return 0; }
	int change;
	if(cnt < n / 2) {
		change = n / 2 - cnt;
		REP(i, 0, n) if(!is[i]) {
			int& t = lb[i];
			cost.PB(min(sqr[t]-a[i], a[i]-sqr[t-1]));
		}
	} else {
		change = cnt - n / 2;
		REP(i, 0, n) if(is[i]) {
			if(a[i] == 0) cost.PB(2);
			else cost.PB(1);
		}
	}

	sort(ALL(cost));
	LL ans = 0;
	REP(i, 0, change) ans += cost[i];
	printf("%lld\n", ans);

	return 0;
}

