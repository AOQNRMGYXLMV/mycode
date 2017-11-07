#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <bitset>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
#define REP(i, a, b) for(int i = a; i < b; i++)
#define PER(i, a, b) for(int i = b - 1; i >= a; i--)
#define ALL(x) x.begin(), x.end()

const int maxn = 100000 + 10;
const int maxk = 12;

int a[maxk][maxn];
bitset<1<<maxk> S[maxn * 2];

int n, k, q;

int main() {
	scanf("%d%d%d", &n, &k, &q);
	int all = 1 << k;
	REP(i, 0, k) {
		REP(j, 0, n) scanf("%d", &a[i][j]);
		REP(j, 0, all) if((j>>i)&1) S[i].set(j, true);
	}

	int cnt = k;
	while(q--) {
		int t, x, y; scanf("%d%d%d", &t, &x, &y);
		x--; y--;
		if(t == 1) S[cnt++] = S[x] & S[y];
		else if(t == 2) S[cnt++] = S[x] | S[y];
		else {
			vector<PII> b; b.clear();
			REP(i, 0, k) b.push_back(make_pair(a[i][y], i));
			sort(ALL(b));
			int bit = 0;
			REP(i, 0, k) {
				bit |= (1 << b[i].second);
				if(S[x][bit]) { printf("%d\n", b[i].first); break; }
			}
		}
	}

	return 0;
}

