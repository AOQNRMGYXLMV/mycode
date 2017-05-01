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

const int maxn = 100 + 5;

int a[maxn][maxn];

int main() {
	int n, k; scanf("%d%d", &n, &k);
	if(k > n * n) { printf("-1\n"); return 0; }
	for(int i = 1; i <= n && k > 0; i++) {
		a[i][i] = 1; k--;
		for(int j = i + 1; j <= n && k > 1; j++) {
			a[i][j] = a[j][i] = 1;
			k -= 2;
		}
	}

	REP(i, 1, n + 1) {
		REP(j, 1, n + 1) printf("%d ", a[i][j]);
		printf("\n");
	}

	return 0;
}


