#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <set>
#include <vector>
#include <iostream>
#include <string>
#include <cmath>
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

const int maxn = 1000 + 10;

struct Circle {
	double x, y, r;
	void read() { scanf("%lf%lf%lf", &x, &y, &r); }
	bool operator < (const Circle& t) const {
		return r < t.r;
	}
};

int n;
Circle a[maxn];
vector<int> G[maxn];

#define sqr(x) ((x)*(x))

const double PI = acos(-1.0);
const double eps = 1e-8;

int dcmp(double x) {
	if(fabs(x) < eps) return 0;
	return x < 0 ? -1 : 1;
}

bool in(int i, int j) {
	return dcmp(sqr(a[i].x-a[j].x)+sqr(a[i].y-a[j].y)-sqr(a[j].r-a[i].r)) <= 0;
}

double ans;

void dfs(int u, int d) {
	if(d) {
		if(d == 1 || (d % 2 == 0)) ans += sqr(a[u].r);
		else ans -= sqr(a[u].r);
	}
	for(int v : G[u]) dfs(v, d + 1);
}

int main() {
	scanf("%d", &n);
	REP(i, 1, n + 1) a[i].read();
	sort(a + 1, a + n + 1);
	REP(i, 1, n + 1) {
		bool find = false;
		REP(j, i + 1, n + 1) if(in(i, j)) {
			G[j].PB(i);
			find = true;
			break;
		}
		if(!find) G[0].PB(i);
	}

	dfs(0, 0);
	printf("%.10f\n", ans * PI);

	return 0;
}


