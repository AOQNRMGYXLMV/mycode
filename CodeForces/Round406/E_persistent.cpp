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
const int maxnode = maxn << 5;

int n, a[maxn], last[maxn];
int tot, root[maxn];
int lch[maxnode], rch[maxnode], sum[maxnode];

int pos, val = -1;

int add(int pre, int L = 1, int R = n) {
	int rt = ++tot;
	sum[rt] = sum[pre] - 1;
	if(L == R) return rt;
	int M = (L + R) / 2;
	if(pos <= M) { rch[rt] = rch[pre]; lch[rt] = add(lch[pre], L, M); }
	else { lch[rt] = lch[pre]; rch[rt] = add(rch[pre], M+1, R); }
	return rt;
}

int main() {
	scanf("%d", &n);
	REP(i, 1, n + 1) scanf("%d", a + i);

	PER(i, 1, n + 1) {
		if(last[a[i]]) {
			pos = last[a[i]];
			root[i] = add(root[i + 1]);
		} else root[i] = root[i + 1];
		last[a[i]] = i;
	}

	REP(k, 1, n + 1) {
		int ans = 0;
		for(int s = 1, t; s <= n; s = t, ans++) {
			if(sum[root[s]] + n - s + 1 <= k) {
				t = n + 1;
				continue;
			}
			int q = k + 1, L = 1, R = n, rt = root[s];
			while(L < R) {
				int M = (L + R) / 2;
				int lft = sum[lch[rt]];
				lft += max(0, M - max(L, s) + 1);
				if(lft >= q) {
					R = M;
					rt = lch[rt];
				} else {
					q -= lft;
					L = M + 1;
					rt = rch[rt];
				}
			}
			t = L;
		}
		printf("%d ", ans);
	}
	printf("\n");

	return 0;
}


