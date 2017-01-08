#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

bool leaf(int n) {
	if(n % 400 == 0) return true;
	if((n % 100 != 0) && (n % 4 == 0)) return true;
	return false;
}

int main()
{
	int y; scanf("%d", &y);

	bool leafy = leaf(y);
	int mod = 0;
	for(;;) {
		if(leaf(y)) mod = (mod + 2) % 7;
		else mod = (mod + 1) % 7;
		y++;
		if(!mod && leaf(y) == leafy) {
			printf("%d\n", y);
			return 0;
		}
	}

	return 0;
}
