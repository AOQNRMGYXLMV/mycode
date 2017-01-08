#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#define MP make_pair
#define F first
#define S second
using namespace std;

typedef pair<int, int> PII;
const int maxn = 1000 + 10;

int dir(int x, int y) {
	if(!x) {
		if(y > 0) return 0;
		else return 2;
	} else {
		if(x > 0) return 1;
		else return 3;
	}
}

int n;
PII a[maxn];
int b[maxn];

int main()
{
	scanf("%d", &n);

	if(n == 4) { printf("0\n"); return 0; }

	for(int i = 0; i <= n; i++)
		scanf("%d%d", &a[i].F, &a[i].S);
	for(int i = 1; i <= n; i++)
		b[i] = dir(a[i].F-a[i-1].F, a[i].S-a[i-1].S);
	b[n + 1] = b[1];
	
	int cnt = 0;
	bool right = true;
	for(int i = 1; i <= n; i++)
		cnt += ((b[i + 1] - b[i]) + 4) % 4;

	if(cnt != (n - 2) * 2) right = false;

	int ans = 0;
	if(right) {
		for(int i = 1; i <= n; i++)
			if((b[i+1]+1)%4 == b[i]) ans++;
	} else {
		for(int i = 1; i <= n; i++)
			if((b[i]+1)%4 == b[i+1]) ans++;
	}

	printf("%d\n", ans);

	return 0;
}
