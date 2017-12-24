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
	int v1, v2, v3, vm;
	scanf("%d%d%d%d", &v1, &v2, &v3, &vm);
	if(vm>v3*2 || v3>vm*2 || vm>=v2) {
		printf("-1\n");
		return 0;
	}
	printf("%d\n%d\n%d\n", v1*2, v2*2, max(v3, vm));

	return 0;
}

