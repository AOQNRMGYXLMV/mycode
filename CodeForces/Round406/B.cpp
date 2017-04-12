#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

const int maxn = 10000;

set<int> S;

int main()
{
    int n, m; scanf("%d%d", &n, &m);
    while(m--) {
        S.clear();
        int k; scanf("%d", &k);
        bool ok = true;
        while(k--) {
            int x; scanf("%d", &x);
            if(S.count(-x)) { ok = false; }
            S.insert(x);
        }
        if(ok == true) { puts("YES"); return 0; }
    }

    puts("NO");

    return 0;
}
