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

const int maxn = 200000 + 10;
const int nlogn = maxn * 40;

//persistant segment tree
int lch[nlogn], rch[nlogn], sum[nlogn];
int tot, root[maxn], p[maxn];

void update(int& rt, int pre, int L, int R, int p, int v = 1) {
	rt = ++tot;
	if(L == R) { sum[rt] = sum[pre] + v; return; }
	int M = (L + R) / 2;
	if(p <= M) { rch[rt] = rch[pre]; update(lch[rt], lch[pre], L, M, p, v); }
	else { lch[rt] = lch[pre]; update(rch[rt], rch[pre], M+1, R, p, v); }
	sum[rt] = sum[lch[rt]] + sum[rch[rt]];
}

int qL, qR;
int query(int rt, int pre, int L, int R) {
	int ans = 0;
	if(qL <= L && R <= qR) return sum[rt] - sum[pre];
	int M = (L + R) / 2;
	if(qL <= M) ans += query(lch[rt], lch[pre], L, M);
	if(qR > M) ans += query(rch[rt], rch[pre], M+1, R);
	return ans;
}

//fail tree
vector<int> G[maxn];
int l[maxn], r[maxn], dfs_clock;

void dfs(int u) {
	l[u] = ++dfs_clock;
	for(int v : G[u]) dfs(v);
	r[u] = dfs_clock;
}

//Trie
int sz;
int ch[maxn][26], f[maxn], pos[maxn], fa[maxn];

void insert(int id, char* s) {
	int u = 0;
	for(int i = 0; s[i]; i++) {
		int c = s[i] - 'a';
		if(!ch[u][c]) {
			ch[u][c] = ++sz;
			memset(ch[sz], 0, sizeof(ch[0]));
		}
		fa[ch[u][c]] = u;
		u = ch[u][c];
	}
	pos[id] = u;
}

void getFail() {
	queue<int> Q;
	REP(c, 0, 26) if(ch[0][c]) {
		Q.push(ch[0][c]);
		G[0].PB(ch[0][c]);
	}
	while(!Q.empty()) {
		int r = Q.front(); Q.pop();
		REP(c, 0, 26) {
			int u = ch[r][c];
			if(!u) ch[r][c] = ch[f[r]][c];
			else {
				f[u] = ch[f[r]][c];
				G[f[u]].PB(u);
				Q.push(u);
			}
		}
	}
}

int n, q;
char s[maxn];

int main() {
	scanf("%d%d", &n, &q);
	REP(i, 0, n) {
		scanf("%s", s);
		insert(i + 1, s);
	}
	getFail();
	dfs(0);
	int cur = 0, s;
	REP(i, 1, n + 1) {
		for(int j = pos[i]; j; j = fa[j]) {
			cur++;
			update(root[cur], root[cur-1], 1, dfs_clock, l[j]);
		}
		p[i] = root[cur];
	}

	while(q--) {
		int x, y, k; scanf("%d%d%d", &x, &y, &k);
		qL = l[pos[k]], qR = r[pos[k]];
		printf("%d\n", query(p[y], p[x-1], 1, dfs_clock));
	}

	return 0;
}

