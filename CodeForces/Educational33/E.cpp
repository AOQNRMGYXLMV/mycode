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

const int maxn = 1000000;

int count(int x) {
	int i, ans = 0;
	for(i = 1; i * i < x; i++) if(x % i == 0) ans += 2;
	if(i * i == x) ans++;
	return ans;
}

int main() {
	int maxv = 2;
	REP(i, 2, maxn + 1) maxv = max(maxv, count(i));
	printf("%d\n", maxv);

	return 0;
}

