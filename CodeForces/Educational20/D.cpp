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

int k;
int b[maxn], cnt;

bool check(int x) {
	int a = 1, r = x, p;
	for(p = 1; p < cnt && a; p++) {
		int d = b[p] - b[p - 1];
		if(d > x) return false;
		if(d <= r) r -= d;
		else {
			if(a == k) return false;
			r = x - d;
			a++;
		}
	}
	return true;
}

int main() {
	b[cnt++] = -1;
	scanf("%d", &k); getchar();
	int l = 0;
	for(char c; (c = getchar()) != EOF && c != '\n'; l++) {
		if(c == '-' || c == ' ') b[cnt++] = l;
	}
	b[cnt++] = l - 1;
	int L = 1, R = l;
	while(L < R) {
		int M = (L + R) / 2;
		if(!check(M)) L = M + 1;
		else R = M;
	}

	printf("%d\n", L);

	return 0;
}


