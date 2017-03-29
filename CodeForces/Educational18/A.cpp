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

const int maxn = 200000 + 10;

int n, a[maxn];

int main() {
	scanf("%d", &n);
	REP(i, 0, n) scanf("%d", a + i);
	sort(a, a + n);

	int mind = a[1] - a[0], cnt = 1;
	REP(i, 2, n) {
		if(a[i] - a[i - 1] < mind) {
			mind = a[i] - a[i - 1];
			cnt = 1;
		} else if(a[i] - a[i - 1] == mind) cnt++;
	}

	printf("%d %d\n", mind, cnt);

	return 0;
}


