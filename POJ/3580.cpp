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

struct Node {
	Node* ch[2];
	int s, v, minv;
	bool flip; int add;
	void maintain() {
		minv = min(v, min(ch[0]->minv, ch[1]->minv));
		s = ch[0]->s + ch[1]->s + 1;
	}
	void pushdown() {
		if(flip) {
			flip = false;
			swap(ch[0], ch[1]);
			ch[0]->flip ^= 1;
			ch[1]->flip ^= 1;
		}
		if(add) {
			v += add;
			min += add;
			ch[0]->add += add;
			ch[1]->add += add;
			add = 0;
		}
	}
};

int tot = 0;
Node pool[maxn << 1], *null;

Node* newnode(int v) {
	Node* p = pool + tot; tot++;
	p->s = 1; p->v = p->min = v;
	p->add = 0; p->flip = false;
	return p;
}

void splyInit() {
	tot = 0;
	null = new Node;
	null->ch[0] = null->ch[1] = null;
	null->s = 0; null->v = null->min = INF;
}

void build(int l, int r) {
	
}

int main() {


	return 0;
}

