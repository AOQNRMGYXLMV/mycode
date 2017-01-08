#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
	int n; scanf("%d", &n);
	for(int A = 0; A <= n; A += 1234567) {
		for(int B = 0; A + B <= n; B += 123456) {
			if(((n - A - B) % 1234) == 0) {
				printf("YES\n");
				return 0;
			}
		}
	}

	printf("NO\n");

	return 0;
}
