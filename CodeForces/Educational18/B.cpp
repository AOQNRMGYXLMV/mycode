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

int n, k, leader;
vector<int> a, op;

void excute(int x) {
	int sz = SZ(a);
	leader = (leader + x) % sz;
	printf("%d ", a[leader]);
	a.erase(a.begin() + leader);
	if(leader == sz - 1) leader = 0;
}

int main() {
	scanf("%d%d", &n, &k);
	REP(i, 1, n + 1) a.PB(i);
	while(k--) { int x; scanf("%d", &x); op.PB(x); }
	for(int x : op) {
		excute(x);
	}
	printf("\n");

	return 0;
}


