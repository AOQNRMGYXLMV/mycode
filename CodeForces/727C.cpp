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

const int maxn = 5000 + 10;

int a[maxn];

int main() {
	int n; scanf("%d", &n);

	int A, B, C;
	printf("? 1 2\n");
	fflush(stdout);
	scanf("%d", &A);
	printf("? 2 3\n");
	fflush(stdout);
	scanf("%d", &B);
	printf("? 1 3\n");
	fflush(stdout);
	scanf("%d", &C);

	int sum = (A + B + C) / 2;
	a[1] = sum - B;
	a[2] = sum - C;
	a[3] = sum - A;

	REP(i, 4, n + 1) {
		printf("? %d %d\n", i-1, i);
		fflush(stdout);
		int sum; scanf("%d", &sum);
		a[i] = sum - a[i - 1];
	}

	printf("!");
	REP(i, 1, n + 1) printf(" %d", a[i]);
	printf("\n");

	return 0;
}

