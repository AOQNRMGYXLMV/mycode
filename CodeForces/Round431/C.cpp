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

const int maxn = 30;

int ans[maxn];

int main() {
	int k; scanf("%d", &k);
	if(!k) { printf("a\n"); return 0; }
	int p = 0;
	while(k) {
		int i;
		for(i = 1; i * (i - 1) / 2 <= k; i++);
		i--;
		ans[p++] = i;
		k -= i * (i - 1) / 2;
	}

	REP(i, 0, p) REP(j, 0, ans[i]) printf("%c", 'a' + i);
	printf("\n");

	return 0;
}


