#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <set>
#include <vector>
#include <iostream>
#include <string>
using namespace std;
#define REP(i, a, b) for(int i = a; i < b; i++)
#define PER(i, a, b) for(int i = b - 1; i >= a; i--)
#define SZ(a) ((int)a.size())
#define MP make_pair
#define PB push_back
#define EB emplace_back
#define ALL(a) a.begin(), a.end()
typedef long long LL;
typedef pair<int, int> PII;

const int maxn = 1000000 + 10;
const LL MOD = 1000000007LL;
const LL inv_2 = 500000004LL;

void add(LL& a, LL b) { a += b; if(a >= MOD) a -= MOD; }

LL mul(LL a, LL b) { return a * b % MOD; }

char s[maxn];

int main() {
	scanf("%s", s);
	LL cnt = 0, ans = 0;
	/*for(int i = 0; s[i]; i++) {
		if(s[i] == 'a') cnt++;
		else add(ans, mul(mul(cnt, cnt + 1), inv_2));
	}*/
	int l = strlen(s);
	PER(i, 0, l) {
		if(s[i] == 'b') add(cnt, 1LL);
		else {
			add(ans, cnt);
			cnt = mul(cnt, 2LL);
		}
	}

	printf("%lld\n", ans);

	return 0;
}


