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
Point operator*(const double factor, const Point & p){
    return Point(factor * p.x, factor * p.y);
}
Point operator*(const Point & p, const double factor){
    return Point(factor * p.x, factor * p.y);
}

struct Segment{
    Point a, ab;
    Segment(const Point &a, const Point &b):a(a), ab(b-a){}
    Segment():a(), ab(){}

    Point b () const {
        return a + ab;
    }
};

void proj(const Segment& l, const Point& p, Point &res){
    res = l.a;
    res += l.ab *  ( ((p - l.a) * l.ab) / abs(l.ab) );
}
double dist(const Segment& r, const Point& p){
	if((p - r.a) * (r.ab) <= 0)return norm(p - r.a);        // If the point out of the segment
	if((p - r.b()) * (-r.ab) <= 0)return norm(p - r.b());   // If the point out of the segment on the other side

	return abs(((p-r.a)^r.ab)/norm(r.ab));                  // If the point inside the segment
}
void coord(const Segment& r, const Point& p, Point &res){
	if((p - r.a) * (r.ab) < 0) res=r.a;        // If the point out of the segment
	else if((p - r.b()) * (-r.ab) < 0) res=r.b();   // If the point out of the segment on the other side
	else{
		res = r.a;
		res += r.ab *  ( ((p - r.a) * r.ab) / abs(r.ab) );
	}
}

const double PI = acos(-1) ;
int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
//	freopen("angle2.in","r",stdin);
//	freopen("angle2.out","w",stdout);
	double xm,ym,n ;
	while(cin>>xm>>ym>>n){
		Point p(xm,ym) ;
		double mn=1000000000,mnx,mny ;
		double x,y,a,b ;
		cin>>a>>b ;
		for(int i=1 ; i<=n ; i++){
			cin>>x>>y ;
			Point p1(x,y), p2(a,b) ;
			Segment l(p2,p1) ;
			Point temp ;
			coord(l, p, temp) ;
			if(dist(l,p)<mn){
				mnx=temp.x ;
				mny=temp.y ;
				mn=dist(l,p) ;
			}
			a=x ;
			b=y ;
		}
		cout<<fixed<<setprecision(4)<<mnx<<endl<<mny<<endl ;
//		printf("%.4lf\n%.4lf\n",mnx,mny) ;
	}
	return 0 ;
}
