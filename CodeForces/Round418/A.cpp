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

const int maxn = 100 + 10;

int n, k;
int a[maxn], b;

int main() {
	scanf("%d%d", &n, &k);
	if(k > 1) { printf("Yes\n"); return 0; }
	int p;
	REP(i, 0, n) {
		scanf("%d", a + i);
		if(0 == a[i]) p = i;
	}
	scanf("%d", a + p);
	REP(i, 0, n - 1) if(a[i] > a[i + 1]) {
		printf("Yes\n");
		return 0;
	}
	printf("No\n");

	return 0;
}


