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

int gcd(int a, int b) { return !b ? a : gcd(b, a%b); }

const int maxn = 100000 + 10;

int a[maxn];

int main() {
	printf("YES\n");
	int n; scanf("%d", &n);
	REP(i, 0, n) scanf("%d", a + i);
	int g = a[0];
	for(int i = 1; i < n && g > 1; i++)
		g = gcd(g, a[i]);
	if(g > 1) { printf("0\n"); return 0; }

	int ans = 0;
	for(int i = 0, j; i < n; i++) if(a[i] & 1) {
		for(j = i; a[j] & 1; j++);
		ans += (j - i) / 2;
		if((j - i) & 1) ans += 2;
		i = j;
	}

	printf("%d\n", ans);

	return 0;
}


