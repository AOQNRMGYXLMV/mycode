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

set<int> S[maxn];
int n, m;
//const int B = 316; //Block size
const int B = 2; //Block size
int a[maxn], pre[maxn], nxt[maxn];
int dp[B+5][B+5];

int op, l, r;

LL query(int l, int r) {
	int x = l / B, y = r / B;
	LL ans = 0;
	if(x == y) {
		REP(i, l, r + 1) if(pre[i] >= l) ans += i - pre[i];
		return ans;
	}
	REP(i, x+1, y) ans += dp[x+1][i];
	int L = (x + 1) * B, R = y * B;
	REP(i, l, L) if(nxt[i] < R) ans += nxt[i] - i;
	REP(i, R, r+1) if(pre[i] >= l) ans += i - pre[i];
	return ans;
}

int main() {
	scanf("%d%d", &n, &m);
	REP(i, 0, n) {
		scanf("%d", a + i);
		S[a[i]].insert(i);
	}

	REP(i, 0, n) {
		auto it = S[a[i]].lower_bound(i);
		auto p = it;
		if(*it == *S[a[i]].begin()) pre[i] = i;
		else pre[i] = *--p;
		p = it;
		if(*it == *S[a[i]].rbegin()) nxt[i] = i;
		else nxt[i] = *++p;
	}

	REP(i, 0, n) {
		int x = pre[i] / B;
		int y = i / B;
		int d = i - pre[i];
		REP(j, 0, x + 1) dp[j][y] += d;
	}

	while(m--) {
		scanf("%d%d%d", &op, &l, &r);
		l--;
		if(op == 1) {
			if(r == a[l]) continue;
			int x = pre[l] / B, y = l / B;
			int d = l - pre[l];
			REP(i, 0, x + 1) dp[i][y] -= d;
			auto it = S[a[l]].lower_bound(l);
			auto p = it;
			bool eq1 = (*it == *S[a[l]].begin());
			bool eq2 = (*it == *S[a[l]].rbegin());
			if(!eq1) {
				p--;
				if(eq2) nxt[*p] = *p;
				else nxt[*p] = *++it;
			}
			if(!eq2) {
				it = S[a[l]].lower_bound(l);
				p = it;
				p++;
				if(eq1) pre[*p] = *p;
				else pre[*p] = *--it;
			}
			S[a[l]].erase(l);
			S[r].insert(l);
			a[l] = r;
			it = S[r].lower_bound(l);
			p = it;
			eq1 = (*it == *S[r].begin());
			eq2 = (*it == *S[r].rbegin());
			if(eq1) pre[l] = l;
			else pre[l] = *--p;
			p = it;
			if(eq2) nxt[l] = l;
			else nxt[l] = *++p;
			p = it;
			if(!eq1) {
				p--;
				nxt[*p] = l;
			}
			p = it;
			if(!eq2) {
				p++;
				pre[*p] = l;
			}

			x = pre[l] / B;
			d = l - pre[l];
			REP(i, 0, x + 1) dp[i][y] += d;
		} else {
			r--;
			printf("%lld\n", query(l, r));
		}
	}

	return 0;
}

