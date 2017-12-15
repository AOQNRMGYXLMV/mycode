#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
#define PB push_back
#define PII pair<int, int>
#define REP(i, a, b) for(int i = a; i < b; i++)
#define PER(i, a, b) for(int i = b - 1; i >= a; i--)
#define ALL(x) x.begin(), x.end()

int main() {
	int a, b, c; scanf("%d%d%d", &a, &b, &c);
	a %= b;
	if(!a) {
		if(c == 0) printf("1\n");
		else printf("-1\n");
		return 0;
	}

	REP(i, 1, 20000) {
		a *= 10;
		if(c == a / b) {
			printf("%d\n", i);
			return 0;
		}
		a %= b;
	}

	printf("-1\n");

	return 0;
}

