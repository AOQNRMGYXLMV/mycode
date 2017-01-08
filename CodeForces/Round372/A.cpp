#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
	int n, c; scanf("%d%d", &n, &c);
	int last, tot;
	bool first = true;
	while(n--) {
		int t; scanf("%d", &t);
		if(first) {
			tot = 1;
			first = false;
		} else {
			if(t - last > c) tot = 1;
			else tot++;
		}
		last = t;
	}
	

	printf("%d\n", tot);

	return 0;
}