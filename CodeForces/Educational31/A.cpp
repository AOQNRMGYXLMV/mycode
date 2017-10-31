#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define REP(i, a, b) for(int i = a; i < b; i++)

int main() {
	int n, t; scanf("%d%d", &n, &t);
	REP(i, 1, n + 1) {
		int a; scanf("%d", &a);
		t -= 86400 - a;
		if(t <= 0) { printf("%d\n", i); return 0; }
	}

	return 0;
}
