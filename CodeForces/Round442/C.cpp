#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
#define MP make_pair
#define PB push_back
#define REP(i, a, b) for(int i = a; i < b; i++)
#define PER(i, a, b) for(int i = b - 1; i >= a; i--)

int main() {
	int n; scanf("%d", &n);
	if(n == 2) { printf("3\n2 1 2\n"); return 0; }
	printf("%d\n", n + (n >> 1));
	if(n & 1) {
		for(int i = 2; i < n; i += 2) printf("%d ", i);
		for(int i = 1; i <= n; i += 2) printf("%d ", i);
		for(int i = 2; i < n; i += 2) printf("%d ", i);
	} else {
		for(int i = 2; i <= n; i += 2) printf("%d ", i);
		for(int i = 1; i < n; i += 2) printf("%d ", i);
		for(int i = 2; i <= n; i += 2) printf("%d ", i);
	}
	printf("\n");

	return 0;
}