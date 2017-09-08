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
	n -= k;
	if(!k || !n) { printf("0 0\n"); return 0; }
	printf("%d %d\n", 1, min(n, k * 2));

	return 0;
}


