#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 20;

int gcd(int a, int b) { return !b ? a : gcd(b, a % b); }

int lcm(int a, int b) { return a / gcd(a, b) * b; }

int n;
int m[maxn], r[maxn];
bool vis[730000];

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", m + i);
	for(int i = 1; i <= n; i++) scanf("%d", r + i);
	int LCM = 1;
	for(int i = 1; i <= n; i++)
		LCM = lcm(LCM, m[i]);

	for(int i = 1; i <= n; i++) {
		int g = LCM / m[i];
		for(int j = r[i]; j < LCM; j += m[i])
			vis[j] = true;
	}

	int cnt = 0;
	for(int i = 0; i < LCM; i++) if(vis[i]) cnt++;
	printf("%.10f\n", (double)cnt / LCM);

	return 0;
}
