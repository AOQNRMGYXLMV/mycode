#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

struct Node
{
	int p, id;
	Node(int p, int id): p(p), id(id) {}
	bool operator < (const Node& t) const {
		return p < t.p || (p == t.p && id > t.id);
	}
};

int main()
{


	return 0;
}
