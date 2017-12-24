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

bool can[30];
bool cur[30];

char s[maxn];

int main() {
	int n; scanf("%d", &n);
	int left = 26;
	REP(i, 0, 26) can[i] = true;
	int ans = 0, h;
	REP(i, 1, n + 1) {
		char op[10];
		scanf("%s %s", op, s);
		if(left > 1) {
			memset(cur, false, sizeof(cur));
			for(int i = 0; s[i]; i++) cur[s[i]-'a'] = true;
			if(op[0] == '!') {
				REP(i, 0, 26) if(!cur[i]) {
					if(can[i]) {
						left--;
						can[i] = false;
					}
				}
			} else if(op[0] == '.') {
				REP(i, 0, 26) if(cur[i]) {
					if(can[i]) {
						left--;
						can[i] = false;
					}
				}
			} else {
				if(can[s[0]-'a']) {
					left--;
					can[s[0]-'a'] = false;
				}
			}
		} else {
			if(op[0] == '!' || (i < n && op[0] == '?'))
				ans++;
		}
		
	}

	printf("%d\n", ans);

	return 0;
}

