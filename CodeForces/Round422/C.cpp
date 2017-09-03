#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <set>
#include <vector>
#include <iostream>
#include <string>
using namespace std;
#define REP(i, a, b) for(int i = a; i < b; i++)
#define PER(i, a, b) for(int i = b - 1; i >= a; i--)
#define SZ(a) ((int)a.size())
#define MP make_pair
#define PB push_back
#define EB emplace_back
#define ALL(a) a.begin(), a.end()
typedef long long LL;
typedef pair<int, int> PII;

const int maxn = 200000 + 10;

struct Segment {
	int l, r, cost;
	void read() { scanf("%d%d%d", &l, &r, &cost); }
	bool operator < (const Segment& t) const {
		return l < t.l || (l == t.l && cost < t.cost);
	}
};

vector<Segment> a[maxn];
vector<int> suf[maxn];

int main() {
	int n, x; scanf("%d%d", &n, &x);
	int maxl = 0;
	REP(i, 0, n) {
		Segment t;
		t.read();
		int len = t.r - t.l + 1;
		a[len].PB(t);
		if(len > maxl) maxl = len;
	}
	REP(i, 1, maxl + 1) sort(ALL(a[i]));

	REP(i, 1, x + 1) {
		if(a[i].empty()) continue;
		int sz = SZ(a[i]);
		suf[i].resize(sz);
		suf[i][sz-1] = a[i][sz-1].cost;
		PER(j, 0, sz - 1) {
			suf[i][j] = min(suf[i][j+1], a[i][j].cost);
		}
	}

	int ans = -1;
	REP(i, 1, x + 1) {
		if(a[x - i].empty()) continue;
		int p = 0;
		int sz = SZ(a[x - i]);
		for(Segment t : a[i]) {
			while(p < sz && a[x - i][p].l <= t.r) p++;
			if(p >= sz) break;
			int cur = t.cost + suf[x - i][p];
			if(ans == -1 || cur < ans) ans = cur;
		}
	}

	printf("%d\n", ans);

	return 0;
}


