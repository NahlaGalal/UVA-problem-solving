#include <bits/stdc++.h>

using namespace std;

struct Point{
    double x, y;
    Point(double x, double y):x(x), y(y){}
    Point():x(0), y(0){}
    Point& operator=(const Point& o){
    	x = o.x;
    	y = o.y;
    	return *this;
    }
    Point& operator+=(const Point& o){
		x += o.x;
		y += o.y;
		return *this;
	}
};

Point operator-(const Point &a){
    return Point(-a.x, -a.y);
}
Point operator+(const Point &a, const Point &b){
    return Point(a.x+b.x, a.y+b.y);
}
Point operator-(const Point &a, const Point &b){
    return Point(a.x-b.x, a.y-b.y);
}
double operator^(const Point &a, const Point &b){
    return a.x*b.y - a.y*b.x;
}
double operator*(const Point &a, const Point &b){
    return a.x*b.x + a.y*b.y;
}
double abs(const Point &p){
    return p*p;
}
double norm(const Point &p){
    return sqrt(p*p);
}

struct Segment{
    Point a, ab;
    Segment(const Point &a, const Point &b):a(a), ab(b-a){}
    Segment():a(), ab(){}

    Point b () const {
        return a + ab;
    }
};

bool dist(const Segment& r, const Point& p){
        if((p - r.a) * (r.ab) <= 0)return 0;
        if((p - r.b()) * (-r.ab) <= 0)return 0;
        return 1;
}
bool inter(const Segment& s1, const Segment &s2){
    if((s1.ab ^ s2.ab) == 0)return 0; // parallel
    double t1 = ((s2.a - s1.a) ^ s2.ab) / (s1.ab ^ s2.ab);
    double t2 = ((s1.a - s2.a) ^ s1.ab) / (s2.ab ^ s1.ab);
    if(t1 < 0 || t1 > 1 || t2 < 0 || t2 > 1)return 0;// does not intersect
    return 1;
}
bool onsegment(const Segment& r, const Point& p){
    return ((p - r.a) ^ r.ab) == 0 && ((p - r.a) * (p - r.b())) <= 0;
}

void swap(double &a, double &b){
	double temp=a ;
	a=b ;
	b=temp ;
}

const double PI = acos(-1) ;
int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
//	freopen("angle2.in","r",stdin);
//	freopen("angle2.out","w",stdout);
	int t;
	cin>>t ;
	while(t--){
		double xs,ys,xe,ye,xl,yt,xr,yb ;
		cin>>xs>>ys>>xe>>ye>>xl>>yt>>xr>>yb ;
		if(xl>xr) swap(xr,xl) ;
		if(yb>yt) swap(yt,yb) ;
		Point p1(xs,ys), p2(xe,ye), pr1(xl,yb), pr2(xl,yt), pr3(xr,yb), pr4(xr,yt) ;
		Segment l(p1,p2), l1(pr1,pr2), l2(pr3,pr4), l3(pr1,pr3), l4(pr2,pr4);
		if( inter(l,l1) || inter(l,l2) || inter(l,l3) || inter(l,l4)) cout<<"T\n" ;
		else if(onsegment(l1,p1) || onsegment(l1,p2) || onsegment(l2,p1) || onsegment(l2,p2)) cout<<"T\n" ;
		else if(onsegment(l3,p1) || onsegment(l3,p2) || onsegment(l4,p1) || onsegment(l4,p2)) cout<<"T\n" ;
		else if(xs>=xl && xs<=xr && xe>=xl && xe<=xr && ys>=yb && ys<=yt && ye>=yb && ye<=yt) cout<<"T\n" ;
		else cout<<"F\n" ;
	}
	return 0 ;
}
