#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 60;

int n;
int a[maxn], b[maxn];

int main()
{
	freopen("in.txt", "r", stdin);
	int Q; scanf("%d", &Q);
	while(Q--) {
		scanf("%d", &n);
		int ans = 0;
		for(int i = 1; i <= n; i++) {
			double f; scanf("%lf%d", &f, &b[i]);
			a[i] = ((int)(f * 2)) % 10;
			if(!a[i]) ans = max(ans, b[i]);
		}
		
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++)
				if(i != j && (((a[i] + a[j]) % 10) == 0))
					ans = max(ans, b[i] + b[j]);

		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++) if(j != i)
				for(int k = 1; k <= n; k++) if(i != k && j != k)
					if(((a[i]+a[j]+a[k])%10)==0)
						ans = max(ans, b[i] + b[j] + b[k]);

		printf("%d\n", ans);
	}

	return 0;
}
