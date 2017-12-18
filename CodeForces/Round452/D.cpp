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

int n;
char x[20];

int calc(int sum) {
	if(sum & 1) {
		sum--;
		return max(0, min(n, sum) - sum / 2);
	} else {
		return max(0, min(n, sum-1) - sum / 2);
	}
}

int main() {
	scanf("%d", &n);
	if(n < 5) { printf("%d\n", n * (n - 1) / 2); return 0; }
	sprintf(x, "%d", (n << 1) - 1);
	int l = strlen(x);
	
	bool check = true;
	REP(i, 0, l) if(x[i] != '9') {
		check = false;
		break;
	}
	if(check) { printf("1\n"); return 0; }

	int p = 1;
	REP(i, 1, l) p *= 10;
	int ans = 0;
	REP(i, 0, x[0] - '0') {
		ans += calc(p * (i + 1) - 1);
		//printf("calc(%d) = %d\n", p*(i+1)-1, calc(p*(i+1)-1));
	}

	if(p*(x[0]-'0'+1)-1 == n*2-1) ans += 1;

	printf("%d\n", ans);

	return 0;
}

