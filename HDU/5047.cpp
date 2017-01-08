#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long LL;

const LL MOD = 1000000000;

struct Big
{
	LL a[5];
	
	Big() { memset(a, 0, sizeof(a)); }
	
	Big(LL x) { memset(a, 0, sizeof(a)); a[1] = x / MOD; a[0] = x % MOD; }

	void read() {
		memset(a, 0, sizeof(a));
		LL x; scanf("%lld", &x);
		a[0] = x % MOD; a[1] = x / MOD;
	}

	Big operator + (const Big& t) const {
		Big ans;
		for(int i = 0; i < 5; i++) ans.a[i] = a[i];
		for(int i = 0; i < 5; i++) {
			ans.a[i] += t.a[i];
			int j = i;
			while(ans.a[j] >= MOD) {
				ans.a[j + 1] += ans.a[j] / MOD;
				ans.a[j++] %= MOD;
			}
		}
		return ans;
	}

	Big operator * (const Big& t) const {
		Big ans;
		for(int i = 0; i < 5; i++) {
			for(int j = 0; j < 5; j++) if(i + j < 5) {
				ans.a[i + j] += a[j] * t.a[i];
				int k = i + j;
				while(ans.a[k] >= MOD) {
					ans.a[k + 1] += ans.a[k] / MOD;
					ans.a[k++] %= MOD;
				}
			}
		}
		return ans;
	}

	Big operator - (const Big& t) const {
		Big ans;
		for(int i = 0; i < 5; i++) ans.a[i] = a[i];
		for(int i = 0; i < 5; i++) {
			int j = i + 1;
			if(ans.a[i] < t.a[i]) {
				while(!ans.a[j]) j++;
				ans.a[j]--;
				for(int k = j - 1; k > i; k--) ans.a[k] += MOD - 1;
				ans.a[i] += MOD;
			}
			ans.a[i] -= t.a[i];
		}
		return ans;
	}

	void output() {
		int i = 0;
		for(i = 4; i; i--) if(a[i]) break;
		printf("%lld", a[i]);
		for(int j = i - 1; j >= 0; j--) printf("%09lld", a[j]);
		printf("\n");
	}
};

int main()
{
	int T; scanf("%d", &T);
	for(int kase = 1; kase <= T; kase++) {
		printf("Case #%d: ", kase);
		Big x; x.read();
		Big ans(1);
		ans = ans + (Big(8) * x * x);
		ans = ans - (Big(7) * x);
		ans.output();
	}

	return 0;
}
