#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

const double eps = 1e-8;

int dcmp(double x) {
	if(fabs(x) < eps) return 0;
	return x < 0 ? -1 : 1;
}

struct Point
{
	double x, y, z;
	Point(double x=0, double y=0, double z=0): x(x), y(y), z(z) {}

	bool read() { return (scanf("%lf%lf%lf", &x, &y, &z) == 3); }
};

Point operator + (const Point& A, const Point& B) {
	return Point(A.x+B.x, A.y+B.y, A.z+B.z);
}

Point operator - (const Point& A, const Point& B) {
	return Point(A.x-B.x, A.y-B.y, A.z-B.z);
}

Point operator / (const Point& A, double p) {
	return Point(A.x/p, A.y/p, A.z/p);
}

Point operator * (const Point& A, double p) {
	return Point(A.x*p, A.y*p, A.z*p);
}

Point Cross(const Point& A, const Point& B) {
	return Point(A.y*B.z-A.z*B.y, A.z*B.x-A.x*B.z, A.x*B.y-A.y*B.x);
}

double Dot(const Point& A, const Point& B) {
	return A.x*B.x+A.y*B.y+A.z*B.z;
}

double Length(const Point& A) {
	return sqrt(Dot(A, A));
}

double Area(const Point& A, const Point& B, const Point& C) {
	return fabs(Length(Cross(B-A, C-A)));
}

char no[] = "O O O O";

int main()
{
	Point p[4];
	while(p[0].read()) {
		for(int i = 1; i < 4; i++) p[i].read();
		Point n = Cross(p[1]-p[0], p[2]-p[0]);
		if(fabs(Length(n)) == 0) {
			puts(no);
			continue;
		}

		n = n / Length(n);
		double h = fabs(Dot(n, p[3]-p[0]));
		if(fabs(h) == 0) {
			puts(no);
			continue;
		}
		
		double area[4], a[4], s = 0;
		for(int i = 0; i < 4; i++) {
			area[i] = Area(p[i], p[(i+1)%4], p[(i+2)%4]);
			s += area[i];
		}
		double r = area[0] * h / s;
		Point I;
		for(int i = 0; i < 4; i++) {
			I = I + (p[i] * (area[(i+1)%4] / s));
		}

		printf("%.4f %.4f %.4f %.4f\n", I.x, I.y, I.z, r);
	}

	return 0;
}
