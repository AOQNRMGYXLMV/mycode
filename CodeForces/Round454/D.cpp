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

const int maxn = 100000 + 10;

int n, m;
bool ex;
int m33[] = { 5, 7, 2, 9, 1, 6, 3, 8, 4 };
int m24[] = { 5, 4, 7, 2, 3, 6, 1, 8 };
int m42[] = { 5, 2, 4, 7, 1, 6, 8, 3 };
int m43[] = { 7, 2, 6, 5, 10, 12, 1, 8, 3, 11, 4, 9 };
int m14[] = { 1, 3, 0, 2 };

int ans[maxn][4];

void print(int* a) {
	printf("YES\n");
	REP(i, 0, n) {
		REP(j, 0, m) printf("%d ", a[i*m+j]);
		printf("\n");
	}
}

int main() {
	scanf("%d%d", &n, &m);
	if(n == 1 && m == 1) { printf("YES\n1\n"); return 0; }
	if(min(m, n) == 1 && max(m, n) == 4) {
		printf("YES\n");
		REP(i, 0, n) {
			REP(j, 0, m) printf("%d ", m14[i*m+j] + 1);
			printf("\n");
		}
		return 0;
	}
	if(n == 3 && m == 3) { print(m33); return 0; }
	if(n == 4 && m == 2) { print(m42); return 0; }
	if(n == 2 && m == 4) { print(m24); return 0; }
	if(n == 3 && m == 4) {
		n = 2;
		print(m24);
		printf("10 12 9 11\n");
		return 0;
	}
	if(n == 4 && m == 3) {
		print(m43);
		return 0;
	}
	if(n == 4 && m == 4) {
		REP(i, 0, 4) {
			REP(j, 0, 4) printf("%d ", m14[i]*4+m14[j]+1);
			putchar('\n');
		}
		return 0;
	}
	ex = false;
	if(n > m) { swap(n, m); ex = true; }
	if(m <= 2 || (n <= 2 && m == 3)) { puts("NO"); return 0; }

	if(ex) swap(n, m);

	printf("YES\n");
	if(m <= 4) {
		int f = 0;
		REP(c, 0, m) {
			int p = 0;
			for(int i = c+m*f; i < m*n; i += m * 2)
				ans[p++][c] = i+1;
			for(int i = c+m*(f^1); i < m*n; i += m * 2)
				ans[p++][c] = i+1;
			f ^= 1;
		}
		REP(i, 0, n) {
			REP(j, 0, m) printf("%d ", ans[i][j]);
			printf("\n");
		}
		return 0;
	}

	int f = 0, base = 0;
	REP(r, 0, n) {
		for(int i = 1+f; i <= m; i += 2)
			printf("%d ", i+base);
		for(int i = 1+(f^1); i <= m; i += 2)
			printf("%d ", i+base);
		printf("\n");
		f ^= 1;
		base += m;
	}

	return 0;
}

