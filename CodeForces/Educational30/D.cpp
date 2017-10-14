#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define REP(i, a, b) for(int i = a; i < b; i++)

const int maxn = 100000 + 10;

int n, k;
int a[maxn];

void solve(int l, int r) {
	if(!k || r - l == 1) return;
	k--;
	int mid = (l + r) / 2;
	swap(a[mid], a[mid - 1]);
	solve(l, mid);
	solve(mid, r);
}

int main() {
	scanf("%d%d", &n, &k);
	k--;
	if(k & 1) { printf("-1\n"); return 0; }
	k >>= 1;
	REP(i, 0, n) a[i] = i + 1;
	solve(0, n);
	if(k) printf("-1\n");
	else REP(i, 0, n) printf("%d ", a[i]);
	printf("\n");

	return 0;
}