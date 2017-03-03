#include <cstdio>
#include <vector>
using namespace std;

int MOD;

int pow_mod(int a, int p) {
	int ans = 1;
	while(p) {
		if(p & 1) ans = ans * a % MOD;
		a = a * a % MOD;
		p >>= 1;
	}
	return ans;
}

int inverse(int a) { return pow_mod(a, MOD - 2); }

int mul(int a, int b) { return a * b % MOD; }

void add(int& a, int b) { a += b; if(a >= MOD) a -= MOD; }

vector<int> A, B;

void read(vector<int>& A) {
	A.clear();
	int degree; scanf("%d", &degree);
	for(int i = 0; i <= degree; i++) {
		int x; scanf("%d", &x);
		A.push_back(x);
	}
}

vector<int> gcd(vector<int> A, vector<int> B) {
	if(!B.size()) return A;
	int d = A.size() - B.size();
	vector<int> C;
	for(int i = 0; i <= d; i++) {
		int t = mul(A[i], inverse(B[0]));
		for(int j = 0; j < B.size(); j++)
			add(A[i+j], MOD - mul(B[j], t));
	}
	int p;
	for(p = 0; p < A.size() && A[p] == 0; p++);
	for(; p < A.size(); p++) C.push_back(A[p]);
	return gcd(B, C);
}

int main()
{
	int kase = 1;
	while(scanf("%d", &MOD) == 1 && MOD) {
		read(A); read(B);
		vector<int> C = gcd(A, B);
		printf("Case %d: %d", kase++, (int)C.size() - 1);
		int t = C[0];
		C[0] = 1;
		t = inverse(t);
		for(int i = 1; i < C.size(); i++) C[i] = mul(C[i], t);
		for(int x : C) printf(" %d", x);
		printf("\n");
	}

	return 0;
}
