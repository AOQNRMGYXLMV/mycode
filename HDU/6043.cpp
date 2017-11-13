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
	LL n, k;
	int _ = 1;
	while(scanf("%I64d%I64d", &n, &k) == 2) {
		printf("Case #%d: ", _++);
		if(k <= n - 1) printf("%I64d\n", k);
		else {
			k -= n;
			k %= (n - 1) * 2;
			if(k < n - 1) {
				if(!k) printf("%I64d\n", n);
				else printf("%I64d\n", k);
			} else {
				k -= n - 1;
				if(!k) printf("%I64d\n", n - 1);
				else printf("%I64d\n", k);
			}
		}
	}
	
	return 0;
}


