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

const int maxn = 20000 + 10;

struct Circle {
	int x, y, r;
	bool operator < (const Circle& t) const {
		return r < t.r;
	}
	void read() { scanf("%d%d%d", &x, &y, &r); }
};

int n;
Circle a[maxn];
vector<int> G[maxn];

#define sqr(x) ((x)*(x))

bool in(int i, int j) {
	return sqr(a[i].x-a[j].x)+sqr(a[i].y-a[j].y)<sqr(a[j].r-a[i].r);
}

int dfs(int u) {
	int ans = 0;
	for(int v : G[u])
		ans ^= (dfs(v) + 1);
	return ans;
}

int main() {
	int _; scanf("%d", &_);
	while(_--) {
		scanf("%d", &n);
		REP(i, 0, n + 1) G[i].clear();
		REP(i, 1, n + 1) a[i].read();
		sort(a + 1, a + n + 1);
		REP(i, 1, n + 1) {
			bool flag = false;
			REP(j, i + 1, n + 1) if(in(i, j)) {
				flag = true;
				G[j].PB(i);
				break;
			}
			if(!flag) G[0].PB(i);
		}
		if(dfs(0)) puts("Alice");
		else puts("Bob");
	}

	return 0;
}


