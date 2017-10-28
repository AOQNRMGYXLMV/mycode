#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
#define MP make_pair
#define PB push_back
#define REP(i, a, b) for(int i = a; i < b; i++)
#define PER(i, a, b) for(int i = b - 1; i >= a; i--)

const int maxn = 400000 + 10;

int n;
char s[maxn], t[maxn];
int cnt[70];

int id(char c) {
	if('A' <= c && c <= 'Z') return c - 'A';
	if('a' <= c && c <= 'z') return c - 'a' + 26;
	return c - '0' + 52;
}

int main() {
	scanf("%d%s", &n, s);
	REP(i, 0, n) cnt[id(s[i])]++;
	int single = 0;
	REP(i, 0, 62) if(cnt[i] & 1) single++;
	int pair = n - single;
	for(int k = 1; k <= n; k++) if(n % k == 0) {
		int l = n / k;
		if(l & 1) {
			
		} else {
			if(single) continue;
			t[l] = 0;

		}
	}

	return 0;
}
