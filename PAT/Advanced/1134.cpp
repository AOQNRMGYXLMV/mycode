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

const int maxn = 10000 + 10;
PII edges[maxn];
int k, cover[maxn];
int n, m;

int main() {
	scanf("%d%d", &n, &m);
	REP(i, 0, m) scanf("%d%d", &edges[i].first, &edges[i].second);
	memset(cover, -1, sizeof(cover));
	int q; scanf("%d", &q);
	while(q--) {
		scanf("%d", &k);
		REP(i, 0, k) {
			int v; scanf("%d", &v);
			cover[v] = q;
		}

		bool ok = true;
		REP(i, 0, m) {
			if(cover[edges[i].first] != q && cover[edges[i].second] != q) {
				ok = false;
				break;
			}
		}
		if(ok) printf("Yes\n");
		else printf("No\n");
	}

	return 0;
}

