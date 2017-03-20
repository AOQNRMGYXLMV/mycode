#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <vector>
using namespace std;

const int maxn = 60;

string generate(int x) {
	string ans = "";
	ans += 'A' + x / 26;
	ans += 'a' + (x % 26);
	return ans;
}

char s[10];
bool a[maxn];
int ans[maxn], sum[maxn];

int main()
{
	int n, k; scanf("%d%d", &n, &k);
	for(int i = k; i <= n; i++) {
		scanf("%s", s);
		a[i] = (s[0] == 'Y');
	}

	int tot = k * (k + 1) / 2;
	for(int i = 1; i < k; i++) {
		ans[i] = i;
		sum[i] = sum[i - 1] + ans[i];
	}

	for(int i = k; i <= n; i++) {
		if(a[i]) {
			ans[i] = tot - (sum[i - 1] - sum[i - k]);
		} else {
			ans[i] = ans[i - k + 1];
		}
		sum[i] = sum[i - 1] + ans[i];
	}

	for(int i = 1; i <= n; i++)
		cout << generate(ans[i]) << " ";
	cout << endl;

	return 0;
}
