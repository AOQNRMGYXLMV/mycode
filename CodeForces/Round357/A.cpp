#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
	char name[20];
	int n, before, after;
	scanf("%d", &n);
	while(n--) {
		scanf("%s %d %d", name, &before, &after);
		if(before >= 2400 && before < after) {
			printf("YES\n");
			return 0;
		}
	}

	printf("NO\n");

	return 0;
}
