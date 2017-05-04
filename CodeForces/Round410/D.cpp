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

int n, a[maxn], b[maxn], c[maxn];

bool cmp(int i, int j) { return a[i] > a[j]; }

int main() {
	scanf("%d", &n);
	REP(i, 0, n) scanf("%d", a + i);
	REP(i, 0, n) scanf("%d", b + i);
	REP(i, 0, n) c[i] = i;
	sort(c, c + n, cmp);
	
	printf("%d\n", n / 2 + 1);
	printf("%d", c[0] + 1);
	for(int i = 1; i + 1 < n; i += 2) {
		if(b[c[i]] > b[c[i + 1]]) printf(" %d", c[i] + 1);
		else printf(" %d", c[i+1] + 1);
	}

	if(!(n & 1)) printf(" %d", c[n - 1] + 1);
	printf("\n");
	return 0;
}


