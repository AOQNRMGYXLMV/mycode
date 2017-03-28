#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;
#define REP(i, a, b) for(int i = a; i < b; i++)
#define SZ(a) ((int)a.size())
#define MP make_pair
#define ALL(a) a.begin(), a.end()
typedef long long LL;
typedef pair<int, int> PII;

const int maxn = ;

map<int, int> Map;

bool cmp(const PII& A, const PII& B) {
    return A.second < B.second || (A.second == B.second && A.first < B.first);
}

vector<PII> x;

int main() {
    int n; scanf("%d", &n);
    while(n--) {
        int x; scanf("%d", &x);
        Map[x]++;
    }

    for(PII t : Map) x.push_back(t);
    sort(ALL(x), cmp);
    
    for(int i = 0; i < SZ(x); i++) {
        for(int j = i; j + 1 < SZ(x) && x[j + 1].second == x[i].second; j++);
        if(j == i) { printf("%d\n", x[i].first); return 0; }
        i = j;
    }

    return 0;
}
