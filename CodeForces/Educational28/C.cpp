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

const int maxn = 5000 + 5;

int n, a[maxn];
LL suf[maxn];
int pos[maxn];

LL sum(int l, int r) {
	return suf[l] - suf[r];
}

int main() {
	scanf("%d", &n);
	REP(i, 0, n) scanf("%d", a + i);
	suf[n] = 0;
	PER(i, 0, n) suf[i] = suf[i + 1] + a[i];
	REP(i, 0, n + 1) {
		LL t = 0;
		int p = i;
		REP(j, i + 1, n + 1) if(sum(i, j) > t) {
			t = sum(i, j);
			p = j;
		}
		pos[i] = p;
	}
	
	LL ans = -0x3f3f3f3f3f3f3f3f;
	int x, y, z;
	REP(i, 0, n + 1) REP(j, i, n + 1) {
		LL tmp = sum(0, i) - sum(i, j);
		int k = pos[j];
		tmp += suf[j] - suf[k] * 2;
		if(tmp > ans) {
			ans = tmp;
			x = i; y = j; z = k;
		}
	}

	printf("%d %d %d\n", x, y, z);

	return 0;
}


