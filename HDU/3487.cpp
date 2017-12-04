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

const int maxn = 300000 + 10;

int n, m;

struct Node {
	int v, s;
	Node* ch[2];
	bool flip;
	int cmp(int x) {
		x -= ch[0]->s + 1;
		if(!x) return -1;
		return x < 0 ? 0 : 1;
	}
	void maintain() {
		s = ch[0]->s + ch[1]->s + 1;
	}
	void pushdown() {
		if(flip) {
			flip = false;
			swap(ch[0], ch[1]);
			ch[0]->flip = !ch[0]->flip;
			ch[1]->flip = !ch[1]->flip;
		}
	}
};

int tot;
Node pool[maxn], *null;

Node* newnode(int v) {
	Node* p = pool + tot;
	tot++;
	p->ch[0] = p->ch[1] = null;
	p->s = 1; p->v = v; p->flip = false;
	return p;
}

Node* build(int l, int r) {
	if(l > r) return null;
	int mid = (l + r) / 2;
	Node* p = newnode(mid);
	p->ch[0] = build(l, mid - 1);
	p->ch[1] = build(mid + 1, r);
	p->maintain();
	return p;
}

void rotate(Node* &o, int d) {
	Node* k = o->ch[d^1];
	o->ch[d^1] = k->ch[d];
	k->ch[d] = o;
	o->maintain();
	k->maintain();
	o = k;
}

void splay(Node* &o, int k) {
	o->pushdown();
	int d = o->cmp(k);
	if(d == -1) return;
	if(d == 1) k -= o->ch[0]->s + 1;
	Node* p = o->ch[d];
	p->pushdown();
	int d2 = p->cmp(k);
	if(d2 == -1) { rotate(o, d^1); return; }
	int k2 = k;
	if(d2 == 1) k2 -= p->ch[0]->s + 1;
	splay(p->ch[d2], k2);
	if(d == d2) { rotate(o, d^1); rotate(o, d^1); }
	else { rotate(o->ch[d], d2^1); rotate(o, d^1); }
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

void splayInit() {
	tot = 0;
	null = new Node;
	null->ch[0] = null->ch[1] = null;
	null->s = 0;
}

char cmd[10];

vector<int> ans;
void dfs(Node* o) {
	o->pushdown();
	if(o->ch[0] != null) dfs(o->ch[0]);
	ans.push_back(o->v);
	if(o->ch[1] != null) dfs(o->ch[1]);
}

void log(Node* o) {
	if(o->ch[0] != null) {
		log(o->ch[0]);
	}
	printf(" %d", o->v);
	if(o->ch[1] != null) {
		log(o->ch[1]);
	}
}

//#define LOCAL

int main() {
	while(scanf("%d%d", &n, &m) == 2) {
		if(n < 0) break;
		splayInit();
		Node* root = build(0, n);
#ifdef LOCAL
		printf("LOG:\n");
		log(root);
#endif
		while(m--) {
			int a, b, c;
			scanf("%s%d%d", cmd, &a, &b);
			Node *left, *mid, *right, *o;
			split(root, a, left, o);
			split(o, b-a+1, mid, right);
#ifdef LOCAL
			puts("\nleft:"); log(left);
			puts("\nmid:"); log(mid);
			puts("\nright:"); log(right);
#endif
			if(cmd[0] == 'C') {
				scanf("%d", &c);
				o = merge(left, right);
				split(o, c+1, left, right);
			} else {
				mid->flip = !(mid->flip);
			}
			root = merge(merge(left, mid), right);
#ifdef LOCAL
			log(root);
#endif
		}

		ans.resize(0);
		dfs(root);
		printf("%d", ans[1]);
		REP(i, 2, (int)ans.size()) printf(" %d", ans[i]);
		printf("\n");
		delete null;
	}

	return 0;
}

