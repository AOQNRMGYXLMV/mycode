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

const int maxn = 20;

char s[maxn];

int main() {
	scanf("%s", s);
	int n = strlen(s);
	int c = 0;
	REP(i, 0, n / 2) {
		if(s[i] != s[n - i - 1]) c++;
	}

	if(c > 1) printf("NO\n");
	else if(c == 1) printf("YES\n");
	else if(c == 0 && (n & 1)) printf("YES\n");
	else printf("NO\n");

	return 0;
}


