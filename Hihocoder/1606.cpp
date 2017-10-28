#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long LL;

int main() {
    LL n; scanf("%lld", &n);
    for(LL a = 2; a * a < n; a++) {
        LL b = a * a;
        LL x = (a * b) % n;
        LL y = (b * b) % n;
        if((x == 1 || x == a || x == b) && (y == 1 || y == a || y == b)) {
            printf("1 %lld %lld\n", a, b);
        }
    }
    printf("-1\n");
    
    return 0;
}
