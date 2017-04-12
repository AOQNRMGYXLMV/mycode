#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
    int a, b, c, d;
    scanf("%d%d%d%d", &a, &b, &c, &d);
    int p = b;
    for(int i = 0; i < 1000000; i++, p += a) {
        if(p >= d && (p - d) % c == 0) {
            printf("%d\n", p);
            return 0;
        }
    }

    puts("-1");

    return 0;
}
