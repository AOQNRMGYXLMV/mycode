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

const int maxn = 30;

int a[maxn];
int days[100] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

int main() {
	int p = 12;
	REP(i, 0, 6) REP(j, 0, 12) {
		days[p++] = days[j];
	}
	days[25]++;

	int n; scanf("%d", &n);
	REP(i, 0, n) scanf("%d", a + i);

	REP(i, 0, p-n) {
		bool ok = true;
		REP(j, 0, n) if(a[j] != days[i+j]) {
			ok = false;
			break;
		}
		if(ok) { printf("YES\n"); return 0; }
	}

	printf("NO\n");

	return 0;
}

