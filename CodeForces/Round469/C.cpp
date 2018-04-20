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

vector<int> ans[maxn];
char a[maxn];
int n;

int main() {
	scanf("%s", a);
	int cnt = 0, p = 0;
	for(int i = 0; a[i]; i++) {
		if(a[i] == '0') {
			if(p) {
				ans[p--].PB(i);
			} else {
				ans[++cnt].PB(i);
			}
		} else {
			if(p < cnt) {
				ans[++p].PB(i);
			} else {
				printf("-1\n");
				return 0;
			}
		}
	}

	if(p) { printf("-1\n"); return 0; }

	printf("%d\n", cnt);
	REP(i, 1, cnt + 1) {
		printf("%d", (int)ans[i].size());
		for(int id : ans[i]) printf(" %d", id + 1);
		printf("\n");
	}
	
	return 0;
}



