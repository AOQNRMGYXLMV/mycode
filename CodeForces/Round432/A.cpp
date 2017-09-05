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
	int n, k, t;
	scanf("%d%d%d", &n, &k, &t);
	int r = t, l = t - k + 1;
	if(1 > l) l = 1;
	if(n < r) r = n;
	printf("%d\n", max(0, r - l + 1));

	return 0;
}


