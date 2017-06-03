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

const int maxn = 1000 + 10;

int n, a[maxn], b[maxn];

int main() {
	scanf("%d", &n);
	REP(i, 0, n) {
		scanf("%d%d", a + i, b + i);
		if(a[i] != b[i]) { printf("rated\n"); return 0; }
	}

	REP(i, 1, n) if(a[i] > a[i - 1]) { printf("unrated\n"); return 0; }
	printf("maybe\n");

	return 0;
}


