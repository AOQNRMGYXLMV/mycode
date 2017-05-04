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

const int maxn = 300000 + 10;

int n, m;
struct Node {
	int val, s, ch[2];
	bool flip;
	void maintain();
	void pushdown();
	int cmp(int) const;
};

Node T[maxn];

void Node::maintain() {
	s = T[ch[0]].s + T[ch[1]].s + 1;
}

void Node::pushdown() {
	if(flip) {
		flip = false;
		swap(ch[0], ch[1]);
		T[ch[0]].flip = !T[ch[0]].flip;
		T[ch[1]].flip = !T[ch[1]].flip;
	}
}

int Node::cmp(int k) const {
	k -= T[ch[0]].s;
	if(1 == k) return -1;
	return k <= 0 ? 0 : 1;
}

void rotate(int& rt, int d) {
	int k = T[rt].ch[d^1];
	T[rt].ch[d^1] = T[k].ch[0];
	T[k].ch[d] = rt;
	T[rt].maintain();
	T[k].maintain();
	rt = k;
}

void splay(int& rt, int k) {
	T[rt].pushdown();
	int d = T[rt].cmp(k);
	if(d == 1) k -= T[T[rt].ch[0]].s + 1;
	if(d != -1) {
		int p = T[rt].ch[d];
		T[p].pushdown();
		int d2 = T[p].cmp(k);
		if(d2 != -1) {
			int k2 = (!d2 ? k : k - T[T[p].ch[0]].s - 1);
			splay(T[p].ch[d2], k2);
			if(d == d2) rotate(rt, d^1);
			else rotate(T[rt].ch[d], d);
		}
		rotate(rt, d^1);
	}
}

void split(int o, int k, int& left, int& right) {
	splay(o, k);
	left = o;
	right = T[o].ch[1];
	T[o].ch[0] = 0;
	T[o].maintain();
}

int merge(int left, int right) {
	splay(left, T[left].s);
	T[left].ch[1] = right;
	T[left].maintain();
	return left;
}

int tot, root;
int build(int sz = n) {
	if(!sz) return 0;
	int rt = ++tot;
	T[rt].ch[0] = build(sz >> 1);
	T[rt].val = tot - 1;
	T[rt].ch[1] = build(sz - sz/2 - 1);
	T[rt].flip = false;
	T[rt].maintain();

	return rt;
}

void init(int sz = n) {
	tot = 0;
	root = build(sz);
}

int main() {
	while(scanf("%d%d", &n, &m) == 2) {
		
	}

	return 0;
}


