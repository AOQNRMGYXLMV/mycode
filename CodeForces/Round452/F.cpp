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
#define MP make_pair

const int maxn = 200000 + 10;

set<int> S[62];

inline int code(char c) {
	if('a' <= c && c <= 'z') return c-'a';
	if('A' <= c && c <= 'Z') return c-'A'+26;
	return c-'0'+52;
}

int n, m;
char s[maxn], t[maxn];
int sum[maxn << 2];

void build(int o, int L, int R) {
	if(L == R) { sum[o] = 1; return; }
	int M = (L + R) / 2;
	build(o<<1, L, M);
	build(o<<1|1, M+1, R);
	sum[o] = sum[o<<1] + sum[o<<1|1];
}

void update(int o, int L, int R, int p) {
	if(L == R) { sum[o] = 0; return; }
	int M = (L + R) / 2;
	if(p <= M) update(o<<1, L, M, p);
	else update(o<<1|1, M+1, R, p);
	sum[o] = sum[o<<1] + sum[o<<1|1];
}

int query(int o, int L, int R, int q) {
	if(L == R) return L;
	int M = (L + R) / 2;
	if(sum[o<<1] >= q) return query(o<<1, L, M, q);
	else return query(o<<1|1, M+1, R, q-sum[o<<1]);
}

set<PII> Q;

int main() {
	scanf("%d%d", &n, &m);
	build(1, 1, n);
	scanf("%s", s + 1);
	REP(i, 1, n + 1) S[code(s[i])].insert(i);

	while(m--) {
		int l, r; char ch;
		scanf("%d %d %c", &l, &r, &ch);
		int c = code(ch);
		l = query(1, 1, n, l);
		r = query(1, 1, n, r);
		auto itr = S[c].upper_bound(r);
		auto itl = S[c].lower_bound(l);
		for(auto it = itl; it != itr; it++) {
			update(1, 1, n, *it);
		}
		S[c].erase(itl, itr);
	}

	REP(i, 0, 62) if(!S[i].empty()) {
		Q.emplace(*S[i].begin(), i);
		S[i].erase(S[i].begin());
	}

	int p = 0;
	while(!Q.empty()) {
		PII x = *Q.begin(); Q.erase(Q.begin());
		t[p++] = s[x.first];
		int c = x.second;
		if(!S[c].empty()) {
			Q.emplace(*S[c].begin(), c);
			S[c].erase(S[c].begin());
		}
	}

	t[p] = 0;
	printf("%s\n", t);

	return 0;
}

