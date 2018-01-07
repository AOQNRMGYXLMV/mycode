#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
#define PB push_back
#define PII pair<int, int>
#define REP(i, a, b) for(int i = a; i < b; i++)
#define PER(i, a, b) for(int i = b - 1; i >= a; i--)
#define ALL(x) x.begin(), x.end()

#define cnt(x, y) (x-y+1)

const int maxn = 100000 + 10;

int n, m, r, k;

struct Node {
	PII p;
	int v;
	Node() {}
	Node(PII p, int v = 0): p(p), v(v) {}
	void calc() {
		int t1 = cnt(n, r) - max(0, cnt(p.first-1, r)) - max(0, cnt(n-p.first, r));
		int t2 = cnt(m, r) - max(0, cnt(p.second-1, r)) - max(0, cnt(m-p.second, r));
		v = t1 * t2;

	}
	bool operator < (const Node& t) const {
		return v < t.v;
	}
};

priority_queue<Node> Q;
set<PII> vis;

int dx[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dy[] = { -1, 0, 1, -1, 1, -1, 0, 1 };

bool in(PII x) {
	return 1<=x.first&&x.first<=n&&1<=x.second&&x.second<=m;
}

int main() {
	scanf("%d%d%d%d", &n, &m, &r, &k);
	PII s((n+1)/2, (m+1)/2);
	Node t(s);
	t.calc();
	vis.insert(s);
	Q.push(t);

	LL tot = 0;
	while(k--) {
		t = Q.top(); Q.pop();
		tot += t.v;
		REP(i, 0, 8) {
			PII nxt(t.p.first+dx[i], t.p.second+dy[i]);
			if(!in(nxt)) continue;
			if(vis.count(nxt)) continue;
			vis.insert(nxt);
			Node nnxt(nxt);
			nnxt.calc();
			Q.push(nnxt);
		}
	}

	printf("%.10f\n", (double)tot / (double)(n-r+1) / (double)(m-r+1));

	return 0;
}

