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

const double PI = acos(-1) ;
int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
//	freopen("angle2.in","r",stdin);
//	freopen("angle2.out","w",stdout);
	int t;
	while(cin>>t && t){
		double arr[t][4] ;
		for(int i=0 ; i<t ; i++){
			for(int j=0 ; j<4 ; j++) cin>>arr[i][j] ;
		}
		vector <int> vec;
//		vector <int> :: iterator it ;
		for(int i=0 ; i<t ; i++){
			Segment s(Point(arr[i][0], arr[i][1]), Point(arr[i][2], arr[i][3]));
			for(int j=0 ; j<vec.size() ; j++){
				int k=vec[j] ;
				Segment s1(Point(arr[k][0], arr[k][1]), Point(arr[k][2], arr[k][3]));
				if(inter(s,s1)){
					vec.erase(vec.begin()+j) ;
					j-- ;
				}
			}
			vec.push_back(i) ;
		}
		cout<<"Top sticks:" ;
		for(int i=0 ; i<vec.size() ; i++){
			cout<<" "<<vec[i]+1 ;
			if(i==vec.size()-1) cout<<"." ;
			else cout<<',' ;
		}
		cout<<endl ;
	}
	return 0 ;
}
