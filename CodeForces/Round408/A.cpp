#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <set>
#include <cmath>
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

const int maxn = 100 + 10;

int a[maxn];

void upd(int& a, int b) { if(a > b) a = b; }

int main() {
	int index, dist = 1000;
	int n, m, k; scanf("%d%d%d", &n, &m, &k);
	REP(i, 1, n + 1) {
		int a; scanf("%d", &a);
		if(a && a <= k) upd(dist, abs(m - i));
	}

	printf("%d\n", dist * 10);

	return 0;
}


