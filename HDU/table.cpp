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

const int maxn = 20;

int n;
int bitcount(int x) {
	int ans = 0;
	for(; x; x >>= 1) if(x & 1) ans++;
	return ans;
}
int f(int x) { return (bitcount(x)&1)^1; }

int ans[maxn][maxn];

int main() {
	scanf("%d", &n);
	n = 1 << n;
	REP(i, 0, n) {
		REP(j, 0, n) printf("%d ", f((i|j)^i));
		printf("\n");
	}

	return 0;
}


