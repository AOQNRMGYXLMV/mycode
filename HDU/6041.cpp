#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
#define PB push_back
#define PII pair<int, int>
#define REP(i, a, b) for(int i = a; i < b; i++)
#define PER(i, a, b) for(int i = b - 1; i >= a; i--)
#define ALL(x) x.begin(), x.end()

const int maxn = 1000 + 10;
int n, m, K;

namespace IO {
    #define BUF_SIZE 500000

    bool inline nc(char& c) {
        static char buf[BUF_SIZE], *p = buf + BUF_SIZE, *pend = buf + BUF_SIZE;
        if(p == pend) {
            p = buf;
            pend = buf + fread(buf, 1, BUF_SIZE, stdin);
            if(pend == buf) { c = ' '; return false; }
        }
        c = *p++;
        return true;
    }

    bool read(int& x) {
        char c = ' ';
        x = 0;
        while(c < '0' || c > '9') if(!nc(c)) return false;
        while('0' <= c && c <= '9') { x = (x<<1)+(x<<3)+c-'0'; nc(c); }
        return true;
    }

    #undef BUF_SIZE
};

using namespace IO;

struct Node {
	int pa, pb, w;
	bool operator < (const Node& t) const {
		return w < t.w;
	}
};

vector<int> ans, w;
void merge(vector<int>& a, vector<int>& b) {
	priority_queue<Node> Q;
	for(int i = 0; i < b.size(); i++) {
		Q.push((Node){0, i, a[0] + b[i]});
	}
	w.resize(0);
	while(w.size() < K && !Q.empty()) {
		Node x = Q.top(); Q.pop();
		w.PB(x.w);
		if(x.pa + 1 < a.size()) {
			x.pa++;
			Q.push((Node){x.pa, x.pb, a[x.pa] + b[x.pb]});
		}
	}
	a = w;
}

struct Edge {
	int v, w, nxt;
	Edge() {}
	Edge(int v, int w, int nxt): v(v), w(w), nxt(nxt) {}
};

int head[maxn], ecnt;
Edge edges[maxn << 2];

void addEdge(int u, int v, int w) {
	edges[ecnt] = Edge(v, w, head[u]);
	head[u] = ecnt++;
	edges[ecnt] = Edge(u, w, head[v]);
	head[v] = ecnt++;
}

stack<int> S;

int pre[maxn], low[maxn], dfs_clock;
void dfs(int u, int p = 0) {
	pre[u] = low[u] = ++dfs_clock;
	for(int i = head[u]; ~i; i = edges[i].nxt) {
		int v = edges[i].v;
		if(!pre[v]) {
			S.push(i);
			dfs(v, i ^ 1);
			low[u] = min(low[u], low[v]);
			if(low[v] >= pre[u]) {
				int j;
				vector<int> circle;
				do {
					j = S.top(); S.pop();
					circle.PB(edges[j].w);
				} while(j != i);
				if(circle.size() == 1) continue;
#ifdef DEBUG
				printf("DEBUG:\n");
				for(int x : circle) printf("%d ", x); printf("\n");
#endif
				merge(ans, circle);
			}
		} else if(i != p && pre[v] < pre[u]) {
			S.push(i);
			low[u] = min(low[u], pre[v]);
		}
	}
}

void init() {
	memset(pre, 0, sizeof(pre));
	memset(head, -1, sizeof(head));
	dfs_clock = ecnt = 0;
	ans.resize(0);
	ans.push_back(0);
}

int main() {
	int _ = 0;
	ans.reserve(100000 + 10);
	w.reserve(100000 + 10);
//	while(scanf("%d%d", &n, &m) == 2) {
	while(read(n) && read(m)) {
		init();
		unsigned sum = 0;
		while(m--) {
			int u, v, w; //scanf("%d%d%d", &u, &v, &w);
			read(u); read(v); read(w);
			addEdge(u, v, w);
			sum += w;
		}
//		scanf("%d", &K);
		read(K);

		dfs(1);
		unsigned res = 0;
		for(unsigned i = 0; i < ans.size(); i++) {
			res += (i + 1) * (sum - ans[i]);
		}
		printf("Case #%d: %u\n", ++_, res);
	}

	return 0;
}

