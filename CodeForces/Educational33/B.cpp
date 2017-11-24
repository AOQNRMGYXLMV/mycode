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

int a[100], p;

int main() {
	for(p = 0; ; p++) {
		a[p] = ((1<<(p+1))-1)<<p;
		if(a[p] > maxn) break;
	}
	
	int n; scanf("%d", &n);
	PER(i, 0, p + 1) if(n % a[i] == 0) {
		printf("%d\n", a[i]);
		return 0;
	}

	return 0;
}

