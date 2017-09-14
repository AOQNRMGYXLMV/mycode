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

int n, a[maxn], b[maxn], r[maxn], p[maxn];

bool cmp(int i, int j) { return b[i] < b[j]; } 

int main() {
	scanf("%d", &n);
	REP(i, 0, n) scanf("%d", a + i);
	REP(i, 0, n) scanf("%d", b + i);
	REP(i, 0, n) r[i] = i;
	sort(a, a + n);
	sort(r, r + n, cmp);
	REP(i, 0, n) p[r[i]] = i;
	REP(i, 0, n) printf("%d ", a[n - 1 - p[i]]);
	printf("\n");
	
	return 0;
}


