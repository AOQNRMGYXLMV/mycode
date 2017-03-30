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

int main() {
	int n, k; scanf("%d%d", &n, &k);
	LL ans = 0;
	while(n--) {
		int w; scanf("%d", &w);
		ans += (w + k - 1) / k;
	}

	printf("%lld\n", (ans + 1) >> 1);

	return 0;
}


