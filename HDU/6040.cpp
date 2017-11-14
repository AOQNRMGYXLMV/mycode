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

unsigned x, y, z;
unsigned rng61() {
  unsigned t;
  x ^= x << 16;
  x ^= x >> 5;
  x ^= x << 1;
  t = x;
  x = y;
  y = z;
  z = t ^ x ^ y;
  return z;
}

const int maxn = 10000000 + 10;
const int maxm = 100 + 5;
const int block = 1 << 16;

int n, m;
int b[maxm], pos[maxm];
int cnt[block], tot[block];
unsigned a[maxn], s[maxn];
bool vis[block];

int getpos(int x) {
	int L = 0, R = block - 1;
	while(L < R) {
		int M = (L + R) / 2;
		if(tot[M] < x) L = M + 1;
		else R = M;
	}
	return L;
}

int main() {
	int _ = 1;
	while(scanf("%d%d%u%u%u", &n, &m, &x, &y, &z) == 5) {
		printf("Case #%d:", _++);
		memset(cnt, 0, sizeof(cnt));
		REP(i, 0, n) {
			a[i] = rng61();
			cnt[a[i] >> 16]++;
		}
		tot[0] = cnt[0];
		REP(i, 1, block) {
			cnt[i] += cnt[i - 1];
			tot[i] = cnt[i];
		}

		memset(vis, false, sizeof(vis));
		REP(i, 0, m) {
			scanf("%d", b + i);
			pos[i] = getpos(b[i] + 1);
			vis[pos[i]] = true;
		}
		REP(i, 0, n) if(vis[a[i]>>16]) s[--cnt[a[i]>>16]] = a[i];
		REP(i, 0, m) {
			int& p = pos[i];
			int L = p ? tot[p - 1] : 0;
			int R = tot[p];
			nth_element(s + L, s + b[i], s + R);
			printf(" %u", s[b[i]]);
		}
		printf("\n");
	}
	
	return 0;
}


