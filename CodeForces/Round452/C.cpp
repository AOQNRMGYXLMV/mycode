#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <cmath>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
#define PB push_back
#define PII pair<int, int>
#define REP(i, a, b) for(int i = a; i < b; i++)
#define PER(i, a, b) for(int i = b - 1; i >= a; i--)
#define ALL(x) x.begin(), x.end()

vector<int> a;

int main() {
	int n; scanf("%d", &n);
	LL sum = (LL)n * (n + 1) / 2;
	LL s = 0;
	if(n & 1) {
		s += 3;
		a.PB(3);
		int add = 0;
		for(int i = 4; i <= n; i += 2) {
			s += i + add;
			a.PB(i + add);
			add ^= 1;
		}
	} else {
		int add = 0;
		for(int i = 1; i <= n; i += 2) {
			s += i + add;
			a.PB(i + add);
			add ^= 1;
		}
	}

	printf("%lld\n", abs(sum - (s << 1)));
	printf("%d", (int)a.size());
	for(int x : a) printf(" %d", x);
	printf("\n");

	return 0;
}

