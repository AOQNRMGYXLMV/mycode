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

int n, m, a[maxn], b[maxn];

int main() {
	scanf("%d%d", &n, &m);
	REP(i, 0, n) scanf("%d", a + i);
	REP(i, 0, m) scanf("%d", b + i);

	int ans = 0, diff = 0;
	for(int i = 0, j = 0; i < n && j < m;) {
		if(diff > 0) {
			diff -= b[j++];
		} else if(diff < 0) {
			diff += a[i++];
		} else {
			if(i == n && j == m) break;
			ans++;
			if(i < n) diff += a[i++];
			else diff -= b[j++];
		}
	}

	printf("%d\n", ans);

	return 0;
}



