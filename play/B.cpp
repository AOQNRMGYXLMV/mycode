#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct Node
{
	Node* ch[2];
	int r, v, s;

	Node(int v): v(v) { ch[0] = ch[1] = NULL; s = 1; r = rand(); }
	
	int cmp(int x) {
		if(x == v) return -1;
		return x < v ? 0 : 1;
	}

	void maintain() {
		s = 1;
		if(ch[0] != NULL) s += ch[0]->s;
		if(ch[1] != NULL) s += ch[1]->s;
	}
};

void rotate(Node* &o, int d) {
	Node* k = o->ch[d^1]; o->ch[d^1] = k->ch[d]; k->ch[d] = o;
	o->maintain(); k->maintain(); o = k;
}

void insert(Node* &o, int x) {
	if(o == NULL) o = new Node(x);
	else {
		int d = x < o->v ? 0 : 1;
		insert(o->ch[d], x);
		if(o->ch[d]->r > o->r) rotate(o, d ^ 1);
	}
	o->maintain();
}

int query(Node* o, int x) {
	int s = o->ch[0] == NULL ? 0 : o->ch[0]->s;
	if(x == s + 1) return o->v;
	if(x <= s) return query(o->ch[0], x);
	else return query(o->ch[1], x - s - 1);
}

void remove(Node* &o) {
	if(o->ch[0] != NULL) remove(o->ch[0]);
	if(o->ch[1] != NULL) remove(o->ch[1]);
	delete o;
	o = NULL;
}

const int maxn = 30000 + 10;

int n, m, a[maxn], b[maxn];

int main()
{
	freopen("in.txt", "r", stdin);
	while(scanf("%d%d", &n, &m) == 2) {
		for(int i = 1; i <= n; i++) scanf("%d", a + i);
		for(int i = 1; i <= m; i++) scanf("%d", b + i);
		int id = 0, p = 0;
		Node* root = NULL;
		for(int i = 1; i <= m; i++) {
			while(p < b[i]) insert(root, a[++p]);
			printf("%d\n", query(root, ++id));
		}
		remove(root);
	}

	return 0;
}
