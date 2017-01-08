#include <cstdio>
#include <cstring>
#include <algorithm>
#include <utility>
#include <set>
#include <vector>
using namespace std;

typedef pair<int, int> PII;

multiset<int> S;
vector<PII> event, ans;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int n; scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        int y, l, r; scanf("%d%d%d", &y, &l, &r);
        event.push_back(make_pair(l, y));
        event.push_back(make_pair(r, -y));
    }
    
    sort(event.begin(), event.end());
    
    S.insert(0);
    int hmax = 0;
    for(int i = 0, j; i < n * 2; i = j) {
        for(j = i; j < n * 2 && event[i].first == event[j].first; j++) {
            if(event[j].second > 0) S.insert(event[j].second);
            else S.erase(S.lower_bound(-event[j].second));
        }
        if((*S.rbegin()) != hmax) {
            ans.push_back(make_pair(event[i].first, hmax));
            ans.push_back(make_pair(event[i].first, hmax = (*S.rbegin())));
        }
    }
    
    printf("%d\n", ans.size());
    for(int i = 0; i < ans.size(); i++) {
        printf("%d %d\n", ans[i].first, ans[i].second);
    }
    
    return 0;
}
