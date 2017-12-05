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

const int maxn = 100000 + 10;
const int INF = 0x3f3f3f3f;

int a[maxn];

struct Node {
	Node* ch[2];
	int s, v, minv;
	bool flip; int add;
	void maintain() {
		minv = min(v, min(ch[0]->minv, ch[1]->minv));
		s = ch[0]->s + ch[1]->s + 1;
	}
	int cmp(int k) {
		k -= ch[0]->s + 1;
		if(!k) return -1;
		return k < 0 ? 0 : 1;
	}
	void pushdown();
};

int tot = 0;
Node pool[maxn << 1], *null;

void Node::pushdown() {
	if(flip) {
		flip = false;
		swap(ch[0], ch[1]);
		ch[0]->flip ^= 1;
		ch[1]->flip ^= 1;
	}
	if(add) {
		if(ch[0] != null) {
			ch[0]->add += add;
			ch[0]->v += add;
			ch[0]->minv += add;
		}
		if(ch[1] != null) {
			ch[1]->add += add;
			ch[1]->v += add;
			ch[1]->minv += add;
		}
		add = 0;
	}
}

Node* newnode(int v) {
	Node* p = pool + tot; tot++;
	p->ch[0] = p->ch[1] = null;
	p->s = 1; p->v = p->minv = v;
	p->add = 0; p->flip = false;
	return p;
}

void rotate(Node* &o, int d) {
	Node* k = o->ch[d^1]; o->ch[d^1] = k->ch[d];
	k->ch[d] = o; o->maintain(); k->maintain();
	o = k;
}

void splay(Node* &o, int k) {
	o->pushdown();
	int d = o->cmp(k);
	if(d == -1) return;
	if(d == 1) k -= o->ch[0]->s + 1;
	Node* &p = o->ch[d];
	p->pushdown();
	int d2 = o->ch[d]->cmp(k);
	if(d2 == -1) { rotate(o, d^1); return; }
	int k2 = k;
	if(d2 == 1) k2 -= p->ch[0]->s + 1;
	splay(p->ch[d2], k2);
	if(d == d2) { rotate(o, d^1); rotate(o, d^1); }
	else { rotate(p, d); rotate(o, d^1); }
}

void split(Node* o, int k, Node* &left, Node* &right) {
	splay(o, k);
	left = o;
	right = o->ch[1];
	left->ch[1] = null;
	left->maintain();
}

Node* merge(Node* left, Node* right) {
	splay(left, left->s);
	left->ch[1] = right;
	left->maintain();
	return left;
}

Node* build(int l, int r) {
	if(l > r) return null;
	int mid = (l + r) / 2;
	Node* p = newnode(a[mid]);
	p->ch[0] = build(l, mid - 1);
	p->ch[1] = build(mid + 1, r);
	p->maintain();
	return p;
}

void splayInit() {
	tot = 0;
	null = new Node;
	null->ch[0] = null->ch[1] = null;
	null->s = 0; null->v = null->minv = INF;
}

void dbgEdge(Node* o) {
	if(o->ch[0] != null) {
		printf("%d %d\n", o->v, o->ch[0]->v);
		dbgEdge(o->ch[0]);
	}
	if(o->ch[1] != null) {
		printf("%d %d\n", o->v, o->ch[1]->v);
		dbgEdge(o->ch[1]);
	}
}

void dbgNode(Node* o) {
	o->pushdown();
	if(o->ch[0] != null) dbgNode(o->ch[0]);
	printf("%d ", o->v);
	if(o->ch[1] != null) dbgNode(o->ch[1]);
}

void print(Node* o, const char s[]) {
	printf("%s\n", s);
	dbgNode(o); printf("\n");
}

//#define LOCAL

int main() {
	int n, m;
	while(scanf("%d", &n) == 1) {
		splayInit();
		a[0] = INF;
		REP(i, 1, n + 1) scanf("%d", a + i);
		Node* root = build(0, n);

#ifdef LOCAL
		print(root, "build:");
#endif

		scanf("%d", &m);
		char cmd[10];
		int x, y;
		while(m--) {
			scanf("%s%d", cmd, &x);
			if(cmd[0] == 'A') {
				int D; scanf("%d%d", &y, &D);
				Node *o, *left, *mid, *right;
				split(root, x, left, o);
				split(o, y-x+1, mid, right);
				mid->add += D;
				mid->v += D;
				mid->minv += D;
				root = merge(merge(left, mid), right);
			} else if(cmd[0] == 'R' && cmd[3] == 'E') {
				scanf("%d", &y);
				Node *o, *left, *mid, *right;
				split(root, x, left, o);
				split(o, y-x+1, mid, right);
				mid->flip ^= 1;
				root = merge(merge(left, mid), right);
			} else if(cmd[0] == 'R' && cmd[3] == 'O') {
				int T; scanf("%d%d", &y, &T);
				int len = y - x + 1;
				T %= len; if(T < 0) T += len;
				if(!T) continue;
				T = y-x+1 - T;
				Node *o, *left, *midl, *midr, *right;
				split(root, x, left, o);
				split(o, T, midl, o);
				split(o, y-x+1-T, midr, right);
				root = merge(merge(merge(left, midr), midl), right);
			} else if(cmd[0] == 'I') {
				int P; scanf("%d", &P);
				Node* p = newnode(P), *left, *right;
				split(root, x+1, left, right);
				root = merge(merge(left, p), right);
			} else if(cmd[0] =='D') {
				Node* left, *mid, *right;
				split(root, x, left, mid);
				split(mid, 1, mid, right);
				root = merge(left, right);
			} else {
				scanf("%d", &y);
				Node* left, *mid, *right;
				split(root, x, left, mid);
				split(mid, y-x+1, mid, right);
				printf("%d\n", mid->minv);
				root = merge(merge(left, mid), right);
			}
#ifdef LOCAL
			print(root, "after:");
#endif
		}

		delete null;
	}

	return 0;
}
