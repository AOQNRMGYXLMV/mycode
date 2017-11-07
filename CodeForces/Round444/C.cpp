#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
#define REP(i, a, b) for(int i = a; i < b; i++)
#define PER(i, a, b) for(int i = b - 1; i >= a; i--)
#define ALL(x) x.begin(), x.end()

int a[24], b[24];

bool check(int* a) {
	for(int i = 0; i < 24; i += 4) {
		REP(j, 1, 4) {
			if(a[i+j] != a[i]) return false;
		}
	}
	return true;
}

int op[3][12] = {
	{ 5, 6, 8, 7, 4, 19, 9, 14, 3, 17, 10, 16 },
	{ 17, 18, 20, 19, 8, 4, 21, 12, 6, 2, 23, 10 },
	{ 9, 10, 12, 11, 7, 19, 23, 15, 8, 20, 24, 16 }
};

void operate(int* a, int t) {
	for(int i = 0; i < 12; i += 4) {
		int tmp = a[op[t][i]];
		REP(j, 0, 3) {
			a[op[t][i+j]] = a[op[t][i+j+1]];
		}
		a[op[t][i+3]] = tmp;
	}
}

int main() {
	REP(i, 0, 24) scanf("%d", a + i);
	REP(i, 0, 3) REP(j, 0, 12) op[i][j]--;
	REP(t, 0, 3) {
		memcpy(b, a, sizeof(a));
		operate(b, t);
		if(check(b)) { printf("YES\n"); return 0; }
		operate(b, t);
		operate(b, t);
		if(check(b)) { printf("YES\n"); return 0; }
	}

	printf("NO\n");

	return 0;
}

