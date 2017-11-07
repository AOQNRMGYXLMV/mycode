#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
#define REP(i, a, b) for(int i = a; i < b; i++)
#define PER(i, a, b) for(int i = b - 1; i >= a; i--)
#define ALL(x) x.begin(), x.end()

char s[100];

int main() {
	scanf("%s", s);
	int n = strlen(s);
	int i = 0;
	for(i = 0; i < n; i++) if(s[i] == '1') break;
	if(i >= n) { printf("no\n"); return 0; }
	int cnt = 0;
	for(i++; i < n; i++) if(s[i] == '0') cnt++;
	if(cnt >= 6) printf("yes\n");
	else printf("no\n");

	return 0;
}

