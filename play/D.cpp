#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n, k;

struct Node
{
	Node* ch[2];
	int r, v, s;
	
	Node(int v): v(v) { ch[0] = ch[1] = NULL; r = rand(); s = 1; }
	
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
		if(o->ch[d]->r > o->r) rotate(o, d^1);
	}
	o->maintain();
}

int kth(Node* o, int k) {
	int s = o->ch[1] == NULL ? 0 : o->ch[1]->s;
	if(k == s + 1) return o->v;
	if(k <= s) return kth(o->ch[1], k);
	else return kth(o->ch[0], k - s - 1);
}

void remove(Node* &o) {
	if(o->ch[0] != NULL) remove(o->ch[0]);
	if(o->ch[1] != NULL) remove(o->ch[1]);
	delete o;
	o = NULL;
}

char op[5];

int main()
{
	while(scanf("%d%d", &n, &k) == 2) {
		Node* root = NULL;
		while(n--) {
			scanf("%s", op);
			if(op[0] == 'I') {
				int x; scanf("%d", &x);
				insert(root, x);
			} else printf("%d\n", kth(root, k));
		}
		remove(root);
	}

	return 0;
}
