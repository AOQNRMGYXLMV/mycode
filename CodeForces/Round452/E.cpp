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

const int maxn = 200000 + 10;

int n, a[maxn], l[maxn], ext[maxn];
int pl[maxn], pr[maxn];

struct Node {
	int s, l;
	Node(int s, int l): s(s), l(l) {}
	bool operator < (const Node& t) const {
		return l > t.l || (l == t.l && s < t.s);
	}
};

set<Node> S;

int main() {
	scanf("%d", &n);
	REP(i, 1, n + 1) scanf("%d", a + i);
	l[n] = 1;
	ext[n] = n;
	PER(i, 1, n) {
		if(a[i] == a[i+1]) {
			ext[i] = ext[i+1];
			l[i] = l[i+1] + 1;
		} else {
			ext[i] = i;
			l[i] = 1;
		}
	}
	int pre = 0;
	REP(i, 1, n + 1) {
		if(i == 1 || a[i] != a[i-1]) {
			pl[i] = pre;
			pr[i] = ext[i] + 1;
			S.insert(Node(i, l[i]));
			//printf("S.insert(%d, %d)\n", i, l[i]);
			pre = i;
		}
	}

	int ans = 0;
	while(!S.empty()) {
		Node x = *S.begin(); S.erase(S.begin());
		ans++;
		if(S.empty()) break;
		int& s = x.s;
		int lft = pl[s], rgh = pr[s];
		pl[rgh] = lft;
		pr[lft] = rgh;
		if(lft == 0) { pl[rgh] = 0; continue; }
		if(rgh == n + 1) { pr[lft] = n + 1; continue; }
		if(a[lft] != a[rgh]) continue;
		S.erase(Node(lft, l[lft]));
		S.erase(Node(rgh, l[rgh]));
		S.insert(Node(lft, l[lft] + l[rgh]));
		l[lft] += l[rgh];
		rgh = pr[rgh];
		pl[rgh] = lft;
		pr[lft] = rgh;
	}

	printf("%d\n", ans);

	return 0;
}

