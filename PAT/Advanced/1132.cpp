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

char s[20];

int main() {
  int kase; scanf("%d", &kase);
  while(kase--) {
    LL n; scanf("%lld", &n);
    sprintf(s, "%lld", n);
    int l = strlen(s) / 2;
    LL p = 1;
    REP(i, 0, l) p *= 10;
    LL A = n / p, B = n % p;
	if(!A || !B) printf("No\n");
	else if(n % (A * B) == 0) printf("Yes\n");
    else printf("No\n");
  }

  return 0;
}
