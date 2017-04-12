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

const int maxn = 100000 + 10;

int n, a[maxn], pos[maxn], nxt[maxn], cnt[maxn];
vector<int> l[maxn];
int C[maxn];
void add(int x, int v) {
	while(x <= n + 1) {
		C[x] += v;
		x += x&(-x);
	}
}

int find(int x) {
	int p = 0;
	PER(i, 0, 17) {
		if(p+(1<<i) <= n+1 && C[p+(1<<i)] < x) {
			p += 1<<i;
			x -= C[p];
		}
	}
	return p + 1;
}

int main() {
	scanf("%d", &n);
	REP(i, 1, n + 1) {
		scanf("%d", a + i);
		pos[i] = n + 1;
	}
	PER(i, 1, n + 1) {
		nxt[i] = pos[a[i]];
		pos[a[i]] = i;
	}
	REP(i, 1, n + 1) {
		add(pos[i], 1);
		l[1].PB(i);
	}
	REP(i, 1, n + 1) {
		for(int k : l[i]) {
			int p = find(k + 1);
			cnt[k]++;
			l[p].PB(k);
		}
		add(i, -1);
		add(nxt[i], 1);
	}

	REP(i, 1, n + 1) printf("%d ", cnt[i]);
	printf("\n");

	return 0;
}


