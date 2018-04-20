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

int main() {
	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);
	if(a > b) swap(a, b);
	int ans = a;
	b -= a;
	if(c <= b) ans += c;
	else { ans += b; ans += (c - b) / 2; }
	printf("%d\n", ans << 1);

	return 0;
}



