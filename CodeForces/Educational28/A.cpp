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

const int maxn = 100;

int n, a[maxn];

int main() {
	scanf("%d", &n);
	REP(i, 0, n) scanf("%d", a + i);
	int del = 0;
	REP(i, 0, n - 1) if(a[i] == 1 && a[i+1] == 0) del++;
	printf("%d\n", n - del);

	return 0;
}


