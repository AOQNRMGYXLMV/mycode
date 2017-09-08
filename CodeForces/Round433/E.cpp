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

struct Query {
	int id, l, d, r, u;

	void read() { scanf("%d%d%d%d", &l, &d, &r, &u); }

	bool operator < (const Query& t) const {
		return l < t.l;
	}
};

bool cmp(const Query& A, const Query& B) {
	return A.r > B.r;
}

int n, m;
int p[maxn];
Query q[maxn];
int lu[maxn], ld[maxn], ru[maxn], rd[maxn];

inline int lowbit(int x) { return x&(-x); }
int C[maxn];
void add(int x, int v) {
	while(x <= n) {
		C[x] += v;
		x += lowbit(x);
	}
}
int query(int x) {
	int ans = 0;
	while(x) {
		ans += C[x];
		x -= lowbit(x);
	}
	return ans;
}

inline LL C_2(LL x) {
	return x * (x - 1) / 2;
}

LL ans[maxn];

int main() {
	scanf("%d%d", &n, &m);
	REP(i, 1, n + 1) scanf("%d", p + i);
	REP(i, 0, m) {
		q[i].read();
		q[i].id = i;
	}

	sort(q, q + m);
	int point = 1;
	REP(i, 0, m) {
		while(point < q[i].l) { add(p[point], 1); point++; }
		ld[q[i].id] = query(q[i].d - 1);
		lu[q[i].id] = point - 1 - query(q[i].u);
	}

	sort(q, q + m, cmp);
	memset(C, 0, sizeof(C));
	point = n;
	REP(i, 0, m) {
		while(point > q[i].r) { add(p[point], 1); point--; }
		rd[q[i].id] = query(q[i].d - 1);
		ru[q[i].id] = n - point - query(q[i].u);
	}

	REP(i, 0, m) {
		int& id = q[i].id;
		LL& res = ans[id];
		res += C_2(q[i].l - 1);
		res += C_2(n - q[i].r);
		res += C_2(q[i].d - 1);
		res += C_2(n - q[i].u);
		res -= C_2(lu[id]);
		res -= C_2(ld[id]);
		res -= C_2(ru[id]);
		res -= C_2(rd[id]);
	}

	LL tot = C_2(n);
	REP(i, 0, m) printf("%lld\n", tot - ans[i]);

	return 0;
}


