#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

struct Node
{
	int p, d;
	Node(int p, int d): p(p), d(d) {}
	bool operator < (const Node& t) const {
		return p > t.p || (p == t.p && d > t.d);
	}
};

priority_queue<Node> Q;

int main()
{
	int T; scanf("%d", &T);
	while(T--) {
		int n; scanf("%d", &n);
		while(n--) {
			int p, d; scanf("%d%d", &p, &d);
			Q.push(Node(p, d));
		}
		int id = 1, ans;
		while(!Q.empty()) {
			Node t = Q.top(); Q.pop();
			ans = t.p;
			if(id) Q.push(Node(t.p + t.d, t.d));
			id ^= 1;
		}
		printf("%d\n", ans);
	}

	return 0;
}
