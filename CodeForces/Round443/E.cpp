#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
#define MP make_pair
#define PB push_back
#define REP(i, a, b) for(int i = a; i < b; i++)
#define PER(i, a, b) for(int i = b - 1; i >= a; i--)

int n, k;
const int maxk = 10;

struct Group {
	int sz, lo[maxk], hi[maxk];

	void read() {
		REP(i, 0, k) {
			scanf("%d", lo + i);
			hi[i] = lo[i];
		}
	}

	void merge(const Group& t) {
		sz += t.sz;
		REP(i, 0, k) {
			lo[i] = min(lo[i], t.lo[i]);
			hi[i] = max(hi[i], t.hi[i]);
		}
	}

	bool operator < (const Group& t) const {
		REP(i, 0, k) if(hi[i] > t.lo[i]) return false;
		return true;
	}
};

set<Group> S;

int main() {
	scanf("%d%d", &n, &k);
	while(n--) {
		Group g;
		g.sz = 1;
		g.read();
		set<Group>::iterator l = S.lower_bound(g), r = S.upper_bound(g);
		while(l != r) {
			g.merge(*l);
			l = S.erase(l);
		}
		S.insert(g);
		printf("%d\n", (*S.rbegin()).sz);
	}

	return 0;
}
