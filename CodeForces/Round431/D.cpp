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

const int maxn = 100000 + 10;

int n, w, h;

struct Dancer {
	int g, p, t, id;

	void read() { scanf("%d%d%d", &g, &p, &t); }

	bool operator < (const Dancer& r) const {
		if((p-t) < (r.p-r.t)) return true;
		if((p-t) > (r.p-r.t)) return false;
		if(g != r.g) return g > r.g;
		if(g == 1) return p < r.p;
		return p > r.p;
	}

	PII destination() {
		if(g == 1) return MP(p, h);
		else return MP(w, p);
	}
};

bool cmp(const PII& A, const PII& B) {
	return (A.second-A.first) > (B.second-B.first);
}

Dancer a[maxn];
PII ans[maxn], dest[maxn];


int main() {
	scanf("%d%d%d", &n, &w, &h);
	REP(i, 0, n) { a[i].read(); a[i].id = i; }
	sort(a, a + n);

	for(int i = 0, j; i < n; i = j) {
		j = i;
		while(j < n && (a[i].p-a[i].t) == (a[j].p-a[j].t)) j++;
		REP(k, i, j) dest[k-i] = a[k].destination();
		sort(dest, dest + j - i, cmp);
		REP(k, i, j) ans[a[k].id] = dest[k-i];
	}

	REP(i, 0, n) printf("%d %d\n", ans[i].first, ans[i].second);

	return 0;
}


