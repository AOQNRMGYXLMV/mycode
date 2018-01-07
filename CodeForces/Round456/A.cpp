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
	LL A, B, x, y, z;
	scanf("%lld%lld%lld%lld%lld", &A, &B, &x, &y, &z);
	LL nA = x * 2 + y;
	LL nB = y + z * 3;

	LL ans = 0;
	if(nA > A) ans += nA - A;
	if(nB > B) ans += nB - B;
	printf("%lld\n", ans);

	return 0;
}

